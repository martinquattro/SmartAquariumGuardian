/*!****************************************************************************
 * @file    water_monitor.cpp
 * @brief   Implementation of the WaterMonitor class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/water_monitor.h"

#include "src/drivers/tds_sensor.h"
#include "framework/common_defs.h"

namespace Subsystems {

WaterMonitor* WaterMonitor::mInstance = nullptr;

//----static-------------------------------------------------------------------
WaterMonitor* WaterMonitor::GetInstance()
{
    return mInstance;
}

//----static-------------------------------------------------------------------
void WaterMonitor::Init()
{
    if (mInstance == nullptr)
    {
        mInstance = new WaterMonitor();
    }

    Drivers::TdsSensor::Init();
}

//-----------------------------------------------------------------------------
void WaterMonitor::Update()
{
    Drivers::TdsSensor::GetInstance()->Update();
}

//-----------------------------------------------------------------------------
int WaterMonitor::GetTdsReading()
{
    return (Drivers::TdsSensor::GetInstance()->GetLastReading());
}

} // namespace Subsystems
