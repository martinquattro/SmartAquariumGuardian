/*!****************************************************************************
 * @file    network_controller.h
 * @brief   NetworkController class header file.
 * @author  Quattrone Martin
 * @date    Sep 2025
 ******************************************************************************/

#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include <sys/time.h>
#include "framework/util/delay.h"

namespace Managers {

    class NetworkController
    {
        public:
        
            /*!
            * @brief Gets the singleton instance of the NetworkController.
            * @return NetworkController* Pointer to the NetworkController instance.
            */
            static NetworkController* GetInstance();

            /*!
            * @brief Initializes the NetworkController.
            */
            static void Init();

            /*!
            * @brief Updates the NetworkController state.
            */
            void Update();

        private:

            enum class State 
            {
                INIT,
                WAITING_FOR_WIFI,
                IDLE,
                SEND_TELEMETRY,
                INIT_TIME_SYNC,
                WAITING_FOR_TIME_SYNC,
                ERROR
            };

            /*
            * @brief Updates the internal state of the NetworkController.
            * @param newState  The new state to transition to.
            */
            void ChangeState(const State newState);

            // TODO
            void SendTelemtry();

            /*
            * @brief Initializes the time synchronization process.
            */
            void TimeSyncInit();
            
            /*! @brief Callback function for time synchronization.
            * @param tv    Pointer to timeval structure with the synchronized time.
            */
            static void TimeSyncCallback(struct ::timeval *tv);

            NetworkController(){}
            ~NetworkController() = default;
            NetworkController(const NetworkController&) = delete;
            NetworkController& operator=(const NetworkController&) = delete;

            //---------------------------------------------

            static NetworkController* _instance;
            bool _isTimeSynced;
            State _state;
            Delay _telemetrySendDelay;
    };

} // namespace Managers

#endif // NETWORK_CONTROLLER_H
