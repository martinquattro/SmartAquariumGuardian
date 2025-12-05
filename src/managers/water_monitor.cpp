/*!****************************************************************************
 * @file    water_monitor.cpp
 * @brief   Implementation of the WaterMonitor class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/water_monitor.h"

#include "framework/common_defs.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"
#include "src/core/guardian_proxy.h"

namespace Managers {

WaterMonitor* WaterMonitor::_instance = nullptr;

//----static-------------------------------------------------------------------
WaterMonitor* WaterMonitor::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void WaterMonitor::Init()
{
    CORE_INFO("Initializing WaterMonitor...");
    
    if (_instance != nullptr)
    {
        CORE_ERROR("WaterMonitor already initialized!");
        return;
    }

    _instance = new WaterMonitor();
    
    Drivers::TdsSensor::Init();
    Drivers::TemperatureSensor::Init();
}

//-----------------------------------------------------------------------------
void WaterMonitor::Update()
{
    CORE_INFO("Updating WaterMonitor...");
    
    Drivers::TdsSensor::GetInstance()->Update();
    Drivers::TemperatureSensor::GetInstance()->Update();
}

//-----------------------------------------------------------------------------
int WaterMonitor::GetTdsReading() const
{
    return (Drivers::TdsSensor::GetInstance()->GetLastReading());
}

//-----------------------------------------------------------------------------
float WaterMonitor::GetTemperatureReading() const
{
    return (Drivers::TemperatureSensor::GetInstance()->GetLastReading());
}

//-----------------------------------------------------------------------------
Result WaterMonitor::SetTemperatureLimits(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled)
{
    CORE_INFO("WaterMonitor: Request to set temp limits -> Min: %.2f (En:%d), Max: %.2f (En:%d)",
              minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

    if (isMinLimitEnabled && isMaxLimitEnabled)
    {
        if (minTemp >= maxTemp)
        {
            CORE_ERROR("WaterMonitor Validation Error: Min temp (%.2f) cannot be >= Max temp (%.2f) when both are enabled.", minTemp, maxTemp);
            return Result::Error("Invalid limits: Minimum must be less than Maximum.");
        }
    }

    // TODO - Check valid temperature ranges if needed.

    const bool success = Core::GuardianProxy::GetInstance()->SaveTempLimitsInStorage(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

    if (success)
    {
        CORE_INFO("WaterMonitor: All temperature limit parameters saved successfully.");
        return Result::Success("Temperature limits updated successfully.");
    }
    else
    {
        CORE_ERROR("WaterMonitor Storage Error: Failed to save temperature parameters.");
        return Result::Error("Storage failure: Could not save settings to permanent memory.");
    }
}

} // namespace Managers
