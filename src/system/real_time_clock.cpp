/*!****************************************************************************
 * @file    real_time_clock.cpp
 * @brief   Implementation of Real Time Clock (RTC) DS3231 module handler.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/system/real_time_clock.h"

#include "include/config.h"
#include "framework/common_defs.h"

namespace System {

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
}

//-----------------------------------------------------------------------------
auto RealTimeClock::GetTime() -> Utilities::DateTime
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

    return Utilities::DateTime(hours, minutes, seconds);
}

//-----------------------------------------------------------------------------
bool RealTimeClock::SetTime(const Utilities::DateTime& dateTime)
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

} // namespace System
