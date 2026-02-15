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

//----protected----------------------------------------------------------------
bool UserInterface::OnInit()
{
    _display = Drivers::GraphicDisplay::GetInstance();
    _display->Init();

    _display->SetOnDoubleClickAction([this]()
        {
            Core::GuardianProxy::GetInstance()->Feed(1);
        }
    );

    _display->SetOnLongPressAction([this]()
        {
            Core::GuardianProxy::GetInstance()->ActivateApMode();
        }
    );

    _display->SetBrightness(80);
    
    // Initialize UI elements
    _time = new Drivers::GraphicDisplay::UIElement(ui_lblTime);

    _batteryFullIcon = new Drivers::GraphicDisplay::UIElement(ui_imgBatteryFull);
    _batteryHighIcon = new Drivers::GraphicDisplay::UIElement(ui_imgBatteryHigh);
    _batteryMediumIcon = new Drivers::GraphicDisplay::UIElement(ui_imgBatteryMedium);
    _batteryLowIcon = new Drivers::GraphicDisplay::UIElement(ui_imgBatteryLow);
    _batteryCriticalIcon = new Drivers::GraphicDisplay::UIElement(ui_imgBatteryCritical);

    _wifiIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgWiFiOff);
    _wifiIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgWifiOn);

    _cloudIconOff = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOff);
    _cloudIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgCloudOn);

    _apIconOn = new Drivers::GraphicDisplay::UIElement(ui_imgAPActive);

    _tdsValue = new Drivers::GraphicDisplay::UIElement(ui_lblTdsValue);

    _tempValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempValue);
    _tempMaxValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMax);
    _tempMinValue = new Drivers::GraphicDisplay::UIElement(ui_lblTempLimitMin);
    _tempPanel = new Drivers::GraphicDisplay::UIElement(ui_panelTempAlert);

    _feederPanel = new Drivers::GraphicDisplay::UIElement(ui_panelFeeder);
    _nextFeedingTime = new Drivers::GraphicDisplay::UIElement(ui_lblNextFeedTime);
    _dosesPerDay = new Drivers::GraphicDisplay::UIElement(ui_lblDosesPerDay);
    _dosesLeft = new Drivers::GraphicDisplay::UIElement(ui_lblDosesLeft);

    return true;
}

//----protected----------------------------------------------------------------
void UserInterface::OnUpdate()
{
    // Power status
    {
        UpdatePowerIndicator();
    }

    // Connection status
    {
        bool wifiOk = Core::GuardianProxy::GetInstance()->IsWifiConnected();
        bool cloudOk = Core::GuardianProxy::GetInstance()->IsMqttConnected();
        bool apPortalOk = Core::GuardianProxy::GetInstance()->IsApPortalActive();

        if (!wifiOk)
        {   
            if (apPortalOk)
            {
                _apIconOn->Show();
                _wifiIconOff->Hide();
                _wifiIconOn->Hide();
                _cloudIconOff->Hide();
                _cloudIconOn->Hide();
            }
            else
            {
                _apIconOn->Hide();
                _wifiIconOff->Show();
                _wifiIconOn->Hide();
                _cloudIconOff->Show();
                _cloudIconOn->Hide();
            }
        }
        else if (!cloudOk)
        {
            _apIconOn->Hide();
            _wifiIconOff->Hide();
            _wifiIconOn->Show();
            _cloudIconOff->Show();
            _cloudIconOn->Hide();
        }
        else
        {
            _apIconOn->Hide();
            _wifiIconOff->Hide();
            _wifiIconOn->Show();
            _cloudIconOff->Hide();
            _cloudIconOn->Show();
        }
    }

    // Time
    {
        Utils::DateTime dateTime;
        if (Core::GuardianProxy::GetInstance()->GetDateTime(dateTime))
        {
            _time->SetText(dateTime.ToString().c_str());
        }
    }

    // Temperature Panel
    {
        char buffer [50];

        const float tempReading = Core::GuardianProxy::GetInstance()->GetTemperatureReading();
        std::sprintf(buffer, "%.1f", tempReading);

        _tempValue->SetText(buffer);

        // Temperature limits
        float minTemp = 0.0f, maxTemp = 0.0f;
        bool isMinLimitEnabled = false, isMaxLimitEnabled = false;

        Core::GuardianProxy::GetInstance()->GetTemperatureLimits(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);

        if (isMinLimitEnabled)
        {
            std::sprintf(buffer, "%.1f °C", minTemp);
        }
        else
        {
            std::sprintf(buffer, "---"); 
        }
        
        _tempMinValue->SetText(buffer);

        if (isMaxLimitEnabled)
        {
            std::sprintf(buffer, "%.1f °C", maxTemp);
        }
        else
        {
            std::sprintf(buffer, "---"); 
        }

        _tempMaxValue->SetText(buffer);

        // Panel state
        if (Core::GuardianProxy::GetInstance()->IsTemperatureOutOfLimits())
        {
            // Alert state
            _tempPanel->SetState1();
        }
        else
        {
            // Normal state
            _tempPanel->ClearState1();
        }
    }

    // TDS reading
    {
        char buffer [50];

        const int tdsReading = Core::GuardianProxy::GetInstance()->GetTdsReading();
        std::sprintf(buffer, "%d", tdsReading);

        _tdsValue->SetText(buffer);
    }

    // Feeder
    {
        const auto& feederStatus = Core::GuardianProxy::GetInstance()->GetFeederStatus();

        CORE_INFO("Feeder Status - Next Feed Time: %s, Next Feed Doses: %d, Remaining Doses Today: %d, Total Per Day: %d",
                  feederStatus.nextFeedTime.ToString().c_str(),
                  feederStatus.nextFeedDoses,
                  feederStatus.remainingDosesToday,
                  feederStatus.totalPerDay
        );

        // Next feeding time
        char buffer [50];

        if (feederStatus.remainingDosesToday > 0)
        {
            std::sprintf(buffer, "%s [%d]", feederStatus.nextFeedTime.ToString().c_str(), feederStatus.nextFeedDoses);
        }
        else if (feederStatus.totalPerDay > 0)
        {
            std::sprintf(buffer, "Tomorrow");
        }
        else
        {
            std::sprintf(buffer, "---");
        }

        _nextFeedingTime->SetText(buffer);

        // Doses per day
        std::sprintf(buffer, "%d", feederStatus.totalPerDay);
        _dosesPerDay->SetText(buffer);

        // Doses left today
        std::sprintf(buffer, "%d", feederStatus.remainingDosesToday);
        _dosesLeft->SetText(buffer);
    }
}

