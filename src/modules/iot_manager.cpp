/*!****************************************************************************
 * @file    iot_manager.cpp
 * @brief   Implementation of the IotManager class
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/modules/iot_manager.h"

#include "esp_sntp.h"
#include "framework/common_defs.h"
#include "src/connectivity/wifi_com.h"
#include "src/services/real_time_clock.h"
#include "src/utils/date_time.h"

namespace Modules {

IotManager* IotManager::_instance = nullptr;

//----static-------------------------------------------------------------------
IotManager* IotManager::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void IotManager::Init()
{
    CORE_INFO("Initializing IoTManager...");

        if (_instance != nullptr)
    {
        CORE_ERROR("IoTManager already initialized!");
        return;
    }

    _instance = new IotManager();
    _instance->_isTimeSynced = false;

    // Initialize WiFi communication
    Connectivity::WiFiCom::Init();
}

//-----------------------------------------------------------------------------
void IotManager::Update()
{
    // Update WiFi state machine
    Connectivity::WiFiCom::GetInstance()->Update();

    if (Connectivity::WiFiCom::GetInstance()->IsConnected() && !_isTimeSynced)
    {
        static bool configMade = false;
        if (!configMade)
        {
            setenv("TZ", "ART3", 1);
            tzset();

            esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
            esp_sntp_setservername(0, "pool.ntp.org");

            sntp_set_time_sync_notification_cb(&IotManager::TimeSyncCallback);

            esp_sntp_init();

            configMade = true;
        }


        time_t now;
        struct tm timeinfo;
        time(&now);
        localtime_r(&now, &timeinfo);

        if (timeinfo.tm_year + 1900 > 2020)
        {
            _isTimeSynced = true;
            CORE_INFO("System time synchronized via NTP");
        }
    }
}

//----static-------------------------------------------------------------------
void IotManager::TimeSyncCallback(struct ::timeval *tv)
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

} // namespace Modules