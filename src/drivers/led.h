/*!****************************************************************************
 * @file    led.h
 * @brief   Declaration of a simple LED driver class.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#pragma once

#include "framework/common_defs.h"

namespace Drivers {

class Led
{
    public:

        Led(PinName pin, bool isOn = false);
        ~Led() = default;

        /**
         * @brief Turn the LED on.
         */
        void TurnOn();

        /**
         * @brief Turn the LED off.
         */
        void TurnOff();

        /**
         * @brief Toggle the LED state.
         */
        void Toggle();

        /**
         * @brief Check if the LED is currently on.
         * @return true if the LED is on, false otherwise.
         */
        bool IsOn() const;

    private:

        DigitalInOut _pin;
};

} // namespace Drivers