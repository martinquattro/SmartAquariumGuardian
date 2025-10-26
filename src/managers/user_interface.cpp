/*!****************************************************************************
 * @file    user_interface.cpp
 * @brief   Implementation of the UserInterface class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/user_interface.h"

#include "framework/common_defs.h"
#include "src/core/guardian_proxy.h"
#include "src/drivers/lcd_display.h"
#include "src/services/real_time_clock.h"

namespace Managers {

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

    Core::GuardianProxy* guardianProxy = Core::GuardianProxy::GetInstance();

    // Handle state transitions
    if (_stateTransitionDelay.HasFinished())
    {
        _currentDisplayState = static_cast<DISPLAY_STATE>((_currentDisplayState + 1) % DISPLAY_STATE::_size);
    }

    Drivers::LcdDisplay* lcdDisplay = Drivers::LcdDisplay::GetInstance();

    // Title
    {
        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_1);
        lcdDisplay->Write(" Smart Aquarium v2 ");
    }
    
    // Connection status
    {
        bool wifiOk = guardianProxy->IsWifiConnected();
        bool cloudOk = guardianProxy->IsMqttConnected();

        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_2);

        if (!wifiOk)
        {
            lcdDisplay->Write("WiFi: Offline   ");
        }
        else if (!cloudOk)
        {
            lcdDisplay->Write("Cloud: ERR     ");
        }
        else
        {
            lcdDisplay->Write("Online         ");
        }
    }

    // Time
    {
        auto dateTime = guardianProxy->GetDateTime();

        lcdDisplay->SetCursor(15, DISPLAY_LINE::LINE_2);
        lcdDisplay->Write(dateTime.ToString().c_str());
    }

    if (_currentDisplayState == STATE_PAGE_1)
    {
        // Water monitoring
        char buffer [50];

        // Tds reading
        const int tdsReading = guardianProxy->GetTdsReading();
        std::sprintf(buffer, "TDS: %03d ppm  [%s] ", tdsReading, "Ok");

        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_3);
        lcdDisplay->Write(buffer);

        // Temperature reading
        const float tempReading = guardianProxy->GetTemperatureReading();
        std::sprintf(buffer, "Temp: %02.2f C [%s] ", tempReading, "Off");

        lcdDisplay->SetCursor(0, DISPLAY_LINE::LINE_4);
        lcdDisplay->Write(buffer);

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

} // namespace Managers
