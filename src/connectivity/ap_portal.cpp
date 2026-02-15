/*!****************************************************************************
 * @file    ap_portal.cpp
 * @brief   Access Point (AP) Portal for WiFi credentials configuration.
 *          Provides a web interface for users to enter WiFi credentials.
 *          Uses state machine for credential management.
 * @author  Quattrone Martin
 * @date    Feb 2026
 *******************************************************************************/

#include "connectivity/ap_portal.h"

#include "connectivity/ap_portal_html.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "framework/common_defs.h"
#include "include/config.h"
#include "lib/nlohmann_json/json.hpp"
#include "lwip/ip_addr.h"
#include "lwip/ip4_addr.h"
#include <cstring>
#include <memory>

namespace Connectivity {

//----private------------------------------------------------------------------
bool APPortal::OnInit()
{
    _httpServer = nullptr;
    _state = State::IDLE;
    _mqttPort = 1883;

    return true;
}

//----private------------------------------------------------------------------
void APPortal::OnUpdate()
{
    switch (_state)
    {
        case State::IDLE:
        {
            // nothing to do
        }
        break;

        case State::INIT:
        {
            _state = _Start();
        }
        break;
        
        case State::LISTENING_WIFI_CONFIG:
        {
            // waiting for HTTP handler to set WIFI_CREDENTIALS_RECEIVED
        }
        break;

        case State::WIFI_CREDENTIALS_RECEIVED:
        {
            // Credentials ready for NetworkController to process
            // Waiting for NetworkController to call ResetState() after processing
        }
        break;

        case State::LISTENING_MQTT_CONFIG:
        {
            // waiting for HTTP handler to set MQTT_CREDENTIALS_RECEIVED
        }
        break;

        case State::MQTT_CREDENTIALS_RECEIVED:
        {
            // MQTT credentials ready for NetworkController to process
            // Waiting for NetworkController to call ResetState() after processing
        }
        break;

        case State::STOP:
        {
            _state = _Stop();
        }
        break;

        case State::ERROR:
        {
            // Error state - could implement retry logic or require manual reset
            CORE_ERROR("APPortal is in ERROR state");
        }
        break;
    }
}

//-----------------------------------------------------------------------------
void APPortal::Start()
{
    if (_state == State::IDLE || _state == State::ERROR)
    {
        _state = State::INIT;
    }
}

//-----------------------------------------------------------------------------
void APPortal::Stop()
{
    if (_state == State::IDLE || _state == State::ERROR)
    {
        return;
    }

    _state = State::STOP;
}

//-----------------------------------------------------------------------------
void APPortal::ResetState()
{
    _state = State::IDLE;
}

//----private------------------------------------------------------------------
auto APPortal::_Start() -> State
{
    // Enable AP mode
    EnableAPMode();
    
    // Setup HTTP server
    SetupHttpServer();
    
    return State::LISTENING_WIFI_CONFIG;
}

//----private------------------------------------------------------------------
auto APPortal::_Stop() -> State
{
    StopHttpServer();
    DisableAPMode();
    
    _state = State::IDLE;
    _configuredSsid = "";
    _configuredPassword = "";
    
    CORE_INFO("AP Portal stopped");
    return State::IDLE;
}

//-----------------------------------------------------------------------------
Result APPortal::GetWifiCredentials(std::string& ssid, std::string& password) const
{
    if (_state != State::WIFI_CREDENTIALS_RECEIVED)
    {
        return Result(false, "WiFi credentials not ready");
    }
    
    ssid = _configuredSsid;
    password = _configuredPassword;
    return Result(true, "Credentials retrieved");
}

//-----------------------------------------------------------------------------
Result APPortal::GetMqttCredentials(std::string& broker, 
                                    uint16_t& port, 
                                    std::string& username, 
                                    std::string& password) const
{
    if (_state != State::MQTT_CREDENTIALS_RECEIVED)
    {
        return Result(false, "MQTT credentials not ready");
    }
    
    broker = _mqttBroker;
    port = _mqttPort;
    username = _mqttUsername;
    password = _mqttPassword;
    return Result(true, "Credentials retrieved");
}

//----private------------------------------------------------------------------
void APPortal::EnableAPMode()
{
    if (_netif == nullptr)
    {
        _netif = esp_netif_create_default_wifi_ap();
    }

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_APSTA));

    wifi_config_t wifi_config = {};
    std::strncpy(reinterpret_cast<char*>(wifi_config.ap.ssid), AP_SSID, sizeof(wifi_config.ap.ssid) - 1);
    std::strncpy(reinterpret_cast<char*>(wifi_config.ap.password), AP_PASSWORD, sizeof(wifi_config.ap.password) - 1);
    
    wifi_config.ap.ssid_len = std::strlen(AP_SSID);
    wifi_config.ap.channel = 1;
    wifi_config.ap.max_connection = 4;
    wifi_config.ap.authmode = WIFI_AUTH_WPA_WPA2_PSK;

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_config));

    // Configure IP address for AP
    esp_netif_ip_info_t ipInfo;
    IP4_ADDR(&ipInfo.ip, 192, 168, 4, 1);
    IP4_ADDR(&ipInfo.gw, 192, 168, 4, 1);
    IP4_ADDR(&ipInfo.netmask, 255, 255, 255, 0);

    esp_netif_dhcps_stop(_netif);
    ESP_ERROR_CHECK(esp_netif_set_ip_info(_netif, &ipInfo));
    esp_netif_dhcps_start(_netif);

    ESP_ERROR_CHECK(esp_wifi_start());

    CORE_INFO("AP mode enabled: SSID=%s, IP=%s", AP_SSID, AP_IP);
}

