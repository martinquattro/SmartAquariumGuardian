/*!****************************************************************************
 * @file    user_interface.cpp
 * @brief   Implementation of the UserInterface class
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/managers/user_interface.h"

#include "framework/common_defs.h"
#include "src/core/guardian_proxy.h"
#include "src/drivers/graphic_display.h"
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

    Drivers::GraphicDisplay::Init();
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

    // Title
    {

    }
    
    // Connection status
    {
        bool wifiOk = guardianProxy->IsWifiConnected();
        bool cloudOk = guardianProxy->IsMqttConnected();

        if (!wifiOk)
        {
        }
        else if (!cloudOk)
        {
        }
        else
        {
        }
    }

    // Time
    {
        auto dateTime = guardianProxy->GetDateTime();


    }

    if (_currentDisplayState == STATE_PAGE_1)
    {
        // Water monitoring
        char buffer [50];

        // Tds reading
        const int tdsReading = guardianProxy->GetTdsReading();
        std::sprintf(buffer, "TDS: %03d ppm  [%s] ", tdsReading, "Ok");


        // Temperature reading
        const float tempReading = guardianProxy->GetTemperatureReading();
        std::sprintf(buffer, "Temp: %02.2f C [%s] ", tempReading, "Off");


    }
    else if (_currentDisplayState == STATE_PAGE_2)
    {

    }
    else
    {
        CORE_ERROR("Unknown Display state: [%d]", _currentDisplayState);
    }
}

//-----------------------------------------------------------------------------
void UserInterface::UpdateFeedingStatusIndicator(bool isFeeding)
{
    CORE_INFO("Updating feeding status indicator to %s", isFeeding ? "ON" : "OFF");

    // if (isFeeding)
    // {
    //     _feedingStatusLed.TurnOn();
    // }
    // else
    // {
    //     _feedingStatusLed.TurnOff();
    // }
}

} // namespace Managers
