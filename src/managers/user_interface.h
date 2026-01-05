/*!****************************************************************************
 * @file    user_interface.h
 * @brief   UserInterface class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "framework/util/delay.h"
#include "src/drivers/led.h"
#include "include/config.h"
#include "src/drivers/graphic_display.h"

namespace Managers {

    class UserInterface 
    {
        public:

            /*!
            * @brief Gets the singleton instance of the UserInterface.
            * @return UserInterface* Pointer to the UserInterface instance.
            */
            static UserInterface* GetInstance();

            /*!
            * @brief Initializes the UserInterface.
            */
            static void Init();

            /*!
            * @brief Updates the UserInterface readings.
            */
            void Update();

            /*!
            * @brief Update feeding status indicator
            * @param isFeeding True if feeding is in progress, false otherwise.
            */
            void UpdateFeedingStatusIndicator(bool isFeeding);

        private:

            //---------------------------------------------

            UserInterface() {}
            ~UserInterface() = default;
            UserInterface(const UserInterface&) = delete;
            UserInterface& operator=(const UserInterface&) = delete;

            //---------------------------------------------

            static UserInterface* _instance;

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

            Drivers::GraphicDisplay::UIElement* _time;
    };

} // namespace Managers

#endif // USER_INTERFACE_H
