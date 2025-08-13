/*!****************************************************************************
 * @file    DigitalOut.h
 * @brief   GPIO output control class for ESP32 (ESP-IDF framework).
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include "driver/gpio.h"
#include "PinNames.h"

class DigitalOut 
{
    public:

        /**
         * @brief Construct a DigitalOut instance and configure the pin as output.
         * @param pin   PinName from PinNames.h.
         * @param value Initial output state (0 or 1).
         */
        DigitalOut(PinName pin, int value = 0);

        /**
         * @brief Set the output pin logic level.
         * @param value Logic level (0 for LOW, 1 for HIGH).
         */
        void Write(int value);

        /**
         * @brief Read the current output pin logic level.
         * @return int Current logic level (0 or 1).
         */
        int Read() const;

        /**
         * @brief Toggle the current output pin logic level.
         */
        void Toggle();

    private:

        gpio_num_t _pin;
};
