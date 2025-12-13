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

    // Create UI elements
    Drivers::GraphicDisplay* display = Drivers::GraphicDisplay::GetInstance();

    // Header elements
    {
        // Separator line
        int centerY = 25;
        _instance->_headerLine = display->CreateLine(0, centerY, Drivers::GraphicDisplay::DISP_H_RES, centerY, Drivers::GraphicDisplay::ElementColor::GREY, 2);

        // Time
        _instance->_time = display->CreateTextElement(LV_ALIGN_TOP_LEFT, 0, 0, "", Drivers::GraphicDisplay::FontSize::SMALL);
        _instance->_time->SetBold(true);

        // Title label
        _instance->_titleLabel = display->CreateTextElement(LV_ALIGN_TOP_MID, 0, 0, "Guardian v2.0", Drivers::GraphicDisplay::FontSize::SMALL);

        // Icons
        _instance->_cloudIcon = display->CreateTextElement(LV_ALIGN_TOP_RIGHT, 0, 0, LV_SYMBOL_REFRESH, Drivers::GraphicDisplay::FontSize::SMALL);
        _instance->_cloudIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::CRITICAL);
        
        _instance->_wifiIcon = display->CreateTextElement(LV_ALIGN_TOP_RIGHT, -20, 0, LV_SYMBOL_WIFI, Drivers::GraphicDisplay::FontSize::SMALL);
        _instance->_wifiIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::CRITICAL);
    }
    
    // Main pages elements
    {
        int circleDiameter = 136;
        int circleThickness = 8;
        int circleXOffset = (Drivers::GraphicDisplay::DISP_H_RES / 4);
        int circleYOffset = 0;

        // Temperature circle and labels
        _instance->_tempCircle = display->CreateRing(LV_ALIGN_CENTER, -circleXOffset, circleYOffset, circleDiameter, circleThickness, Drivers::GraphicDisplay::ElementColor::GREEN);

        _instance->_tempDescLabel = display->CreateTextElement(LV_ALIGN_CENTER, -circleXOffset, circleYOffset + circleDiameter / 2 + 20 , "Temperature", Drivers::GraphicDisplay::FontSize::SMALL);

        _instance->_tempValue = display->CreateTextElement(LV_ALIGN_CENTER, -circleXOffset, circleYOffset, "", Drivers::GraphicDisplay::FontSize::LARGE);
        _instance->_tempValue->SetBold(true);

        //TDS circle and labels
        _instance->_tdsCircle = display->CreateRing(LV_ALIGN_CENTER, circleXOffset, circleYOffset, circleDiameter, circleThickness, Drivers::GraphicDisplay::ElementColor::GREEN);

        _instance->_tdsDescLabel = display->CreateTextElement(LV_ALIGN_CENTER, circleXOffset, circleYOffset + circleDiameter / 2 + 20 , "TDS", Drivers::GraphicDisplay::FontSize::SMALL);

        _instance->_tdsValue = display->CreateTextElement(LV_ALIGN_CENTER, circleXOffset, circleYOffset, "", Drivers::GraphicDisplay::FontSize::LARGE);
        _instance->_tdsValue->SetBold(true);
    }
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
        // No need to update title for now
    }
    
    // Connection status
    {
        bool wifiOk = guardianProxy->IsWifiConnected();
        bool cloudOk = guardianProxy->IsMqttConnected();

        if (!wifiOk)
        {
            _instance->_wifiIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::CRITICAL);
            _instance->_cloudIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::CRITICAL);
        }
        else if (!cloudOk)
        {
            _instance->_wifiIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::OK);
            _instance->_cloudIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::CRITICAL);
        }
        else
        {
            _instance->_wifiIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::OK);
            _instance->_cloudIcon->SetStatus(Drivers::GraphicDisplay::ElementStatus::OK);
        }
    }

    // Time
    {
        auto dateTime = guardianProxy->GetDateTime();
        _time->SetText(dateTime.ToString().c_str());
    }
    

    if (_currentDisplayState == STATE_PAGE_1)
    {
        char buffer [50];

        // Temperature reading
        const float tempReading = guardianProxy->GetTemperatureReading();
        std::sprintf(buffer, "%02.1f °C", tempReading);

        _instance->_tempValue->SetText(buffer);

        // TDS reading
        const int tdsReading = guardianProxy->GetTdsReading();
        std::sprintf(buffer, "%d ppm", tdsReading);

        _instance->_tdsValue->SetText(buffer);

        _tempCircle->Show();
        _tempDescLabel->Show();
        _tempValue->Show();

        _tdsCircle->Show();
        _tdsDescLabel->Show();
        _tdsValue->Show();
    }
    else if (_currentDisplayState == STATE_PAGE_2)
    {

        _tempCircle->Hide();
        _tempDescLabel->Hide();
        _tempValue->Hide();

        _tdsCircle->Hide();
        _tdsDescLabel->Hide();
        _tdsValue->Hide();
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
