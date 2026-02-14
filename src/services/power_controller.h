/*!****************************************************************************
 * @file    power_controller.h
 * @brief   Declaration of the PowerController manager.
 * @author  Quattrone Martin
 * @date    Jan 2022
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "src/core/base/service.h"

namespace Services {

class PowerController : public Base::Singleton<PowerController>
                      , public Base::Service
{
    public:

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

        friend class Base::Singleton<PowerController>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "PowerController"; }

        /*!
         * @brief Initializes the Module.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override;

        //---------------------------------------------

        PowerController();
        ~PowerController() = default;
        PowerController(const PowerController&) = delete;
        PowerController& operator=(const PowerController&) = delete;

        //---------------------------------------------

        static constexpr float VOLTAGE_MULTIPLIER = 2.0f;
        //---------------------------------------------

        AnalogIn _batteryVoltagePin;
        DigitalInOut _usbDetectPin;

};

} // namespace Services