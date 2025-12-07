/*!****************************************************************************
 * @file    network_controller.cpp
 * @brief   Implementation of the NetworkController class
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/managers/network_controller.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/connectivity/mqtt_client.h"
#include "src/connectivity/wifi_com.h"
#include "src/core/guardian_public_interfaces.h"
#include "src/managers/comms/json_parser.h"
#include "src/managers/comms/network_config.h"
#include "src/managers/comms/telemetry_data.h"
#include "src/services/storage_service.h"

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
            Core::GuardianProxy::GetInstance()->InitTimeSync();
            ChangeState(State::WAITING_FOR_TIME_SYNC);
        }
        break;

        case State::WAITING_FOR_TIME_SYNC:
        {
            // TODO - add timeout and error handling
            if (Core::GuardianProxy::GetInstance()->IsTimeSynced())
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
    _rpcHandlers[Handlers::SetTempLimitsHandler::NAME]          = std::make_unique<Handlers::SetTempLimitsHandler>();
    _rpcHandlers[Handlers::AddFeedingScheduleHandler::NAME]     = std::make_unique<Handlers::AddFeedingScheduleHandler>();
    _rpcHandlers[Handlers::DeleteFeedingScheduleHandler::NAME]  = std::make_unique<Handlers::DeleteFeedingScheduleHandler>();
    _rpcHandlers[Handlers::FeedNowHandler::NAME]                = std::make_unique<Handlers::FeedNowHandler>();
    _rpcHandlers[Handlers::SetTimezoneHandler::NAME]            = std::make_unique<Handlers::SetTimezoneHandler>();
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

    // Get telemetry data
    Comms::TelemetryData telemetryData;
    const std::string payload = telemetryData.ToJsonString();

    // Publish telemetry data
    const bool success = Connectivity::MqttClient::GetInstance()->Publish(
        TELEMETRY_TOPIC
      , payload
    );

    if (success)
    {
        CORE_INFO("Telemetry data sent successfully");
        CORE_INFO("Payload sent: %s", payload.c_str());
    }
    else
    {
        CORE_ERROR("Failed to send telemetry data");
    }
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