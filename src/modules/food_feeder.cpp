/*!****************************************************************************
 * @file    food_feeder.cpp
 * @brief   Implementation of the FoodFeeder class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/modules/food_feeder.h"

#include "framework/common_defs.h"
#include "src/drivers/servo.h"

namespace Subsystems {

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

} // namespace Subsystems
