/*!****************************************************************************
 * @file    food_feeder.h
 * @brief   FoodFeeder class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef FOOD_FEEDER_H
#define FOOD_FEEDER_H

namespace Subsystems {

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

        private:

            FoodFeeder() {}
            ~FoodFeeder() = default;
            FoodFeeder(const FoodFeeder&) = delete;
            FoodFeeder& operator=(const FoodFeeder&) = delete;

            //---------------------------------------------

            static FoodFeeder* _instance;
        };

} // namespace Subsystems

#endif // FOOD_FEEDER_H
