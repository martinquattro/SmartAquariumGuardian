/*!****************************************************************************
 * @file    power_controller.cpp
 * @brief   Implementation of the PowerController class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/services/power_controller.h"

#include "framework/common_defs.h"
#include "include/config.h"

namespace Services {

PowerController* PowerController::_instance = nullptr;

//----static-------------------------------------------------------------------
PowerController* PowerController::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void PowerController::Init()
{
    CORE_INFO("Initializing PowerController...");
    
    if (_instance != nullptr)
    {
        CORE_ERROR("PowerController already initialized!");
        return;
    }

    _instance = new PowerController();
}

//-----------------------------------------------------------------------------
auto PowerController::GetCurrentMode() -> Mode
{
    // Read USB detect pin state
    if (_usbDetectPin.Read() == OFF)
    {
        return Mode::MODE_BATTERY_POWERED;
    }
    return Mode::MODE_USB_POWERED;
}

//-----------------------------------------------------------------------------
auto PowerController::GetBatteryLevel() -> BatteryLevel
{
    // Read battery voltage
    const float voltage = _batteryVoltagePin.ReadVoltage(64) * VOLTAGE_MULTIPLIER;

    CORE_INFO("Battery voltage: %.2f V", voltage);

    if (voltage >= 4.0f)
    {
        return BatteryLevel::LEVEL_FULL;
    }
    else if (voltage >= 3.8f)
    {
        return BatteryLevel::LEVEL_HIGH;
    }
    else if (voltage >= 3.6f)
    {
        return BatteryLevel::LEVEL_MEDIUM;
    }
    else if (voltage >= 3.4f)
    {
        return BatteryLevel::LEVEL_LOW;
    }

    return BatteryLevel::LEVEL_CRITICAL;
}

//----private------------------------------------------------------------------
PowerController::PowerController()
    : _batteryVoltagePin(Config::BATTERY_ADC_PIN)
    , _usbDetectPin(Config::USB_DETECT_PIN, DigitalInOut::INPUT_MODE)
{
}

} // namespace Services