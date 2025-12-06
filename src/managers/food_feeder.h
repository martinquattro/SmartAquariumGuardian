/*!****************************************************************************
 * @file    food_feeder.h
 * @brief   FoodFeeder class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef FOOD_FEEDER_H
#define FOOD_FEEDER_H

#include "framework/os/async_worker.h"

struct Result;

namespace Managers {

    class FoodFeeder 
    {
        public:

            /*!
            * @brief Gets the singleton instance of the FoodFeeder.
            * @return FoodFeeder* Pointer to the FoodFeeder instance.
            */
            static FoodFeeder* GetInstance();

            /*!
            * @brief Initializes the FoodFeeder.
            */
            static void Init();

            /*!
            * @brief Updates the FoodFeeder state.
            */
            void Update();

            /*!
            * @brief Feed a specific dose of food.
            * @param dose Amount of food to dispense.
            * @return Result Success or error result of the feeding operation.
            */
            auto Feed(int dose) -> Result;

            /*!
            * @brief Add or modify feeding schedule entry.
            * @param minutesAfterMidnight Minutes after midnight (0-1439).
            * @param slotIndex Feeding slot index.
            * @param dose Dose amount for this entry.
            * @param enabled Is this entry enabled.
            * @return Result Success or error result of the operation.
            */
            auto AddFeedingScheduleEntry(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -> Result;

            /*!
            * @brief Delete feeding schedule entry.
            * @param slotIndex Feeding slot index to delete.
            * @return Result Success or error result of the operation.
            */
            auto DeleteFeedingScheduleEntry(int slotIndex) -> Result;

        private:

            /*!
            * @brief Perform the feeding sequence for the specified dose.
            * @param dose Amount of food to dispense.
            */
            void PerformAsyncFeedingSequence(int dose);

            //---------------------------------------------

            FoodFeeder() : _feedingTask("feeding_task", 4096) {}
            ~FoodFeeder() = default;
            FoodFeeder(const FoodFeeder&) = delete;
            FoodFeeder& operator=(const FoodFeeder&) = delete;

            //---------------------------------------------

            static constexpr const int MAX_FEEDING_SCHECULES = 10;
            static constexpr const int MINUTES_IN_A_DAY = 1440;
            static constexpr const int MIN_FEED_DOSE = 1;
            static constexpr const int MAX_FEED_DOSE = 5;
            static constexpr const float FEEDER_OPEN_ANGLE = 180.0;
            static constexpr const float FEEDER_CLOSED_ANGLE = 0.0f;
            static constexpr const int FEEDER_MOVE_TIME_MS = 1000;
            static constexpr const int FEEDER_WAIT_TIME_MS = 300;

            //---------------------------------------------

            static FoodFeeder* _instance;
            AsyncWorker _feedingTask;
        };

} // namespace Managers

#endif // FOOD_FEEDER_H
