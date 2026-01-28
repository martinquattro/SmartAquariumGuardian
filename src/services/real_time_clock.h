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
#include <sys/time.h>

struct Result;

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
         * @param time    Reference to a DateTime object to store the current time.
         * @return true if successful, false otherwise.
        */
        auto GetTime(Utils::DateTime& time) -> bool;

        /**
         * @brief Set the current time on the RTC.
         * @param dateTime   DateTime object with the time to set.
         * @return true if success, false otherwise.
        */
        bool SetTime(const Utils::DateTime& dateTime);

        /**
        * @brief Check if the time has been synchronized.
        * @return true if time is synchronized, false otherwise.
        */
        bool IsTimeSynced() const { return _isTimeSynced; }

        /*!
        * @brief Initializes the time synchronization process. 
                 Reads timezone from storage.
        * @param timezone  Optional timezone string (e.g., "UTC", "PST8PDT"). If nullptr, reads from storage.
        * @return Result indicating success or failure.
        */
        Result InitTimeSync(const char* timezone = nullptr) const;
        
        /*!
        * @brief Callback function for time synchronization.
        * @param tv    Pointer to timeval structure with the synchronized time.
        */
        static void TimeSyncCallback(struct ::timeval *tv);

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
        bool _isTimeSynced;
};

} // namespace Services

#endif // REAL_TIME_CLOCK_H