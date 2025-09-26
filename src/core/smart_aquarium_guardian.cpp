/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/core/smart_aquarium_guardian.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/modules/food_feeder.h"
#include "src/modules/iot_manager.h"
#include "src/modules/user_interface.h"
#include "src/modules/water_monitor.h"
#include "src/services/eeprom_memory.h"
#include "src/services/real_time_clock.h"

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

    // Initialize hardware components
    Services::EepromMemory::Init();
    Services::RealTimeClock::Init();

    // Initialize subsystems
    Subsystems::WaterMonitor::Init();
    Subsystems::FoodFeeder::Init();
    Subsystems::UserInterface::Init();
    Subsystems::IotManager::Init();

    CORE_INFO("SmartAquariumGuardian initialized.");
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

            time_t now;
            struct tm timeinfo;
            time(&now);
            localtime_r(&now, &timeinfo);

            CORE_INFO("Now: %02d:%02d:%02d",
                        timeinfo.tm_hour
                    , timeinfo.tm_min
                    , timeinfo.tm_sec
            );

        // Update subsystems
        // Subsystems::WaterMonitor::GetInstance()->Update();
        // Subsystems::FoodFeeder::GetInstance()->Update();
        Subsystems::UserInterface::GetInstance()->Update();

        // CORE_INFO("Periodic update completed.");

        // Debounce delay to prevent flickering. 
        // TODO - See if it can be avoid
        TaskDelayMs(10);
    }

    // Always update IoT manager to handle connectivity and time sync
    Subsystems::IotManager::GetInstance()->Update();

    // Debounce delay to prevent flickering. 
    // TODO - See if it can be avoid
    TaskDelayMs(10);
}