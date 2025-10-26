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
#include <string>

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

            /*!
            * @brief Check if WiFi is connected.
            * @return true if connected, false otherwise.
            */
            bool IsWiFiConnected() const;

            /*!
            * @brief Check if MQTT client is connected.
            * @return true if connected, false otherwise.
            */
            bool IsMqttClientConnected() const;

        private:

            enum class State 
            {
                INIT,
                START_WIFI,
                WAITING_FOR_WIFI,
                START_TIME_SYNC,
                WAITING_FOR_TIME_SYNC,
                START_MQTT_CLIENT,
                WAITING_FOR_MQTT_CLIENT,
                SETUP_MQTT_CLIENT,
                IDLE,
                SEND_TELEMETRY,
                ERROR
            };

            /*!
            * @brief Updates the internal state of the NetworkController.
            * @param newState  The new state to transition to.
            */
            void ChangeState(const State newState);

            /*!
            * @brief Handle incoming RPC request payload.
            * @param payload   The RPC request payload.
            */
            void HandleRpcRequest(const std::string &payload);

            /*!
            * @brief Send telemetry data to the MQTT broker.
            */
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
            
            static constexpr const char* TELEMETRY_TOPIC = "v1/devices/me/telemetry";
            static constexpr const char* RPC_REQUEST_TOPIC = "v1/devices/me/rpc/request/+";

            //---------------------------------------------

            static NetworkController* _instance;
            bool _isTimeSynced;
            State _state;
            Delay _telemetrySendDelay;
    };

} // namespace Managers

#endif // NETWORK_CONTROLLER_H
