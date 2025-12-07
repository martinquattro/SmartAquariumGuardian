/*!****************************************************************************
 * @file    date_time.cpp
 * @brief   Utility class for time manipulation and formatting.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/utils/date_time.h"

#include <sstream>
#include <iomanip>

namespace Utils {

//-----------------------------------------------------------------------------
DateTime::DateTime() 
    : _hour(0), _minute(0), _second(0) 
{}

//-----------------------------------------------------------------------------
DateTime::DateTime(uint8_t hour, uint8_t minute, uint8_t second)
    : _hour(hour % 24)
    , _minute(minute % 60)
    , _second(second % 60)
{}

//-----------------------------------------------------------------------------
DateTime::DateTime(uint32_t secondsOfDay)
{
    secondsOfDay %= 24 * 3600; // wrap within a day

    _hour = secondsOfDay / 3600;
    _minute = (secondsOfDay % 3600) / 60;
    _second = secondsOfDay % 60;
}

//-----------------------------------------------------------------------------
void DateTime::Set(uint8_t hour, uint8_t minute, uint8_t second)
{
    _hour = hour % 24;
    _minute = minute % 60;
    _second = second % 60;
}

//-----------------------------------------------------------------------------
uint32_t DateTime::ToSecondsOfDay() const
{
    return ToMinutesOfDay() * 60 + _second;
}

//-----------------------------------------------------------------------------
uint32_t DateTime::ToMinutesOfDay() const
{
    return _hour * 60 + _minute;
}

//-----------------------------------------------------------------------------
std::string DateTime::ToString() const
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << (int)_hour   << ":"
        << std::setw(2) << std::setfill('0') << (int)_minute ;

    return oss.str();
}

//-----------------------------------------------------------------------------
bool DateTime::operator==(const DateTime& other) const
{
    return ToSecondsOfDay() == other.ToSecondsOfDay();
}

//-----------------------------------------------------------------------------
bool DateTime::operator<(const DateTime& other) const
{
    return ToSecondsOfDay() < other.ToSecondsOfDay();
}

} // namespace Utils
