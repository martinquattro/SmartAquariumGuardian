/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/core/smart_aquarium_guardian.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include "src/core/guardian_proxy.h"
#include "src/services/storage_service.h"
#include "src/managers/food_feeder.h"
#include "src/managers/network_controller.h"
#include "src/managers/user_interface.h"
#include "src/managers/water_monitor.h"
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

    // Create and initialize the GuardianProxy
    Core::GuardianProxy::Init();

    // Initialize services
    Services::RealTimeClock::Init();
    Services::StorageService::Init();

    // Initialize managers
    Managers::WaterMonitor::Init();
    Managers::FoodFeeder::Init();
    Managers::UserInterface::Init();
    Managers::NetworkController::Init();

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

        // Update managers
        // Managers::WaterMonitor::GetInstance()->Update();
        // Managers::FoodFeeder::GetInstance()->Update();
        Managers::UserInterface::GetInstance()->Update();

        CORE_INFO("Periodic update completed.");
    }

    // Always update Network Controller to handle connectivity and time sync
    Managers::NetworkController::GetInstance()->Update();

    // Debounce delay to prevent flickering. 
    // TODO - See if it can be avoid
    TaskDelayMs(10);
}