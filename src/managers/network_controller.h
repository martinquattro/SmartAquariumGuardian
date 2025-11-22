/*!****************************************************************************
 * @file    network_controller.h
 * @brief   NetworkController class header file.
 * @author  Quattrone Martin
 * @date    Sep 2025
 ******************************************************************************/

#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include "framework/util/delay.h"
#include "lib/nlohmann_json/json.hpp"
#include <functional>
#include <string>
#include <sys/time.h>
#include <unordered_map>
#include <map>
#include <memory>
#include "src/managers/cmd/rpc_handler.h"

namespace Managers {

    class NetworkController
    {
        public:

            using Json = nlohmann::json;

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
            * @brief Register RPC command handlers.
            */
            void RegisterRpcHandlers();

            /*!
            * @brief Updates the internal state of the NetworkController.
            * @param newState  The new state to transition to.
            */
            void ChangeState(const State newState);

            /*!
            * @brief Dispatch incoming MQTT messages to appropriate handlers.
            * @param topic     The topic of the incoming message.
            * @param payload   The payload of the incoming message.
            */
            void DispatchMqttMessage(const std::string& topic, const std::string& payload);

            /*!
            * @brief Handle incoming RPC request payload.
            * @param topic     The RPC request topic.
            * @param payload   The RPC request payload.
            */
            void DispatchRpcRequest(const std::string& topic, const std::string &payload);

            /*!
            * @brief Handle incoming Attributes request payload.
            * @param payload   The Attributes request payload.
            */
            void DispatchAttributesRequest(const std::string &payload);

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

            /*!
            * @brief Extracts the request ID from the RPC request URL.
            * @param url   The RPC request URL.
            * @return int  The extracted request ID.
            */
            int ExtractRequestId(const std::string& url);

            //---------------------------------------------
            
            static constexpr const char* TELEMETRY_TOPIC    = "v1/devices/me/telemetry";
            static constexpr const char* RPC_REQUEST_TOPIC  = "v1/devices/me/rpc/request/+";
            static constexpr const char* RPC_RESPONSE_TOPIC = "v1/devices/me/rpc/response/";
            static constexpr const char* ATTRIBUTES_TOPIC   = "v1/devices/me/attributes";

            //---------------------------------------------

            static NetworkController* _instance;
            bool _isTimeSynced;
            State _state;
            Delay _telemetrySendDelay;
            std::map<std::string, std::unique_ptr<Handlers::IRpcHandler>> _rpcHandlers;
    };

} // namespace Managers

#endif // NETWORK_CONTROLLER_H
