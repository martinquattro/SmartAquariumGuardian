/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.    
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "smart_aquarium_guardian.h"

SmartAquariumGuardian* SmartAquariumGuardian::_instance = nullptr;

//----static-------------------------------------------------------------------
SmartAquariumGuardian* SmartAquariumGuardian::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void SmartAquariumGuardian::Init()
{
    if (_instance == nullptr)
    {
        _instance = new SmartAquariumGuardian();
    }
}

//-----------------------------------------------------------------------------
void SmartAquariumGuardian::Update()
{

}

//----private------------------------------------------------------------------
SmartAquariumGuardian::SmartAquariumGuardian() 
{}