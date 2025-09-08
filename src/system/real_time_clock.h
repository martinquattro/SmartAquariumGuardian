/*!****************************************************************************
 * @file    real_time_clock.h
 * @brief   Real Time Clock (RTC) DS3231 module handler.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef REAL_TIME_CLOCK_H
#define REAL_TIME_CLOCK_H

#include "framework/drivers/i2c.h"
#include <string>

namespace System {

class RealTimeClock
{
    public:

        /**
         * @brief Get the singleton instance of RealTimeClock.
         * @return RealTimeClock* Pointer to the RealTimeClock instance.
         */
        static RealTimeClock* GetInstance();

        /**
         * @brief Initialize the RTC driver.
         */
        static void Init();

        /**
         * @brief Get the current time from the RTC.
         * @param timeStr    String to store the time in "HH:MM:SS" format.
         * @return true if success, false otherwise.
        */
        bool GetTime(std::string& timeStr);

        /**
         * @brief Set the current time on the RTC.
         * @param hours     Hours (0-23).
         * @param minutes   Minutes (0-59).
         * @param seconds   Seconds (0-59).
         * @return true if success, false otherwise.
        */
        bool SetTime(uint8_t hours, uint8_t minutes, uint8_t seconds);

    private:

        RealTimeClock(PinName sda, PinName scl, uint8_t address);
        ~RealTimeClock() = default;
        RealTimeClock(const RealTimeClock&) = delete;
        RealTimeClock& operator=(const RealTimeClock&) = delete;

        //---------------------------------------------

        /**
         * @brief Convert decimal to BCD format.
         * @param val   Decimal value (0-99).
         */
        uint8_t DecToBcd(uint8_t val);

        /**
         * @brief Convert BCD to decimal format.
         * @param val   BCD value (0-99).
         */
        uint8_t BcdToDec(uint8_t val);

        //---------------------------------------------

        static RealTimeClock* _instance;
        I2C _i2c;
};

} // namespace System

#endif // REAL_TIME_CLOCK_H