/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/smart_aquarium_guardian.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/app/water_monitor.h"

SmartAquariumGuardian* SmartAquariumGuardian::_instance = nullptr;

//----static-------------------------------------------------------------------
SmartAquariumGuardian* SmartAquariumGuardian::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void SmartAquariumGuardian::Init()
{
    if (_instance == nullptr)
    {
        _instance = new SmartAquariumGuardian();
    }

    Subsystems::WaterMonitor::Init();
}

//-----------------------------------------------------------------------------
void SmartAquariumGuardian::Update()
{
    if (_delay.HasFinished())
    {
        Subsystems::WaterMonitor::GetInstance()->Update();
        
        // Debounce delay to prevent flickering. 
        // TODO - See if it can be avoid
        TaskDelay(10);
    }
}

//----private------------------------------------------------------------------
SmartAquariumGuardian::SmartAquariumGuardian()
    : _delay(Config::SYSTEM_TIME_INCREMENT_MS)
{}