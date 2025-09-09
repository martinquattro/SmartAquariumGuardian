/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/smart_aquarium_guardian.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/app/food_feeder.h"
#include "src/app/user_interface.h"
#include "src/app/water_monitor.h"
#include "src/system/eeprom_memory.h"
#include "src/system/real_time_clock.h"

SmartAquariumGuardian* SmartAquariumGuardian::_instance = nullptr;

//----static-------------------------------------------------------------------
SmartAquariumGuardian* SmartAquariumGuardian::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void SmartAquariumGuardian::Init()
{
    CORE_INFO("Initializing SmartAquariumGuardian...");

    if (_instance != nullptr)
    {
        CORE_ERROR("SmartAquariumGuardian already initialized!");
        return;
    }

    // Start periodic update delay
    _instance = new SmartAquariumGuardian();
    _instance->_delay.Start(Config::SYSTEM_TIME_INCREMENT_MS);

    // Initialize system drivers
    System::EepromMemory::Init();
    System::RealTimeClock::Init();

    // Initialize subsystems
    Subsystems::WaterMonitor::Init();
    Subsystems::FoodFeeder::Init();
    Subsystems::UserInterface::Init();
}

//-----------------------------------------------------------------------------
void SmartAquariumGuardian::Update()
{
    // Periodic update
    // Only proceed if the delay has finished
    // This ensures the update runs at a fixed interval
    if (_delay.HasFinished())
    {
        CORE_INFO("Starting periodic update...");

        // Update subsystems
        Subsystems::WaterMonitor::GetInstance()->Update();
        Subsystems::FoodFeeder::GetInstance()->Update();
        Subsystems::UserInterface::GetInstance()->Update();

        // Debounce delay to prevent flickering. 
        // TODO - See if it can be avoid
        TaskDelayMs(10);

        CORE_INFO("Periodic update completed.");
    }
}