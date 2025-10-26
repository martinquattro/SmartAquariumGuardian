/*!****************************************************************************
 * @file    water_monitor.cpp
 * @brief   Implementation of the WaterMonitor class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/water_monitor.h"

#include "framework/common_defs.h"
#include "services/eeprom_memory.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"

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

} // namespace Managers
