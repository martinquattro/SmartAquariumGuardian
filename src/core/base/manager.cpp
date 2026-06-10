/*!****************************************************************************
 * @file    manager.cpp
 * @brief   Implementation of Manager base class methods.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#include "src/core/base/manager.h"
#include "src/services/power_controller.h"
#include "esp_timer.h"

namespace Base {

//----public-------------------------------------------------------------------
void Manager::Update(int delayAfterMs)
{
    bool enteredBatteryMode = false;
    bool exitedBatteryMode = false;

    _CheckBatteryModeChange(enteredBatteryMode, exitedBatteryMode);

    if (enteredBatteryMode)
    {
        CORE_INFO("%s entering battery mode", GetModuleName());
        OnBatteryModeEnter();
    }
    else if (exitedBatteryMode)
    {
        CORE_INFO("%s exiting battery mode", GetModuleName());
        OnBatteryModeExit();
    }

    OnUpdate();

    if (delayAfterMs > 0)
    {
        TaskDelayMs(delayAfterMs);
    }
}

//----private------------------------------------------------------------------
void Manager::_CheckBatteryModeChange(bool& enteredBatteryMode, bool& exitedBatteryMode)
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
