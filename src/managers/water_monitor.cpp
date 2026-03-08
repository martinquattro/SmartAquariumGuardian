/*!****************************************************************************
 * @file    water_monitor.cpp
 * @brief   Implementation of the WaterMonitor class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/water_monitor.h"

#include "framework/common_defs.h"
#include "src/core/guardian_proxy.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"

namespace Managers {

//----private------------------------------------------------------------------
bool WaterMonitor::OnInit()
{
    _temperatureSensor = Drivers::TemperatureSensor::GetInstance();
    _tdsSensor = Drivers::TdsSensor::GetInstance();

    return (_temperatureSensor->Init() && _tdsSensor->Init());
}

//----private------------------------------------------------------------------
void WaterMonitor::OnUpdate()
{
    _temperatureSensor->Update();

    _tdsSensor->SetTemperature(_temperatureSensor->GetLastReading());
    _tdsSensor->Update();
}

//-----------------------------------------------------------------------------
int WaterMonitor::GetTdsReading() const
{
    return (_tdsSensor->GetLastReading());
}

//-----------------------------------------------------------------------------
float WaterMonitor::GetTemperatureReading() const
{
    return (_temperatureSensor->GetLastReading());
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

    if (isMinLimitEnabled)
    {
        if (minTemp < MIN_TEMP_VALID_VALUE || minTemp > MAX_TEMP_VALID_VALUE)
        {
            CORE_ERROR("WaterMonitor Validation Error: Min temp (%.2f) out of valid range [%.2f, %.2f].", minTemp, MIN_TEMP_VALID_VALUE, MAX_TEMP_VALID_VALUE);
            return Result::Error("Invalid minimum temperature limit.");
        }
    }

    if (isMaxLimitEnabled)
    {
        if (maxTemp < MIN_TEMP_VALID_VALUE || maxTemp > MAX_TEMP_VALID_VALUE)
        {
            CORE_ERROR("WaterMonitor Validation Error: Max temp (%.2f) out of valid range [%.2f, %.2f].", maxTemp, MIN_TEMP_VALID_VALUE, MAX_TEMP_VALID_VALUE);
            return Result::Error("Invalid maximum temperature limit.");
        }
    }

    const bool success = Core::GuardianProxy::GetInstance()->SaveTempLimitsInStorage(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

    if (success)
    {
        CORE_INFO("WaterMonitor: All temperature limit parameters saved successfully.");
        return Result::Success("Temperature limits updated successfully.");
    }
    else
    {
        CORE_ERROR("WaterMonitor Storage Error: Failed to save temperature parameters.");
        return Result::Error("Internal Error: Could not save settings to permanent memory.");
    }
}

//-----------------------------------------------------------------------------
void WaterMonitor::GetTemperatureLimits(float& minTemp, bool& isMinLimitEnabled, float& maxTemp, bool& isMaxLimitEnabled) const
{
    Core::GuardianProxy::GetInstance()->GetTempLimitsFromStorage(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);
}

//-----------------------------------------------------------------------------
bool WaterMonitor::IsTemperatureOutOfLimits() const
{
    float minTemp = 0.0f, maxTemp = 0.0f;
    bool isMinLimitEnabled = false, isMaxLimitEnabled = false;

    GetTemperatureLimits(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

    const float currentTemp = GetTemperatureReading();

    if (isMinLimitEnabled && (currentTemp < minTemp))
    {
        CORE_INFO("Temperature reading %.2f is below the minimum limit of %.2f.", currentTemp, minTemp);
        return true;
    }

    if (isMaxLimitEnabled && (currentTemp > maxTemp))
    {
        CORE_INFO("Temperature reading %.2f is above the maximum limit of %.2f.", currentTemp, maxTemp);
        return true;
    }

    return false;
}

//-----------------------------------------------------------------------------
Result WaterMonitor::SetTdsLimits(const int minTds, const bool isMinLimitEnabled, const int maxTds, const bool isMaxLimitEnabled)
{
    CORE_INFO("WaterMonitor: Request to set TDS limits -> Min: %d (En:%d), Max: %d (En:%d)",
              minTds, isMinLimitEnabled, maxTds, isMaxLimitEnabled);

    if (isMinLimitEnabled && isMaxLimitEnabled)
    {
        if (minTds >= maxTds)
        {
            CORE_ERROR("WaterMonitor Validation Error: Min TDS (%d) cannot be >= Max TDS (%d) when both are enabled.", minTds, maxTds);
            return Result::Error("Invalid limits: Minimum must be less than Maximum.");
        }
    }

    if (isMinLimitEnabled)
    {
        if (minTds < MIN_TDS_VALID_VALUE || minTds > MAX_TDS_VALID_VALUE)
        {
            CORE_ERROR("WaterMonitor Validation Error: Min TDS (%d) out of valid range [%d, %d].", minTds, MIN_TDS_VALID_VALUE, MAX_TDS_VALID_VALUE);
            return Result::Error("Invalid minimum TDS limit.");
        }
    }

    if (isMaxLimitEnabled)
    {
        if (maxTds < MIN_TDS_VALID_VALUE || maxTds > MAX_TDS_VALID_VALUE)
        {
            CORE_ERROR("WaterMonitor Validation Error: Max TDS (%d) out of valid range [%d, %d].", maxTds, MIN_TDS_VALID_VALUE, MAX_TDS_VALID_VALUE);
            return Result::Error("Invalid maximum TDS limit.");
        }
    }

    const bool success = Core::GuardianProxy::GetInstance()->SaveTdsLimitsInStorage(minTds, isMinLimitEnabled, maxTds, isMaxLimitEnabled);

    if (success)
    {
        CORE_INFO("WaterMonitor: All TDS limit parameters saved successfully.");
        return Result::Success("TDS limits updated successfully.");
    }
    else
    {
        CORE_ERROR("WaterMonitor Storage Error: Failed to save TDS parameters.");
        return Result::Error("Internal Error: Could not save settings to permanent memory.");
    }
}

//-----------------------------------------------------------------------------
void WaterMonitor::GetTdsLimits(int& minTds, bool& isMinLimitEnabled, int& maxTds, bool& isMaxLimitEnabled) const
{
    Core::GuardianProxy::GetInstance()->GetTdsLimitsFromStorage(minTds, isMinLimitEnabled, maxTds, isMaxLimitEnabled);
}

//-----------------------------------------------------------------------------
bool WaterMonitor::IsTdsOutOfLimits() const
{
    int minTds = 0, maxTds = 0;
    bool isMinLimitEnabled = false, isMaxLimitEnabled = false;

    GetTdsLimits(minTds, isMinLimitEnabled, maxTds, isMaxLimitEnabled);

    const int currentTds = GetTdsReading();

    if (isMinLimitEnabled && (currentTds < minTds))
    {
        CORE_INFO("TDS reading %d is below the minimum limit of %d.", currentTds, minTds);
        return true;
    }

    if (isMaxLimitEnabled && (currentTds > maxTds))
    {
        CORE_INFO("TDS reading %d is above the maximum limit of %d.", currentTds, maxTds);
        return true;
    }

    return false;
}

} // namespace Managers
