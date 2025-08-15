/*!****************************************************************************
 * @file    Delay.cpp
 * @brief   Implementation of Delay class for ESP32 projects.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "delay.h"

//-----------------------------------------------------------------------------
Delay::Delay()
{
    _startTime = 0;
    _interval = 0;
}

//-----------------------------------------------------------------------------
Delay::Delay(uint32_t interval_ms)
{
    Start(interval_ms);
}

//-----------------------------------------------------------------------------
void Delay::Start(uint32_t interval_ms)
{
    _interval = (interval_ms * 1000ULL);
    _startTime = esp_timer_get_time();
}

//-----------------------------------------------------------------------------
bool Delay::HasFinished()
{
    if (_interval == 0)
    {
        return false;
    }

    uint64_t current = esp_timer_get_time();
    uint64_t elapsed_ms = (current - _startTime);

    if (elapsed_ms >= _interval)
    {
        _startTime = current;
        return true;
    }
    
    return false;
}
