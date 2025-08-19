/*!****************************************************************************
 * @file    water_monitor.cpp
 * @brief   Implementation of the WaterMonitor class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/water_monitor.h"

#include "src/drivers/temperature_sensor.h"
#include "src/drivers/tds_sensor.h"
#include "framework/common_defs.h"

namespace Subsystems {

WaterMonitor* WaterMonitor::_instance = nullptr;

//----static-------------------------------------------------------------------
WaterMonitor* WaterMonitor::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void WaterMonitor::Init()
{
    if (_instance == nullptr)
    {
        _instance = new WaterMonitor();
    }

    Drivers::TdsSensor::Init();
    //Drivers::TemperatureSensor::Init();
}

//-----------------------------------------------------------------------------
void WaterMonitor::Update()
{
     Drivers::TdsSensor::GetInstance()->Update();
    //Drivers::TemperatureSensor::GetInstance()->Update();
}

//-----------------------------------------------------------------------------
int WaterMonitor::GetTdsReading()
{
    return (Drivers::TdsSensor::GetInstance()->GetLastReading());
}

} // namespace Subsystems
