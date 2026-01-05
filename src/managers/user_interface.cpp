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
#include "ui/ui.h"

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

    // Initialize Graphic Display
    Drivers::GraphicDisplay::Init();
    
    // Initialize UI elements
    _instance->_time = new Drivers::GraphicDisplay::UIElement(ui_lblTime);
    _instance->_tempValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempValue);
    _instance->_wifiIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgWiFiOff);
    _instance->_wifiIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgWifiOn);
    _instance->_cloudIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOff);
    _instance->_cloudIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOn);
    _instance->_tdsValue = new Drivers::GraphicDisplay::UIElement(ui_lblTdsValue);
    _instance->_tempMaxValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMin);
    _instance->_tempMinValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMax);
}

//-----------------------------------------------------------------------------
void UserInterface::Update()
{
    CORE_INFO("Updating UserInterface...");

    Core::GuardianProxy* guardianProxy = Core::GuardianProxy::GetInstance();

    // Connection status
    {
        bool wifiOk = guardianProxy->IsWifiConnected();
        bool cloudOk = guardianProxy->IsMqttConnected();

        if (!wifiOk)
        {   
            _instance->_wifiIconOff->Show();
            _instance->_wifiIconOn->Hide();
            _instance->_cloudIconOff->Show();
            _instance->_cloudIconOn->Hide();
        }
        else if (!cloudOk)
        {
            _instance->_wifiIconOff->Hide();
            _instance->_wifiIconOn->Show();
            _instance->_cloudIconOff->Show();
            _instance->_cloudIconOn->Hide();
        }
        else
        {
            _instance->_wifiIconOff->Hide();
            _instance->_wifiIconOn->Show();
            _instance->_cloudIconOff->Hide();
            _instance->_cloudIconOn->Show();
        }
    }

    // Time
    {
        auto dateTime = guardianProxy->GetDateTime();
        _time->SetText(dateTime.ToString().c_str());
    }

    // Temperature Panel
    {
        char buffer [50];

        const float tempReading = guardianProxy->GetTemperatureReading();
        std::sprintf(buffer, "%.1f", tempReading);

        _instance->_tempValue->SetText(buffer);

        // Temperature limits
        float minTemp = 0.0f, maxTemp = 0.0f;
        bool isMinLimitEnabled = false, isMaxLimitEnabled = false;

        guardianProxy->GetTemperatureLimits(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

        if (isMinLimitEnabled)
        {
            std::sprintf(buffer, "%.1f", minTemp);
        }
        else
        {
            std::sprintf(buffer, "--"); 
        }
        
        _instance->_tempMinValue->SetText(buffer);

        if (isMaxLimitEnabled)
        {
            std::sprintf(buffer, "%.1f", maxTemp);
        }
        else
        {
            std::sprintf(buffer, "--"); 
        }

        _instance->_tempMaxValue->SetText(buffer);
    }

    // TDS reading
    {
        char buffer [50];

        const int tdsReading = guardianProxy->GetTdsReading();
        std::sprintf(buffer, "%d", tdsReading);

        _instance->_tdsValue->SetText(buffer);
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