//----private------------------------------------------------------------------
void APPortal::DisableAPMode()
{
    esp_wifi_stop();
    esp_wifi_deinit();

    CORE_INFO("AP mode disabled");
}

//----private------------------------------------------------------------------
void APPortal::SetupHttpServer()
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = HTTP_PORT;
    config.max_uri_handlers = 6;
    config.stack_size = 10240;

    if (httpd_start(&_httpServer, &config) != ESP_OK)
    {
        CORE_ERROR("APPortal: Failed to start HTTP server");
        _state = State::ERROR;
        return;
    }

    // Register URI handlers
    httpd_uri_t uri_get_root = {
        .uri = "/",
        .method = HTTP_GET,
        .handler = HandleGetRoot,
        .user_ctx = this
    };
    httpd_register_uri_handler(_httpServer, &uri_get_root);

    httpd_uri_t uri_get_networks = {
        .uri = "/api/wifi-networks",
        .method = HTTP_GET,
        .handler = HandleGetWifiNetworks,
        .user_ctx = this
    };
    httpd_register_uri_handler(_httpServer, &uri_get_networks);

    httpd_uri_t uri_post_credentials = {
        .uri = "/api/credentials",
        .method = HTTP_POST,
        .handler = HandlePostCredentials,
        .user_ctx = this
    };
    httpd_register_uri_handler(_httpServer, &uri_post_credentials);

    httpd_uri_t uri_post_mqtt = {
        .uri = "/api/mqtt-credentials",
        .method = HTTP_POST,
        .handler = HandlePostMqttCredentials,
        .user_ctx = this
    };
    httpd_register_uri_handler(_httpServer, &uri_post_mqtt);

    httpd_uri_t uri_get_status = {
        .uri = "/api/status",
        .method = HTTP_GET,
        .handler = HandleGetStatus,
        .user_ctx = this
    };
    httpd_register_uri_handler(_httpServer, &uri_get_status);

    CORE_INFO("HTTP server started on port %d", HTTP_PORT);
}

//----private------------------------------------------------------------------
void APPortal::StopHttpServer()
{
    if (_httpServer)
    {
        httpd_stop(_httpServer);
        _httpServer = nullptr;
        CORE_INFO("HTTP server stopped");
    }
}

//----private------------------------------------------------------------------
esp_err_t APPortal::HandleGetRoot(httpd_req_t* req)
{
    httpd_resp_set_type(req, "text/html; charset=utf-8");
    httpd_resp_send(req, HTML_PORTAL, std::strlen(HTML_PORTAL));
    return ESP_OK;
}

//----private------------------------------------------------------------------
esp_err_t APPortal::HandlePostCredentials(httpd_req_t* req)
{
    APPortal* instance = Connectivity::APPortal::GetInstance();
    
    // Read request body
    char buf[512] = {0};
    int total_len = req->content_len;
    int cur_len = 0;

    while (cur_len < total_len)
    {
        int recv_len = httpd_req_recv(req, buf + cur_len, total_len - cur_len);
        if (recv_len <= 0)
        {
            httpd_resp_send_500(req);
            return ESP_FAIL;
        }
        cur_len += recv_len;
    }
    buf[cur_len] = '\0';

    // Parse JSON using nlohmann::json
    Json response;
    {
        Json j = Json::parse(std::string(buf), nullptr, false);
        
        if (j.is_discarded())
        {
            response["success"] = false;
            response["message"] = "Invalid JSON";
            std::string json_str = response.dump();
            httpd_resp_set_type(req, "application/json");
            httpd_resp_send(req, json_str.c_str(), json_str.length());
            return ESP_OK;
        }

        std::string ssid, password;
        
        // Extract SSID
        if (j.contains("ssid") && j["ssid"].is_string())
        {
            ssid = j["ssid"].get<std::string>();
        }

        // Extract password
        if (j.contains("password") && j["password"].is_string())
        {
            password = j["password"].get<std::string>();
        }

        if (ssid.empty() || password.empty())
        {
            response["success"] = false;
            response["message"] = "Invalid credentials";
            std::string json_str = response.dump();
            httpd_resp_set_type(req, "application/json");
            httpd_resp_send(req, json_str.c_str(), json_str.length());
            return ESP_OK;
        }

        // Store credentials
        instance->_configuredSsid = ssid;
        instance->_configuredPassword = password;
        instance->_state = State::WIFI_CREDENTIALS_RECEIVED;

        CORE_INFO("APPortal: WiFi credentials received - SSID: %s", ssid.c_str());

        response["success"] = true;
        response["message"] = "Credentials saved. Connecting...";
    }

    std::string json_str = response.dump();
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json_str.c_str(), json_str.length());

    return ESP_OK;
}

