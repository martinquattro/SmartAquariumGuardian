/*!****************************************************************************
 * @file    user_interface.h
 * @brief   UserInterface class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "framework/util/delay.h"
#include "include/config.h"
#include "src/drivers/graphic_display.h"
#include "src/core/base/manager.h"

namespace Managers {

class UserInterface : public Base::Singleton<UserInterface>
                    , public Base::Manager
{
    public:

        /*!
        * @brief Update feeding status indicator
        * @param isFeeding True if feeding is in progress, false otherwise.
        */
        void UpdateFeedingStatusIndicator(bool isFeeding);

    private:

        friend class Base::Singleton<UserInterface>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "UserInterface"; }

        /*!
         * @brief Initializes the Module.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override;

        /*!
         * @brief Updates the Module state.
         *        This method should be called periodically to update the system state.
         */
        void OnUpdate() override;

        /*!
        * @brief Update power status indicator
        */
        void UpdatePowerIndicator();

        //---------------------------------------------

        UserInterface() {}
        ~UserInterface() = default;
        UserInterface(const UserInterface&) = delete;
        UserInterface& operator=(const UserInterface&) = delete;

        //---------------------------------------------

        Drivers::GraphicDisplay* _display = nullptr;

        Drivers::GraphicDisplay::UIElement* _batteryFullIcon;
        Drivers::GraphicDisplay::UIElement* _batteryHighIcon;
        Drivers::GraphicDisplay::UIElement* _batteryMediumIcon;
        Drivers::GraphicDisplay::UIElement* _batteryLowIcon;
        Drivers::GraphicDisplay::UIElement* _batteryCriticalIcon;

        Drivers::GraphicDisplay::UIElement* _tempValue;
        Drivers::GraphicDisplay::UIElement* _tempMinValue;
        Drivers::GraphicDisplay::UIElement* _tempMaxValue;
        Drivers::GraphicDisplay::UIElement* _tempPanel;

        Drivers::GraphicDisplay::UIElement* _tdsValue;
        Drivers::GraphicDisplay::UIElement* _tdsMinValue;

        Drivers::GraphicDisplay::UIElement* _wifiIconOn;
        Drivers::GraphicDisplay::UIElement* _wifiIconOff;

        Drivers::GraphicDisplay::UIElement* _cloudIconOn;
        Drivers::GraphicDisplay::UIElement* _cloudIconOff;

        Drivers::GraphicDisplay::UIElement* _apIconOn;

        Drivers::GraphicDisplay::UIElement* _time;

        Drivers::GraphicDisplay::UIElement* _feederPanel;
        Drivers::GraphicDisplay::UIElement* _nextFeedingTime;
        Drivers::GraphicDisplay::UIElement* _dosesPerDay;
        Drivers::GraphicDisplay::UIElement* _dosesLeft;
};

} // namespace Managers

#endif // USER_INTERFACE_H
