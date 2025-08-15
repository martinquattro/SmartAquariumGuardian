/*!****************************************************************************
 * @file    digital_in_out.h
 * @brief   GPIO output control class for ESP32 (ESP-IDF framework).
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include "driver/gpio.h"
#include "framework/pin_names.h"

class DigitalInOut 
{
    public:

        enum PinMode
        {
            INPUT_MODE,
            OUTPUT_MODE,
            INPUT_OUTPUT_MODE
        };

        /**
         * @brief Construct a DigitalOut instance and configure the pin as output.
         * @param pin   PinName from pin_names.h.
         * @param mode  Pin mode (INPUT_MODE, OUTPUT_MODE, INPUT_OUTPUT_MODE).
         * @param value Initial output state (0 or 1).
         */
        DigitalInOut(PinName pin, PinMode mode, int value = 0);

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
         * @brief Toggle the output pin logic level.
         */
        void Toggle();

    private:

        gpio_num_t _pin;
        PinMode _mode;
};
