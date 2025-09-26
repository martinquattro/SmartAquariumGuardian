/*!****************************************************************************
 * @file    real_time_clock.h
 * @brief   Real Time Clock (RTC) DS3231 module handler.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef REAL_TIME_CLOCK_H
#define REAL_TIME_CLOCK_H

#include "framework/drivers/i2c.h"
#include "src/utils/date_time.h"
#include <string>

namespace Services {

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
         * @return DateTime object with the current time.
        */
        auto GetTime() -> Utils::DateTime;

        /**
         * @brief Set the current time on the RTC.
         * @param dateTime   DateTime object with the time to set.
         * @return true if success, false otherwise.
        */
        bool SetTime(const Utils::DateTime& dateTime);

    private:

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

        RealTimeClock(PinName sda, PinName scl, uint8_t address);
        ~RealTimeClock() = default;
        RealTimeClock(const RealTimeClock&) = delete;
        RealTimeClock& operator=(const RealTimeClock&) = delete;

        //---------------------------------------------

        static RealTimeClock* _instance;
        I2C _i2c;
};

} // namespace Services

#endif // REAL_TIME_CLOCK_H