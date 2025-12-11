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

            static constexpr int STATE_INTERVAL_MS = 4000;

            enum DISPLAY_STATE
            {
                STATE_PAGE_1,
                STATE_PAGE_2,
                _size
            };

            enum DISPLAY_LINE
            {
                LINE_1 = 0,
                LINE_2 = 1,
                LINE_3 = 2,
                LINE_4 = 3
            };

            //---------------------------------------------

            UserInterface() {}
            ~UserInterface() = default;
            UserInterface(const UserInterface&) = delete;
            UserInterface& operator=(const UserInterface&) = delete;

            //---------------------------------------------

            static UserInterface* _instance;
            Delay _stateTransitionDelay;
            DISPLAY_STATE _currentDisplayState = STATE_PAGE_1;
    };

} // namespace Managers

#endif // USER_INTERFACE_H
