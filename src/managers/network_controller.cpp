/*!****************************************************************************
 * @file    network_controller.cpp
 * @brief   Implementation of the NetworkController class
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/managers/network_controller.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/connectivity/ap_portal.h"
#include "src/connectivity/mqtt_client.h"
#include "src/connectivity/wifi_com.h"
#include "src/core/guardian_proxy.h"
#include "src/core/guardian_public_interfaces.h"

#include "src/managers/comms/cloud_payloads.h"
#include "src/managers/comms/json_parser.h"
#include "src/managers/comms/network_config.h"
#include "src/services/storage_service.h"

namespace Managers {

//----protected----------------------------------------------------------------
bool NetworkController::OnInit()
{
    _state = State::INIT;
    _telemetrySendDelay.Start(Config::TELEMETRY_SEND_INTERVAL_MS);

    RegisterRpcHandlers();

    _wifiCom = Connectivity::WiFiCom::GetInstance();
    _mqttClient = Connectivity::MqttClient::GetInstance();
    _apPortal = Connectivity::APPortal::GetInstance();

    bool success = _wifiCom->Init();
    success &= _mqttClient->Init();
    success &= _apPortal->Init();

    _wifiCom->SetCredentials(
        Core::GuardianProxy::GetInstance()->GetWifiSsidFromStorage(),
        Core::GuardianProxy::GetInstance()->GetWifiPasswordFromStorage()
    );

    return success;
}

//----protected----------------------------------------------------------------
void NetworkController::OnUpdate()
{
    _wifiCom->Update();
    _mqttClient->Update();
    _apPortal->Update();

    switch (_state)
    {
        case State::INIT:
        {
            ChangeState(State::PRE_START_WIFI, 500); // Start WiFi after short delay to allow system to stabilize
        }
        break;
        
        case State::PRE_START_WIFI:
        {
            if (_delayTimeout.HasFinished())
            {
                if (_apPortal->GetState() != Connectivity::APPortal::State::IDLE)
                {
                    CORE_WARNING("AP Portal is active, killing portal before starting WiFi connection");
                    _apPortal->Stop(); // Ensure portal is stopped before starting WiFi connection

                    ChangeState(State::PRE_START_WIFI, 1000);
                }
                else
                {
                    ChangeState(State::START_WIFI, 1000);

                    CORE_INFO("Starting WiFi connection");
                }
            }
        }
        break;

        case State::START_WIFI:
        {
            if (_delayTimeout.HasFinished())
            {
                if (_apPortal->GetState() != Connectivity::APPortal::State::IDLE)
                {
                    CORE_WARNING("NetworkController: AP Portal is active, cannot start WiFi connection");
                    ChangeState(State::PRE_START_WIFI, 1000);
                }
                else
                {
                    _wifiCom->Start();
                    ChangeState(State::WAITING_FOR_WIFI, WIFI_CONNECTION_TIMEOUT_MS);
                }
            }
        }
        break;

        case State::WAITING_FOR_WIFI:
        {
            if (IsWiFiConnected())
            {
                ChangeState(State::START_TIME_SYNC);
            }
            else if (_delayTimeout.HasFinished())
            {
                CORE_WARNING("WiFi connection timeout, starting AP Portal");

                ChangeState(State::PRE_START_ACCESS_POINT, 1000);
            }
        }
        break;

        case State::START_TIME_SYNC:
        {
            Core::GuardianProxy::GetInstance()->InitTimeSync();
            ChangeState(State::WAITING_FOR_TIME_SYNC, TIME_SYNC_TIMEOUT_MS);
        }
        break;

        case State::WAITING_FOR_TIME_SYNC:
        {
            if (Core::GuardianProxy::GetInstance()->IsTimeSynced())
            {
                ChangeState(State::START_MQTT_CLIENT);
            }
            else if (_delayTimeout.HasFinished())
            {
                CORE_WARNING("Time synchronization timeout, proceeding without time sync");
                ChangeState(State::START_MQTT_CLIENT);
            }
        }
        break;

        case State::START_MQTT_CLIENT:
        {
            _mqttClient->Start();
            ChangeState(State::WAITING_FOR_MQTT_CLIENT, MQTT_CLIENT_TIMEOUT_MS);
        }
        break;

        case State::WAITING_FOR_MQTT_CLIENT:
        {
            if (IsMqttClientConnected())
            {
                ChangeState(State::SETUP_MQTT_CLIENT);
            }
            else if (_delayTimeout.HasFinished())
            {
                CORE_WARNING("MQTT client connection timeout, proceeding without MQTT");
                ChangeState(State::IDLE);
            }
        }
        break;

        case State::SETUP_MQTT_CLIENT:
        {
            _mqttClient->Subscribe(
                RPC_REQUEST_TOPIC
            );

            _mqttClient->SetMessageCallback(
                [this](const std::string& topic, const std::string& payload)
                {
                    DispatchMqttMessage(topic, payload);
                }
            );

            const auto result = SendClientAttributes();
            if (!result.success)
            {
                CORE_ERROR("Failed to send client attributes: %s", result.responseMessage.value().c_str());
                ChangeState(State::ERROR);
            }

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
                CORE_WARNING("Lost connection");
                ChangeState(State::PRE_START_WIFI, 1000);
            }
        }
        break;

        case State::SEND_TELEMETRY:
        {
            SendTelemtry();
            ChangeState(State::IDLE);
        }
        break;

        case State::PRE_START_ACCESS_POINT:
        {
            if (_delayTimeout.HasFinished())
            {
                if (_mqttClient->IsConnected())
                {
                    CORE_WARNING("NetworkController: Still connected to MQTT broker, killing MQTT client before starting AP Portal");
                    _mqttClient->Stop();

                    ChangeState(State::PRE_START_ACCESS_POINT, 1000);
                }
                else if (_wifiCom->IsConnected() || _wifiCom->GetState() != Connectivity::WiFiCom::State::IDLE)
                {
                    CORE_WARNING("NetworkController: Still connected to WiFi, killing WiFi connection before starting AP Portal");
                    _wifiCom->Disconnect();

                    ChangeState(State::PRE_START_ACCESS_POINT, 1000);
                }
                else
                {
                    ChangeState(State::START_ACCESS_POINT, 500);
                }
            }
        }
        break;

        case State::START_ACCESS_POINT:
        {
            if (_delayTimeout.HasFinished())
            {
                if (_mqttClient->IsConnected())
                {
                    CORE_WARNING("NetworkController: Still connected to MQTT broker, killing MQTT client before starting AP Portal");
                    ChangeState(State::PRE_START_ACCESS_POINT, 1000); // Retry after short delay
                }
                if (_wifiCom->IsConnected()  || _wifiCom->GetState() != Connectivity::WiFiCom::State::IDLE)
                {
                    CORE_WARNING("NetworkController: Still connected to WiFi, cannot start AP Portal");
                    ChangeState(State::PRE_START_ACCESS_POINT, 1000); // Retry after short delay
                }
                else
                {
                    CORE_INFO("NetworkController: Starting AP Portal for WiFi configuration");
                    _apPortal->Start();
                    ChangeState(State::WAITING_FOR_ACCESS_POINT, 1000); // Check for credentials after short delay to allow portal to start
                }
            }
        }
        break;

        case State::WAITING_FOR_ACCESS_POINT:
        {
            // Check if WiFi credentials were received from portal
            if (_apPortal->GetState() == Connectivity::APPortal::State::WIFI_CREDENTIALS_RECEIVED)
            {
                std::string ssid, password;
                Result result = _apPortal->GetWifiCredentials(ssid, password);
                
                if (result.success && !ssid.empty() && !password.empty())
                {
                    CORE_INFO("NetworkController: New WiFi credentials received from portal - SSID: %s", 
                             ssid.c_str());
                    
                    // Apply new credentials
                    _wifiCom->SetCredentials(ssid, password);
                    
                    // Save to storage for persistence
                    Core::GuardianProxy::GetInstance()->SaveWifiCredentialsInStorage(ssid, password);
                                        
                    ChangeState(State::PRE_START_WIFI, 2000);
                }
                else
                {
                    CORE_WARNING("NetworkController: Invalid credentials from portal");
                    _apPortal->ResetState();
                }
            }
        }
        break;

        case State::ERROR:
        {
            CORE_ERROR("NetworkController is in ERROR state. Manual intervention required.");
            ChangeState(State::IDLE);
        }
        break;

        case State::STOP:
        {
            if (_delayTimeout.HasFinished())
            {
                if (_mqttClient->IsConnected())
                {
                    CORE_WARNING("NetworkController: Still connected to MQTT broker, killing MQTT client");
                    _mqttClient->Stop();

                    ChangeState(State::STOP, 1000);
                }
                else if (_wifiCom->IsConnected() || _wifiCom->GetState() != Connectivity::WiFiCom::State::IDLE)
                {
                    CORE_WARNING("NetworkController: Still connected to WiFi, killing WiFi connection.");
                    _wifiCom->Disconnect();

                    ChangeState(State::STOP, 1000);
                }
                else if (_apPortal->GetState() != Connectivity::APPortal::State::IDLE)
                {
                    CORE_WARNING("NetworkController: Still connected to AP Portal, killing AP Portal.");
                    _apPortal->Stop();

                    ChangeState(State::STOP, 1000);
                }
                else
                {
                    CORE_INFO("NetworkController: All connections stopped successfully");
                    ChangeState(State::NO_CONNECTIONS);
                }
            }
        }
        break;

        case State::NO_CONNECTIONS:
        {
            // Do nothing, just stay idle with no connections until battery mode is exited
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

//----protected----------------------------------------------------------------
void NetworkController::OnBatteryModeEnter()
{
    if (_state != State::STOP)
    {
        ChangeState(State::STOP, 5000); // Stop all network activity when entering battery mode.
    }
}

//----protected----------------------------------------------------------------
void NetworkController::OnBatteryModeExit()
{
    if (_state == State::NO_CONNECTIONS)
    {
        ChangeState(State::INIT); 
    }
}

//-----------------------------------------------------------------------------
void NetworkController::ActivateApMode()
{
    CORE_INFO("Activating AP mode for configuration");
    
    ChangeState(State::PRE_START_ACCESS_POINT, 1000); // Start AP portal after short delay
}

//-----------------------------------------------------------------------------
bool NetworkController::IsWiFiConnected() const
{
    return _wifiCom->IsConnected();
}

//-----------------------------------------------------------------------------
bool NetworkController::IsMqttClientConnected() const
{
    return _mqttClient->IsConnected();
}

//-----------------------------------------------------------------------------
bool NetworkController::IsApPortalActive() const
{
    return (_apPortal->GetState() != Connectivity::APPortal::State::IDLE);
}

//-----------------------------------------------------------------------------
Result NetworkController::SyncDevice()
{
    return SendClientAttributes();
}

//----private------------------------------------------------------------------
void NetworkController::RegisterRpcHandlers()
{
    _rpcHandlers[Handlers::SetTempLimitsHandler::NAME]          = std::make_unique<Handlers::SetTempLimitsHandler>();
    _rpcHandlers[Handlers::AddFeedingScheduleHandler::NAME]     = std::make_unique<Handlers::AddFeedingScheduleHandler>();
    _rpcHandlers[Handlers::DeleteFeedingScheduleHandler::NAME]  = std::make_unique<Handlers::DeleteFeedingScheduleHandler>();
    _rpcHandlers[Handlers::FeedNowHandler::NAME]                = std::make_unique<Handlers::FeedNowHandler>();
    _rpcHandlers[Handlers::SetTimezoneHandler::NAME]            = std::make_unique<Handlers::SetTimezoneHandler>();
    _rpcHandlers[Handlers::FactoryResetHandler::NAME]           = std::make_unique<Handlers::FactoryResetHandler>();
    _rpcHandlers[Handlers::SyncDeviceHandler::NAME]             = std::make_unique<Handlers::SyncDeviceHandler>();
}
    
//----private------------------------------------------------------------------
void NetworkController::ChangeState(const State newState, const int delayMs)
{
    _state = newState;
    _delayTimeout.Start(delayMs);
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
        const bool publishSuccess = _mqttClient->Publish(
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

        if (result.success && _mqttClient->IsConnected())
        {
            const std::string& methodName = method.value();
            if (methodName == Handlers::SetTempLimitsHandler::NAME ||
                methodName == Handlers::AddFeedingScheduleHandler::NAME ||
                methodName == Handlers::DeleteFeedingScheduleHandler::NAME ||
                methodName == Handlers::SetTimezoneHandler::NAME ||
                methodName == Handlers::FactoryResetHandler::NAME)
            {
                const auto result = SendClientAttributes();
                if (!result.success)
                {
                    CORE_ERROR("Failed to send client attributes: %s", result.responseMessage.value().c_str());
                }
            }
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
    Comms::TelemetryPayload telemetryPayload;
    const std::string payload = telemetryPayload.ToJsonString();

    // Publish telemetry data
    const bool success = _mqttClient->Publish(
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
Result NetworkController::SendClientAttributes()
{
    if (!_mqttClient->IsConnected())
    {
        CORE_WARNING("Cannot send client attributes: MQTT not connected");
        return Result::Error("MQTT not connected");
    }

    CORE_INFO("Sending client attributes to ThingsBoard...");

    Comms::ClientAttributesPayload attributesPayload;
    const std::string payload = attributesPayload.ToJsonString();
    CORE_INFO("Client attributes to send: %s", payload.c_str());

    const bool success = _mqttClient->Publish(ATTRIBUTES_TOPIC, payload);

    if (success)
    {
        CORE_INFO("Client attributes sent successfully");
        return Result::Success("Client attributes sent successfully");
    }
    else
    {
        CORE_ERROR("Failed to send client attributes");
        return Result::Error("Failed to send client attributes");
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