//----protected----------------------------------------------------------------
void UserInterface::OnBatteryModeEnter()
{
    _display->SetBrightness(DISPLAY_BRIGHTNESS_BATTERY_MODE); // Dim the display for battery mode
}

//----protected----------------------------------------------------------------
void UserInterface::OnBatteryModeExit()
{
    _display->SetBrightness(DISPLAY_BRIGHTNESS_NORMAL_MODE); // Restore brightness for normal mode
}

//----private------------------------------------------------------------------
void UserInterface::UpdatePowerIndicator()
{
    static Services::PowerController::BatteryLevel lastBatteryLevel = Services::PowerController::BatteryLevel::_size;
    static Services::PowerController::Mode lastPowerMode = Services::PowerController::Mode::_size;

    const auto powerMode = Core::GuardianProxy::GetInstance()->GetCurrentMode();
    const auto batteryLevel = Core::GuardianProxy::GetInstance()->GetBatteryLevel();

    if (lastBatteryLevel != batteryLevel || lastPowerMode != powerMode)
    {
        lastBatteryLevel = batteryLevel;
        lastPowerMode = powerMode;

        _batteryFullIcon->Hide();
        _batteryHighIcon->Hide();
        _batteryMediumIcon->Hide();
        _batteryLowIcon->Hide();
        _batteryCriticalIcon->Hide();

        if (powerMode == Services::PowerController::Mode::MODE_BATTERY_POWERED)
        {
            switch (batteryLevel)
            {
                case Services::PowerController::BatteryLevel::LEVEL_FULL:               _batteryFullIcon->Show();                  break;
                case Services::PowerController::BatteryLevel::LEVEL_HIGH:               _batteryHighIcon->Show();                  break;
                case Services::PowerController::BatteryLevel::LEVEL_MEDIUM:             _batteryMediumIcon->Show();                break;
                case Services::PowerController::BatteryLevel::LEVEL_LOW:                _batteryLowIcon->Show();                   break;
                case Services::PowerController::BatteryLevel::LEVEL_CRITICAL:           _batteryCriticalIcon->Show();              break;
                default:                                                                                                           break;
            }
        }
    }
}

//-----------------------------------------------------------------------------
void UserInterface::UpdateFeedingStatusIndicator(bool isFeeding)
{
    CORE_INFO("Updating feeding status indicator to %s", isFeeding ? "ON" : "OFF");

    if (isFeeding)
    {
        _feederPanel->SetState1();
    }
    else
    {
        _feederPanel->ClearState1();
    }
}

} // namespace Managers