//----private------------------------------------------------------------------
esp_err_t APPortal::HandleGetWifiNetworks(httpd_req_t* req)
{
    // Perform WiFi scan
    esp_wifi_scan_start(nullptr, true);  // Blocking scan

    // Get scan results
    uint16_t apCount = 0;
    esp_wifi_scan_get_ap_num(&apCount);

    Json response;
    response["networks"] = Json::array();

    if (apCount > 0)
    {
        // Allocate memory for results
        wifi_ap_record_t* apRecords = new wifi_ap_record_t[apCount];
        esp_wifi_scan_get_ap_records(&apCount, apRecords);

        // Build JSON response
        for (uint16_t i = 0; i < apCount; i++)
        {
            Json network;
            
            // Convert SSID to string (null-terminated)
            std::string ssid(reinterpret_cast<const char*>(apRecords[i].ssid));
            
            network["ssid"] = ssid;
            network["rssi"] = apRecords[i].rssi;
            network["channel"] = apRecords[i].primary;
            
            response["networks"].push_back(network);
        }

        delete[] apRecords;
    }

    std::string json_str = response.dump();
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json_str.c_str(), json_str.length());

    return ESP_OK;
}

//----private------------------------------------------------------------------
esp_err_t APPortal::HandlePostMqttCredentials(httpd_req_t* req)
{
    APPortal* portal = static_cast<APPortal*>(req->user_ctx);
    
    // Read request body
    char buf[512] = {0};
    int total_len = req->content_len;
    int cur_len = 0;

    while (cur_len < total_len)
    {
        int recv_len = httpd_req_recv(req, buf + cur_len, total_len - cur_len);
        if (recv_len <= 0)
        {
            httpd_resp_send_500(req);
            return ESP_FAIL;
        }
        cur_len += recv_len;
    }
    buf[cur_len] = '\0';

    // Parse JSON using nlohmann::json
    Json response;
    
    {
        Json j = Json::parse(std::string(buf), nullptr, false);
        
        if (j.is_discarded())
        {
            response["success"] = false;
            response["message"] = "Invalid JSON";
            std::string json_str = response.dump();
            httpd_resp_set_type(req, "application/json");
            httpd_resp_send(req, json_str.c_str(), json_str.length());
            return ESP_OK;
        }

        std::string broker, username, password;
        uint16_t port = 1883;

        // Extract fields
        if (j.contains("broker") && j["broker"].is_string())
        {
            broker = j["broker"].get<std::string>();
        }

        if (j.contains("port") && j["port"].is_number())
        {
            port = j["port"].get<uint16_t>();
        }

        if (j.contains("username") && j["username"].is_string())
        {
            username = j["username"].get<std::string>();
        }

        if (j.contains("password") && j["password"].is_string())
        {
            password = j["password"].get<std::string>();
        }

        if (broker.empty())
        {
            response["success"] = false;
            response["message"] = "Broker address required";
            std::string json_str = response.dump();
            httpd_resp_set_type(req, "application/json");
            httpd_resp_send(req, json_str.c_str(), json_str.length());
            return ESP_OK;
        }

        // Store MQTT credentials
        portal->_mqttBroker = broker;
        portal->_mqttPort = port;
        portal->_mqttUsername = username;
        portal->_mqttPassword = password;
        portal->_state = State::MQTT_CREDENTIALS_RECEIVED;

        CORE_INFO("APPortal: MQTT settings received - Broker: %s:%d, User: %s", 
                  broker.c_str(), port, username.empty() ? "(none)" : username.c_str());

        response["success"] = true;
        response["message"] = "MQTT settings saved";
    }

    std::string json_str = response.dump();
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json_str.c_str(), json_str.length());

    return ESP_OK;
}

//----private------------------------------------------------------------------
esp_err_t APPortal::HandleGetStatus(httpd_req_t* req)
{
    Json response;

    response["connected"] = false;
    response["ssid"] = "Waiting for credentials";

    std::string json_str = response.dump();
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json_str.c_str(), json_str.length());

    return ESP_OK;
}

//----private------------------------------------------------------------------
APPortal::APPortal() 
    : _configuredSsid("")
    , _configuredPassword("")
    , _mqttBroker("")
    , _mqttPort(1883)
    , _mqttUsername("")
    , _mqttPassword("")
{
}

//----private------------------------------------------------------------------
APPortal::~APPortal()
{
    Stop();
}

} // namespace Connectivity