/*!****************************************************************************
 * @file    real_time_clock.cpp
 * @brief   Implementation of Real Time Clock (RTC) DS3231 module handler.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/services/real_time_clock.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "esp_sntp.h"

namespace Services {

RealTimeClock* RealTimeClock::_instance = nullptr;

//-----------------------------------------------------------------------------
RealTimeClock* RealTimeClock::GetInstance()
{
    return _instance;
}

//-----------------------------------------------------------------------------
void RealTimeClock::Init()
{
    CORE_INFO("Initializing RealTimeClock...");

    if (_instance != nullptr) 
    {
        CORE_ERROR("RealTimeClock already initialized!");
        return;
    }

    _instance = new RealTimeClock(
          Config::I2C_SDA_PIN
        , Config::I2C_SCL_PIN
        , Config::RTC_I2C_ADDRESS
    );
    _instance->_isTimeSynced = false;
}

//-----------------------------------------------------------------------------
auto RealTimeClock::GetTime() -> Utils::DateTime
{
    uint8_t startReg = 0x00;
    uint8_t buffer[3] = {0};

    if (!_i2c.WriteRead(&startReg, 1, buffer, 3)) 
    {
        CORE_ERROR("Failed to read time");
        return false;
    }

    uint8_t seconds = BcdToDec(buffer[0]);
    uint8_t minutes = BcdToDec(buffer[1]);
    uint8_t hours   = BcdToDec(buffer[2]);

    return Utils::DateTime(hours, minutes, seconds);
}

//-----------------------------------------------------------------------------
bool RealTimeClock::SetTime(const Utils::DateTime& dateTime)
{
    uint8_t hours   = dateTime.GetHour();
    uint8_t minutes = dateTime.GetMinute();
    uint8_t seconds = dateTime.GetSecond();


    uint8_t buffer[4];
    buffer[0] = 0x00; // start register
    buffer[1] = DecToBcd(seconds);
    buffer[2] = DecToBcd(minutes);
    buffer[3] = DecToBcd(hours);

    if (!_i2c.Write(buffer, sizeof(buffer))) 
    {
        CORE_ERROR("Failed to set time");
        return false;
    }

    CORE_INFO("Set RTC time to %02u:%02u:%02u", hours, minutes, seconds);
    return true;
}

//-----------------------------------------------------------------------------
void RealTimeClock::InitTimeSync() const
{
    // TODO - This should be set by the user
    setenv("TZ", "ART3", 1);
    tzset();

    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    esp_sntp_setservername(0, "pool.ntp.org");

    sntp_set_time_sync_notification_cb(&RealTimeClock::TimeSyncCallback);

    esp_sntp_init();
}

//----static-------------------------------------------------------------------
void RealTimeClock::TimeSyncCallback(struct ::timeval *tv)
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

    if (_instance)
    {
        _instance->SetTime(
            Utils::DateTime(
                  static_cast<uint8_t>(timeinfo.tm_hour)
                , static_cast<uint8_t>(timeinfo.tm_min)
                , static_cast<uint8_t>(timeinfo.tm_sec)
            )
        );

        _instance->_isTimeSynced = true;
    }
    else
    {
        CORE_ERROR("RTC instance not initialized; cannot set time");
    }
}

//----private------------------------------------------------------------------
uint8_t RealTimeClock::DecToBcd(uint8_t val)
{
    return ((val / 10 * 16) + (val % 10));
}

//----private------------------------------------------------------------------
uint8_t RealTimeClock::BcdToDec(uint8_t val)
{
    return ((val / 16 * 10) + (val % 16));
}

//----private------------------------------------------------------------------
RealTimeClock::RealTimeClock(PinName sda, PinName scl, uint8_t address)
    : _i2c(sda, scl, address)
{}

} // namespace Services
