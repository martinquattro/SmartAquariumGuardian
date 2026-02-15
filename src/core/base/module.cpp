/*!****************************************************************************
 * @file    module.cpp
 * @brief   Implementation of Module base class methods.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#include "src/core/base/module.h"
#include "src/services/power_controller.h"

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
    }
}

} // namespace Base
