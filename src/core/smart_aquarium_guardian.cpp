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
#include "src/managers/food_feeder.h"
#include "src/managers/network_controller.h"
#include "src/managers/user_interface.h"
#include "src/managers/water_monitor.h"
#include "src/services/power_controller.h"
#include "src/services/real_time_clock.h"
#include "src/services/storage_service.h"

//----private------------------------------------------------------------------
bool SmartAquariumGuardian::OnInit()
{
    _delay.Start(Config::SYSTEM_TIME_INCREMENT_MS);

    // Create and initialize the GuardianProxy
    Core::GuardianProxy::GetInstance()->Init();

    // Initialize services
    Services::RealTimeClock::GetInstance()->Init();
    Services::StorageService::GetInstance()->Init();
    Services::PowerController::GetInstance()->Init();

    // Initialize managers
    Managers::WaterMonitor::GetInstance()->Init();
    Managers::FoodFeeder::GetInstance()->Init();
    Managers::UserInterface::GetInstance()->Init();
    Managers::NetworkController::GetInstance()->Init();

    return true;
}

//----private------------------------------------------------------------------
void SmartAquariumGuardian::OnUpdate()
{
    // Periodic update
    // Only proceed if the delay has finished
    // This ensures the update runs at a fixed interval
    if (_delay.HasFinished())
    {
        CORE_INFO("Starting periodic update...");

        // Update managers
        Managers::WaterMonitor::GetInstance()->Update();
        Managers::FoodFeeder::GetInstance()->Update();
        Managers::UserInterface::GetInstance()->Update();

        CORE_INFO("Periodic update completed.");
    }

    // Always update Network Controller to handle connectivity and time sync
    Managers::NetworkController::GetInstance()->Update();

    // Debounce delay to prevent flickering. 
    // TODO - See if it can be avoid
    TaskDelayMs(10);
}