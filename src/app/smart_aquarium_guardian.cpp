/*!****************************************************************************
 * @file    smart_aquarium_guardian.cpp
 * @brief   Implementation of the SmartAquariumGuardian class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/smart_aquarium_guardian.h"

#include "include/config.h"
#include "framework/common_defs.h"

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
    if (_delay.HasFinished())
    {
        // Update subsystems here

        // Debounce delay to prevent flickering. See if it can be avoid
        delay(10);
    }
}

//----private------------------------------------------------------------------
SmartAquariumGuardian::SmartAquariumGuardian()
    : _delay(SYSTEM_TIME_INCREMENT_MS)
{}