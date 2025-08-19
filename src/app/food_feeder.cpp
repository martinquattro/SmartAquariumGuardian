/*!****************************************************************************
 * @file    food_feeder.cpp
 * @brief   Implementation of the FoodFeeder class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/food_feeder.h"

#include "framework/common_defs.h"

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
    if (_instance == nullptr)
    {
        _instance = new FoodFeeder();
    }
}

//-----------------------------------------------------------------------------
void FoodFeeder::Update()
{

}

} // namespace Subsystems
