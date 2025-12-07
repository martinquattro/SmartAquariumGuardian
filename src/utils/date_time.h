/*!****************************************************************************
 * @file    date_time.h
 * @brief   Utility class for time manipulation and formatting.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
#include <cstdint>

namespace Utils {

class DateTime
{
    public:

        DateTime();
        DateTime(uint8_t hour, uint8_t minute, uint8_t second);
        DateTime(uint32_t secondsOfDay);

        // Conversion
        uint32_t ToSecondsOfDay() const;
        uint32_t ToMinutesOfDay() const;
        std::string ToString() const;

        // Setters / Getters
        void Set(uint8_t hour, uint8_t minute, uint8_t second);
        uint8_t GetHour() const { return _hour; }
        uint8_t GetMinute() const { return _minute; }
        uint8_t GetSecond() const { return _second; }

        // Operators
        bool operator==(const DateTime& other) const;
        bool operator<(const DateTime& other) const;

    private:

        uint8_t _hour;
        uint8_t _minute;
        uint8_t _second;
};

} // namespace Utils

#endif // DATE_TIME_H
