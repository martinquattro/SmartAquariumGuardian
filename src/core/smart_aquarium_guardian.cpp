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
    // Create and initialize the GuardianProxy
    Core::GuardianProxy::GetInstance()->Init();

    // Initialize services
    Services::RealTimeClock::GetInstance()->Init(100);
    Services::StorageService::GetInstance()->Init(100);
    Services::PowerController::GetInstance()->Init(100);

    // Display + backlight draw high current; delay after before starting network
    Managers::UserInterface::GetInstance()->Init(300);

    // Initialize managers (sensors first, low current)
    Managers::WaterMonitor::GetInstance()->Init(200);

    // Servo init can draw significant current; delay after so supply can settle
    Managers::FoodFeeder::GetInstance()->Init(400);

    Managers::NetworkController::GetInstance()->Init();

    _delay.Start(Config::SYSTEM_TIME_INCREMENT_MS);

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

        Managers::WaterMonitor::GetInstance()->Update(100);
        Managers::FoodFeeder::GetInstance()->Update(100);
        Managers::UserInterface::GetInstance()->Update(100);

        CORE_INFO("Periodic update completed.");
    }

    // Always update Network Controller to handle connectivity and time sync
    Managers::NetworkController::GetInstance()->Update();
}