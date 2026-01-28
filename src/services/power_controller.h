/*!****************************************************************************
 * @file    power_controller.h
 * @brief   Declaration of the PowerController manager.
 * @author  Quattrone Martin
 * @date    Jan 2022
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"

namespace Services {

class PowerController
{
    public:

        /**
         * @brief Get the singleton instance of PowerController.
         * @return PowerController* Pointer to the PowerController instance.
         */
        static PowerController* GetInstance();

        /**
         * @brief Initialize the PowerController.
         */
        static void Init();

        enum class Mode
        {
            MODE_USB_POWERED,
            MODE_BATTERY_POWERED,
            _size
        };

        enum class BatteryLevel
        {
            LEVEL_FULL,
            LEVEL_HIGH,
            LEVEL_MEDIUM,
            LEVEL_LOW,
            LEVEL_CRITICAL,
            _size
        };

        /**
         * @brief Get the current power mode.
         * @return Mode Current power mode.
         */
        auto GetCurrentMode() -> Mode;

        /**
         * @brief Get the current battery level percentage (0-100).
         * @return int Battery level percentage.
         */
        auto GetBatteryLevel() -> BatteryLevel;

    private:

        PowerController();
        ~PowerController() = default;
        PowerController(const PowerController&) = delete;
        PowerController& operator=(const PowerController&) = delete;

        //---------------------------------------------

        static constexpr float VOLTAGE_MULTIPLIER = 2.0f;
        //---------------------------------------------

        static PowerController* _instance;
        AnalogIn _batteryVoltagePin;
        DigitalInOut _usbDetectPin;

};

} // namespace Services