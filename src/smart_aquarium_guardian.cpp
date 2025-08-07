/*!****************************************************************************
 * @file    fish_tank_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.    
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "smart_aquarium_guardian.h"

SmartAquariumGuardian* SmartAquariumGuardian::mInstance = nullptr;

//----static-------------------------------------------------------------------
void SmartAquariumGuardian::Init()
{
    if (mInstance == nullptr)
    {
        mInstance = new SmartAquariumGuardian();
    }
}

//----static-------------------------------------------------------------------
SmartAquariumGuardian* SmartAquariumGuardian::GetInstance()
{
    return mInstance;
}

//-----------------------------------------------------------------------------
void SmartAquariumGuardian::Update()
{

}

//----private------------------------------------------------------------------
SmartAquariumGuardian::SmartAquariumGuardian() 
{}