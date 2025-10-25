/*!****************************************************************************
 * @file    wifi_com.cpp
 * @brief   WiFi connectivity wrapper (non-blocking state-machine).
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "connectivity/wifi_com.h"
#include "include/config.h"

#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_sntp.h"

namespace Connectivity {

WiFiCom* WiFiCom::_instance = nullptr;

//----static-------------------------------------------------------------------
WiFiCom* WiFiCom::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void WiFiCom::Init()
{
    CORE_INFO("Initializing WiFiCom...");

    if (_instance != nullptr)
    {
        CORE_ERROR("WiFiCom already initialized!");
        return;
    }

    _instance = new WiFiCom();
    _instance->_state = State::INIT;
    _instance->_ssid = "Cuchitril 2.4GHz";
    _instance->_password = "Defensa5232022";
}

//-----------------------------------------------------------------------------
void WiFiCom::Update()
{
    switch (_state)
    {
        case State::INIT:
        {
            _state = _Start();
        }
        break;

        case State::CONNECTING:
        {
            // waiting for event handler to set CONNECTED
        }
        break;

        case State::CONNECTED:
        {
            // connected; nothing mandatory here
        }
        break;

        case State::DISCONNECTING:
        {
            _Stop();
        }
        break;

        case State::ERROR:
        {
        }
        break;

        default:
        {
            CORE_ERROR("WiFiCom in unknown state!");
            _state = State::ERROR;
        }
        break;
    }
}

//-----------------------------------------------------------------------------
bool WiFiCom::IsConnected() const
{
    return _connected_flag.load();
}

//-----------------------------------------------------------------------------
void WiFiCom::Disconnect()
{
    if (_state == State::CONNECTED || _state == State::CONNECTING)
    {
        _state = State::DISCONNECTING;
        // actual stop will be done in Update() or destructor
    }
}

//----private------------------------------------------------------------------
auto WiFiCom::_Start() -> State
{
    CORE_INFO("Starting wifi stack");

    // Initialize NVS (required for WiFi)
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize TCP/IP and default event loop
    static bool s_started = false;
    if (!s_started)
    {
        ESP_ERROR_CHECK(esp_netif_init());
        ESP_ERROR_CHECK(esp_event_loop_create_default());
        s_started = true;
    }

    // create default wifi station
    esp_netif_t* netif = esp_netif_create_default_wifi_sta();
    _netif = netif;

    // Initialize WiFi with default config
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_err_t err = esp_wifi_init(&cfg);
    if (err != ESP_OK)
    {
        CORE_ERROR("WiFi init failed: %d", err);
        return State::ERROR;
    }

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &WiFiCom::EventHandler, nullptr, nullptr));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &WiFiCom::EventHandler, nullptr, nullptr));

    wifi_config_t wifi_cfg = {};
    strncpy(reinterpret_cast<char*>(wifi_cfg.sta.ssid), _ssid.c_str(), sizeof(wifi_cfg.sta.ssid)-1);
    strncpy(reinterpret_cast<char*>(wifi_cfg.sta.password), _password.c_str(), sizeof(wifi_cfg.sta.password)-1);
    wifi_cfg.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
    wifi_cfg.sta.pmf_cfg.capable = true;
    wifi_cfg.sta.pmf_cfg.required = false;

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_cfg));

    esp_err_t result = esp_wifi_start();
    if (result == ESP_OK) 
    {
        CORE_INFO("esp_wifi_start OK -> connecting...");
        esp_wifi_connect(); // non-blocking

        return State::CONNECTING;
    }
    else 
    {
        CORE_ERROR("esp_wifi_start failed: %d", result);
        return State::ERROR;
    }
}

//----private------------------------------------------------------------------
void WiFiCom::_Stop()
{
    CORE_INFO("stopping wifi stack");

    esp_wifi_disconnect();
    esp_wifi_stop();
    esp_wifi_deinit();

    _state = State::INIT;
    _got_ip = false;
    _connected_flag = false;
}

//----private------------------------------------------------------------------
void WiFiCom::EventHandler(
      void* arg
    , esp_event_base_t event_base
    , int32_t event_id
    , void* event_data)
{
    // This static handler is used for both WIFI_EVENT and IP_EVENT
    if (event_base == WIFI_EVENT)
    {
        switch (event_id)
        {
            case WIFI_EVENT_STA_START:
            {
                CORE_INFO("WIFI_EVENT_STA_START");
            }
            break;

            case WIFI_EVENT_STA_DISCONNECTED:
            {
                CORE_WARNING("WIFI_EVENT_STA_DISCONNECTED");

                if (WiFiCom::_instance)
                {
                    WiFiCom::_instance->_connected_flag = false;
                    WiFiCom::_instance->_got_ip = false;
                    WiFiCom::_instance->_state = State::CONNECTING;
                    // attempt reconnect (non-blocking)
                    esp_wifi_connect();
                }
            }
            break;

            default:
            {
                // Do nothing
            }
            break;
        }
    }
    else if (event_base == IP_EVENT)
    {
        if (event_id == IP_EVENT_STA_GOT_IP)
        {
            ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;

            char ip_str[16] = {0};
            esp_ip4addr_ntoa(&event->ip_info.ip, ip_str, sizeof(ip_str));
            CORE_INFO("Got IP: %s", ip_str);
            
            if (WiFiCom::_instance) 
            {
                WiFiCom::_instance->_got_ip = true;
                WiFiCom::_instance->_connected_flag = true;
                WiFiCom::_instance->_state = State::CONNECTED;
            }
        }
    }
}

//----private------------------------------------------------------------------
WiFiCom::WiFiCom()
    : _got_ip(false)
    , _connected_flag(false)
    , _netif(nullptr)
{}

//----private------------------------------------------------------------------
WiFiCom::~WiFiCom()
{
    _Stop();
}

} // namespace Connectivity