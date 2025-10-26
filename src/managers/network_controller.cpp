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
#include "src/connectivity/mqtt_client.h"
#include "src/connectivity/wifi_com.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"
#include "src/services/real_time_clock.h"
#include "src/utils/date_time.h"

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
    _instance->_telemetrySendDelay.Start(Config::TELEMTRY_SEND_INTERVAL_MS);

    Connectivity::WiFiCom::Init();
    Connectivity::MqttClient::Init();
}

//-----------------------------------------------------------------------------
void NetworkController::Update()
{
    Connectivity::WiFiCom::GetInstance()->Update();

    switch (_instance->_state)
    {
        case State::INIT:
        {
            ChangeState(State::WAITING_FOR_WIFI);
        }
        break;

        case State::WAITING_FOR_WIFI:
        {
            if (!Connectivity::WiFiCom::GetInstance()->IsConnected())
            {
                ChangeState(State::IDLE);
            }
        }
        break;

        case State::IDLE:
        {
            if (Connectivity::WiFiCom::GetInstance()->IsConnected())
            {
                // Time sync check
                if (!_isTimeSynced)
                {
                    ChangeState(State::INIT_TIME_SYNC);
                }

                // MQTT Client update
                Connectivity::MqttClient::GetInstance()->Update();

                if (Connectivity::MqttClient::GetInstance()->IsConnected())
                {
                    if (_telemetrySendDelay.HasFinished())
                    {
                        ChangeState(State::SEND_TELEMETRY);
                    }
                }
            }
            else
            {
                // TODO - Try Reconnect;
            }
        }
        break;

        case State::SEND_TELEMETRY:
        {
            SendTelemtry();
            ChangeState(State::IDLE);
        }
        break;

        case State::INIT_TIME_SYNC:
        {
            TimeSyncInit();
            ChangeState(State::WAITING_FOR_TIME_SYNC);
        }
        break;

        case State::WAITING_FOR_TIME_SYNC:
        {
            if (_isTimeSynced)
            {
                ChangeState(State::IDLE);
            }
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
void NetworkController::ChangeState(const State newState)
{
    _state = newState;
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

    Services::RealTimeClock::GetInstance()->SetTime(
        Utils::DateTime(
              static_cast<uint8_t>(timeinfo.tm_hour)
            , static_cast<uint8_t>(timeinfo.tm_min)
            , static_cast<uint8_t>(timeinfo.tm_sec)
        )
    );

    _instance->_isTimeSynced = true;
}

} // namespace Managers