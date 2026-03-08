/*!****************************************************************************
 * @file    module.cpp
 * @brief   Implementation of Module base class methods.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#include "src/core/base/module.h"
#include "src/services/power_controller.h"
#include "esp_timer.h"

namespace Base {

//----private------------------------------------------------------------------
void Module::_CheckBatteryModeChange(bool& enteredBatteryMode, bool& exitedBatteryMode)
{
    enteredBatteryMode = false;
    exitedBatteryMode = false;

    auto powerCtrl = Services::PowerController::GetInstance();
    if (!powerCtrl)
    {
        return;
    }

    const uint64_t nowUs = esp_timer_get_time();

    if (_batteryModeRecoveryEndUs != 0 && nowUs < _batteryModeRecoveryEndUs)
    {
        return;
    }

    _batteryModeRecoveryEndUs = 0;

    bool isBatteryMode = (powerCtrl->GetCurrentMode() == Services::PowerController::Mode::MODE_BATTERY_POWERED);
    if (isBatteryMode != _lastBatteryMode)
    {
        if (isBatteryMode)
        {
            enteredBatteryMode = true;
        }
        else
        {
            exitedBatteryMode = true;
        }

        _lastBatteryMode = isBatteryMode;
        _batteryModeRecoveryEndUs = nowUs + (BATTERY_MODE_RECOVERY_MS * 1000ULL);
    }
}

} // namespace Base
