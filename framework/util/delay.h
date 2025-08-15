/*!****************************************************************************
 * @file    Delay.h
 * @brief   Simple delay/timer utility for periodic checks in ESP32 projects.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include "esp_timer.h"

class Delay
{
    public:

        /**
         * @brief Construct a Delay instance.
         */
        Delay();

        /**
         * @brief Construct a Delay instance with a specified interval.
         * @param interval_ms Interval in milliseconds.
         */
        Delay(uint32_t interval_ms);
        
        /** 
         * @brief Start the delay timer.
         * @param interval_ms Interval in milliseconds.
         */
        void Start(uint32_t interval_ms);

        /**
         * @brief Check if the delay interval has finished.
         *        If finished, restarts the timer automatically.
         * @return true if interval elapsed, false otherwise.
         */
        bool HasFinished();

    private:

        uint64_t _startTime;
        uint64_t _interval;
};
