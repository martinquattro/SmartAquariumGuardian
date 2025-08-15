/*!****************************************************************************
 * @file    main.cpp
 * @brief   Implementation of the main application entry point for the Smart Aquarium Guardian. 
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/smart_aquarium_guardian.h"

extern "C" void app_main(void) 
{
    SmartAquariumGuardian::Init();

    while (true) 
    {
        SmartAquariumGuardian::GetInstance()->Update();
    }
}