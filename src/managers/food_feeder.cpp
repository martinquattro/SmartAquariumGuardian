/*!****************************************************************************
 * @file    food_feeder.cpp
 * @brief   Implementation of the FoodFeeder class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/food_feeder.h"

#include "framework/common_defs.h"
#include "src/drivers/servo.h"
#include "src/core/guardian_proxy.h"

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

    if (dose < MIN_FEED_DOSE || dose > MAX_FEED_DOSE)
    {
        CORE_WARNING("Invalid dose %d. Must be in range [%d, %d].", dose, MIN_FEED_DOSE, MAX_FEED_DOSE);
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
auto FoodFeeder::AddFeedingScheduleEntry(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -> Result
{
    CORE_INFO("Adding/Modifying feeding schedule entry: Time=%d min, SlotIndex=%d, Dose=%d, Enabled=%d",
              minutesAfterMidnight, slotIndex, dose, enabled);

    if (minutesAfterMidnight < 0 || minutesAfterMidnight >= MINUTES_IN_A_DAY)
    {
        CORE_WARNING("Invalid minutesAfterMidnight %d. Must be in range [0, 1439].", minutesAfterMidnight);
        return Result::Error("Invalid time for feeding schedule.");
    }

    if (slotIndex < 0 || slotIndex >= MAX_FEEDING_SCHECULES)
    {
        CORE_WARNING("Invalid slotIndex %d. Must be in range [0, %d].", slotIndex, MAX_FEEDING_SCHECULES - 1);
        return Result::Error("Max feeding schedule entries exceeded.");
    }

    if (dose < MIN_FEED_DOSE || dose > MAX_FEED_DOSE)
    {
        CORE_WARNING("Invalid dose %d. Must be in range [%d, %d].", dose, MIN_FEED_DOSE, MAX_FEED_DOSE);
        return Result::Error("Invalid dose amount for feeding schedule.");
    }

    const bool success = Core::GuardianProxy::GetInstance()->SaveFeedingScheduleInStorage(
        minutesAfterMidnight,
        slotIndex,
        dose,
        enabled
    );

    if (!success)
    {
        CORE_ERROR("Failed to save feeding schedule to storage");
        return Result::Error("Internal error: Failed to save feeding schedule to storage");
    }

    CORE_INFO("Feeding schedule entry added/modified successfully.");
    return Result::Success("Feeding schedules updated.");
}

//----private------------------------------------------------------------------
void FoodFeeder::PerformAsyncFeedingSequence(int dose)
{
    CORE_INFO("Feeding sequence started for %d doses.", dose);

    Core::GuardianProxy::GetInstance()->UpdateFeedingStatusIndicator(true);

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
    Core::GuardianProxy::GetInstance()->UpdateFeedingStatusIndicator(false);
}

} // namespace Managers
