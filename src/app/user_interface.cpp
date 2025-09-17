/*!****************************************************************************
 * @file    user_interface.cpp
 * @brief   Implementation of the UserInterface class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/app/user_interface.h"

#include "framework/common_defs.h"
#include "src/components/real_time_clock.h"
#include "src/drivers/lcd_display.h"

namespace Subsystems {

UserInterface* UserInterface::_instance = nullptr;

//----static-------------------------------------------------------------------
UserInterface* UserInterface::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void UserInterface::Init()
{
    CORE_INFO("Initializing UserInterface...");
    
    if (_instance != nullptr)
    {
        CORE_ERROR("UserInterface already initialized!");
        return;
    }

    _instance = new UserInterface();
    _instance->_stateTransitionDelay.Start(STATE_INTERVAL_MS);

    Drivers::LcdDisplay::Init();
}

//-----------------------------------------------------------------------------
void UserInterface::Update()
{
    CORE_INFO("Updating UserInterface...");

    // Handle state transitions
    if (_stateTransitionDelay.HasFinished())
    {
        _currentDisplayState = static_cast<DISPLAY_STATE>((_currentDisplayState + 1) % DISPLAY_STATE::_size);
    }

    Drivers::LcdDisplay* lcdDisplay = Drivers::LcdDisplay::GetInstance();

    // Title
    {
        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_1);
        lcdDisplay->Write(" --Guardian v2.0-- ");
    }
    
    // Wi-Fi
    {
        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_2);
        lcdDisplay->Write("Wi-Fi: OK");
    }

    // Time
    {
        auto dateTime = Components::RealTimeClock::GetInstance()->GetTime();
        lcdDisplay->SetCursor(12, DISPLAY_LINE::LINE_2);
        lcdDisplay->Write(dateTime.ToString().c_str());
    }

    if (_currentDisplayState == STATE_PAGE_1)
    {
        // Water quality
        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_3);
        lcdDisplay->Write("TDS: 342 ppm  [OK]  ");

        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_4);
        lcdDisplay->Write("Temp: 23.5 C  [HIGH]");
    }
    else if (_currentDisplayState == STATE_PAGE_2)
    {
        // Feeder status
        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_3);
        lcdDisplay->Write("Feeds left: 3       ");

        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_4);
        lcdDisplay->Write("Next: 12:00 (3)     ");
    }
    else
    {
        CORE_ERROR("Unknown Display state: [%d]", _currentDisplayState);
    }
}

} // namespace Subsystems
