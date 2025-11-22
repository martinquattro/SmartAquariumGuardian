/*!****************************************************************************
 * @file    network_controller.cpp
 * @brief   Implementation of the NetworkController class
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/managers/network_controller.h"

#include "esp_sntp.h"
#include "framework/common_defs.h"
#include "include/config.h"
#include "include/network_config.h"
#include "src/connectivity/mqtt_client.h"
#include "src/connectivity/wifi_com.h"
#include "src/core/guardian_proxy.h"
#include "src/core/guardian_public_interfaces.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"
#include "src/utils/date_time.h"
#include "src/utils/json_parser.h"

namespace Managers {

NetworkController* NetworkController::_instance = nullptr;

//----static-------------------------------------------------------------------
NetworkController* NetworkController::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void NetworkController::Init()
{
    CORE_INFO("Initializing NetworkController...");

    if (_instance != nullptr)
    {
        CORE_ERROR("NetworkController already initialized!");
        return;
    }

    _instance = new NetworkController();
    _instance->_isTimeSynced = false;
    _instance->_state = State::INIT;
    _instance->_telemetrySendDelay.Start(Config::TELEMETRY_SEND_INTERVAL_MS);
    _instance->RegisterRpcHandlers();

    Connectivity::WiFiCom::Init();
    Connectivity::MqttClient::Init();
}

//-----------------------------------------------------------------------------
void NetworkController::Update()
{
    Connectivity::WiFiCom::GetInstance()->Update();
    Connectivity::MqttClient::GetInstance()->Update();

    switch (_instance->_state)
    {
        case State::INIT:
        {
            ChangeState(State::START_WIFI);
        }
        break;
        
        case State::START_WIFI:
        {
            Connectivity::WiFiCom::GetInstance()->Start();
            ChangeState(State::WAITING_FOR_WIFI);
        }
        break;

        case State::WAITING_FOR_WIFI:
        {
            if (IsWiFiConnected())
            {
                ChangeState(State::START_TIME_SYNC);
            }
        }
        break;

        case State::START_TIME_SYNC:
        {
            TimeSyncInit();
            ChangeState(State::WAITING_FOR_TIME_SYNC);
        }
        break;

        case State::WAITING_FOR_TIME_SYNC:
        {
            if (_isTimeSynced)
            {
                ChangeState(State::START_MQTT_CLIENT);
            }
        }
        break;

        case State::START_MQTT_CLIENT:
        {
            Connectivity::MqttClient::GetInstance()->Start();
            ChangeState(State::WAITING_FOR_MQTT_CLIENT);
        }
        break;

        case State::WAITING_FOR_MQTT_CLIENT:
        {
            if (IsMqttClientConnected())
            {
                ChangeState(State::SETUP_MQTT_CLIENT);
            }
        }
        break;

        case State::SETUP_MQTT_CLIENT:
        {
            Connectivity::MqttClient::GetInstance()->Subscribe(
                RPC_REQUEST_TOPIC
            );

            // Connectivity::MqttClient::GetInstance()->Subscribe(
            //     ATTRIBUTES_TOPIC
            // );

            Connectivity::MqttClient::GetInstance()->SetMessageCallback(
                [](const std::string& topic, const std::string& payload)
                {
                    _instance->DispatchMqttMessage(topic, payload);
                }
            );

            ChangeState(State::IDLE);
        }
        break;

        case State::IDLE:
        {
            if (IsWiFiConnected() && IsMqttClientConnected())
            {
                if (_telemetrySendDelay.HasFinished())
                {
                    ChangeState(State::SEND_TELEMETRY);
                }
            }
            else
            {
                CORE_WARNING("NetworkController lost connection");
                ChangeState(State::ERROR);
            }
        }
        break;

        case State::SEND_TELEMETRY:
        {
            SendTelemtry();
            ChangeState(State::IDLE);
        }
        break;

        case State::ERROR:
        {
            // Error state - do nothing
            return;
        }
        break;

        default:
        {
            CORE_ERROR("NetworkController in unknown state");
            ChangeState(State::ERROR);
        }
        break;
    }
}

//-----------------------------------------------------------------------------
bool NetworkController::IsWiFiConnected() const
{
    return Connectivity::WiFiCom::GetInstance()->IsConnected();
}

//-----------------------------------------------------------------------------
bool NetworkController::IsMqttClientConnected() const
{
    return Connectivity::MqttClient::GetInstance()->IsConnected();
}

//----private------------------------------------------------------------------
void NetworkController::RegisterRpcHandlers()
{
    _rpcHandlers[Handlers::SetTempLimitsHandler::NAME] = 
        std::make_unique<Handlers::SetTempLimitsHandler>();
}

//----private------------------------------------------------------------------
void NetworkController::ChangeState(const State newState)
{
    _state = newState;
}

//----private------------------------------------------------------------------
void NetworkController::DispatchMqttMessage(const std::string& topic, const std::string& payload)
{
    CORE_INFO("Received MQTT message on topic: %s\n payload: %s", topic.c_str(), payload.c_str());

    if (topic.find("rpc/request/") != std::string::npos)
    {
        DispatchRpcRequest(topic, payload);
    }
    else if (topic.find("v1/devices/me/attributes") != std::string::npos)
    {
        DispatchAttributesRequest(payload);
    }
    else
    {
        CORE_WARNING("MQTT message on unknown topic: %s", topic.c_str());
    }
}

//----private------------------------------------------------------------------
void NetworkController::DispatchRpcRequest(const std::string& topic, const std::string& payload)
{
    Utils::JsonPayloadParser parser(payload);
    if (!parser.IsValid())
    {
        CORE_ERROR("Invalid JSON in RPC payload: %s", parser.GetError().c_str());
        return;
    }

    auto method = parser.GetMethod();
    if (!method.has_value())
    {
        CORE_ERROR("RPC payload missing 'method' field");
        return;
    }

    auto it = _rpcHandlers.find(method.value());
    if (it != _rpcHandlers.end())
    {
        // Call the registered handler
        const Result result = it->second->Handle(payload);

        // Extract request ID from topic and send response
        const int requestId = ExtractRequestId(topic);
        const std::string responseTopic = std::string(RPC_RESPONSE_TOPIC) + std::to_string(requestId);

        // Prepare the response JSON
        Json responseJson;

        responseJson[NetworkConfig::Key::RESULT] =
            result.success ? NetworkConfig::Value::RESULT_SUCCESS
                           : NetworkConfig::Value::RESULT_ERROR;
        
        if (result.responseMessage.has_value()) 
        {
            responseJson[NetworkConfig::Key::RESPONSE_MSG] = result.responseMessage.value();
        }
   
        // Serialize and publish the response
        const bool publishSuccess = Connectivity::MqttClient::GetInstance()->Publish(
            responseTopic,
            responseJson.dump()
        );

        if (!publishSuccess)
        {
            CORE_ERROR("Failed to publish RPC response to topic: %s", responseTopic.c_str());
        }
        else
        {
            CORE_INFO("Published RPC response to topic: %s with payload: %s", 
                responseTopic.c_str()
              , responseJson.dump().c_str()
            );
        }
    }
    else
    {
        CORE_WARNING("Unknown RPC method: %s", method.value().c_str());
    }
}

//----private------------------------------------------------------------------
void NetworkController::DispatchAttributesRequest(const std::string& payload)
{
    Json json;
    if (!Json::accept(payload))
    {
        CORE_ERROR("Invalid JSON received in RPC payload: %s", payload.c_str());
        return;
    }

    json = Json::parse(payload);
}

//----private------------------------------------------------------------------
void NetworkController::SendTelemtry()
{
    CORE_INFO("Sending telemetry data...");

    const float temperature = Drivers::TemperatureSensor::GetInstance()->GetLastReading();
    const int tds = Drivers::TdsSensor::GetInstance()->GetLastReading();

    std::string payload;
    payload += "{";
    payload += "\"temperature\":" + std::to_string(temperature);
    payload += ",\"tds\":" + std::to_string(tds);
    payload += "}";

    const bool success = Connectivity::MqttClient::GetInstance()->Publish(
        TELEMETRY_TOPIC
      , payload
    );

    if (success)
    {
        CORE_INFO("Telemetry data sent successfully");
    }
    else
    {
        CORE_ERROR("Failed to send telemetry data");
    }
}

//----private------------------------------------------------------------------
void NetworkController::TimeSyncInit()
{
    // TODO - This should be set by the user
    setenv("TZ", "ART3", 1);
    tzset();

    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    esp_sntp_setservername(0, "pool.ntp.org");

    sntp_set_time_sync_notification_cb(&NetworkController::TimeSyncCallback);

    esp_sntp_init();
}

//----static-------------------------------------------------------------------
void NetworkController::TimeSyncCallback(struct ::timeval *tv)
{
    CORE_INFO("Time synchronized from NTP server");

    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    CORE_INFO("NTP Time: %02d:%02d:%02d",
                timeinfo.tm_hour
              , timeinfo.tm_min
              , timeinfo.tm_sec
    );

    Core::GuardianProxy::GetInstance()->SetDateTime(
        Utils::DateTime(
              static_cast<uint8_t>(timeinfo.tm_hour)
            , static_cast<uint8_t>(timeinfo.tm_min)
            , static_cast<uint8_t>(timeinfo.tm_sec)
        )
    );

    _instance->_isTimeSynced = true;
}

//----private------------------------------------------------------------------
int NetworkController::ExtractRequestId(const std::string& url)
{
    size_t lastSlashPos = url.find_last_of('/');

    if (lastSlashPos != std::string::npos && lastSlashPos < url.length() - 1) 
    {
        std::string idStr = url.substr(lastSlashPos + 1);
        return std::stoi(idStr);
    }
    else
    {
        CORE_ERROR("Failed to extract ID from URL: %s", url.c_str());
        return ::INVALID;
    }
}

} // namespace Managers