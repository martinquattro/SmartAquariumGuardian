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

    Drivers::GraphicDisplay::GetInstance()->SetOnDoubleClickAction([]()
        {
            Core::GuardianProxy::GetInstance()->Feed(1);
        }
    );
    
    // Initialize UI elements
    _instance->_time = new Drivers::GraphicDisplay::UIElement(ui_lblTime);

    _instance->_wifiIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgWiFiOff);
    _instance->_wifiIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgWifiOn);

    _instance->_cloudIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOff);
    _instance->_cloudIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOn);

    _instance->_tdsValue = new Drivers::GraphicDisplay::UIElement(ui_lblTdsValue);

    _instance->_tempValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempValue);
    _instance->_tempMaxValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMax);
    _instance->_tempMinValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMin);
    _instance->_tempPanel = new Drivers::GraphicDisplay::UIElement(ui_panelTempAlert);

    _instance->_feederPanel = new Drivers::GraphicDisplay::UIElement(ui_panelFeeder);
    _instance->_nextFeedingTime = new Drivers::GraphicDisplay::UIElement(ui_lblNextFeedTime);
    _instance->_dosesPerDay = new Drivers::GraphicDisplay::UIElement(ui_lblDosesPerDay);
    _instance->_dosesLeft = new Drivers::GraphicDisplay::UIElement(ui_lblDosesLeft);
}

//-----------------------------------------------------------------------------
void UserInterface::Update()
{
    CORE_INFO("Updating UserInterface...");

    Core::GuardianProxy* guardianProxy = Core::GuardianProxy::GetInstance();

    // Power status
    {
        const auto powerMode = guardianProxy->GetCurrentMode();
        const auto batteryLevel = guardianProxy->GetBatteryLevel();

        CORE_INFO("Power Mode: %s, Battery Level: %d%",
                  powerMode == Services::PowerController::Mode::MODE_USB_POWERED ? "USB Powered" : "Battery Powered",
                  static_cast<int>(batteryLevel)
        );
    }

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
        Utils::DateTime dateTime;
        if (guardianProxy->GetDateTime(dateTime))
        {
            _time->SetText(dateTime.ToString().c_str());
        }
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
            std::sprintf(buffer, "%.1f °C", minTemp);
        }
        else
        {
            std::sprintf(buffer, "---"); 
        }
        
        _instance->_tempMinValue->SetText(buffer);

        if (isMaxLimitEnabled)
        {
            std::sprintf(buffer, "%.1f °C", maxTemp);
        }
        else
        {
            std::sprintf(buffer, "---"); 
        }

        _instance->_tempMaxValue->SetText(buffer);

        // Panel state
        if (guardianProxy->IsTemperatureOutOfLimits())
        {
            // Alert state
            _instance->_tempPanel->SetState1();
        }
        else
        {
            // Normal state
            _instance->_tempPanel->ClearState1();
        }
    }

    // TDS reading
    {
        char buffer [50];

        const int tdsReading = guardianProxy->GetTdsReading();
        std::sprintf(buffer, "%d", tdsReading);

        _instance->_tdsValue->SetText(buffer);
    }

    // Feeder
    {
        const auto& feederStatus = guardianProxy->GetFeederStatus();

        // Next feeding time
        char buffer [50];

        if (feederStatus.remainingDosesToday > 0)
        {
            std::sprintf(buffer, "%s [%d]", feederStatus.nextFeedTime.ToString().c_str(), feederStatus.nextFeedDoses);
        }
        else
        {
            std::sprintf(buffer, "Tomorrow");
        }

        _instance->_nextFeedingTime->SetText(buffer);

        // Doses per day
        std::sprintf(buffer, "%d", feederStatus.totalPerDay);
        _instance->_dosesPerDay->SetText(buffer);

        // Doses left today
        std::sprintf(buffer, "%d", feederStatus.remainingDosesToday);
        _instance->_dosesLeft->SetText(buffer);
    }
}

//-----------------------------------------------------------------------------
void UserInterface::UpdateFeedingStatusIndicator(bool isFeeding)
{
    CORE_INFO("Updating feeding status indicator to %s", isFeeding ? "ON" : "OFF");

    if (isFeeding)
    {
        _instance->_feederPanel->SetState1();
    }
    else
    {
        _instance->_feederPanel->ClearState1();
    }
}

} // namespace Managers
