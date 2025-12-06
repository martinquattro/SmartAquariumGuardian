/*!****************************************************************************
 * @file    food_feeder.cpp
 * @brief   Implementation of the FoodFeeder class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/food_feeder.h"

#include "framework/common_defs.h"
#include "src/drivers/servo.h"

namespace Managers {

FoodFeeder* FoodFeeder::_instance = nullptr;

//----static-------------------------------------------------------------------
FoodFeeder* FoodFeeder::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void FoodFeeder::Init()
{
    CORE_INFO("Initializing FoodFeeder...");
    
    if (_instance != nullptr)
    {
        CORE_ERROR("FoodFeeder already initialized!");
        return;
    }

    _instance = new FoodFeeder();
    Drivers::Servo::Init();
}

//-----------------------------------------------------------------------------
void FoodFeeder::Update()
{
    CORE_INFO("Updating FoodFeeder...");
    
    Drivers::Servo::GetInstance()->Update();
}

//-----------------------------------------------------------------------------
auto FoodFeeder::Feed(int dose) -> Result
{
    CORE_INFO("Feeding %d doses ", dose);

    if (dose <= MIN_FEED_DOSE || dose > MAX_FEED_DOSE)
    {
        CORE_ERROR("Invalid dose %d. Must be in range [%d, %d].", dose, MIN_FEED_DOSE, MAX_FEED_DOSE);
        return Result::Error("Invalid dose amount.");
    }

    if (_feedingTask.IsBusy())
    {
        CORE_WARNING("Feeding already in progress.");
        return Result::Error("Feeding in progress.");
    }

    bool started = _feedingTask.Start(
        [this, dose]()
        {
            this->PerformAsyncFeedingSequence(dose);
        }
    );

    if (!started)
    {
        return Result::Error("Internal Error: Failed to start feeding.");
    }

    return Result::Success("Feeding process started");
}

//-----------------------------------------------------------------------------
void FoodFeeder::PerformAsyncFeedingSequence(int dose)
{
    CORE_INFO("Feeding sequence started for %d doses.", dose);

    Drivers::Servo* servo = Drivers::Servo::GetInstance();

    for (int i = 0; i < dose; ++i)
    {
        CORE_INFO("Dispensing dose %d of %d.", i + 1, dose);

        // Open feeder
        servo->FadeToAngle(FEEDER_OPEN_ANGLE, FEEDER_MOVE_TIME_MS);
        TaskDelayMs(FEEDER_MOVE_TIME_MS + FEEDER_WAIT_TIME_MS);

        // Close feeder
        servo->FadeToAngle(FEEDER_CLOSED_ANGLE, FEEDER_MOVE_TIME_MS);
        TaskDelayMs(FEEDER_MOVE_TIME_MS + FEEDER_WAIT_TIME_MS);
    }

    CORE_INFO("Feeding sequence completed for %d doses.", dose);
}

} // namespace Managers
