/*!****************************************************************************
 * @file    network_controller.h
 * @brief   NetworkController class header file.
 * @author  Quattrone Martin
 * @date    Sep 2025
 ******************************************************************************/

#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include "framework/common_defs.h"
#include "framework/util/delay.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/core/base/manager.h"
#include "src/managers/comms/rpc_handler.h"
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

namespace Connectivity { class WiFiCom; }
namespace Connectivity { class MqttClient; }
namespace Connectivity { class APPortal; }

namespace Managers {

class NetworkController : public Base::Singleton<NetworkController>
                        , public Base::Manager
{
    public:

        using Json = nlohmann::json;

        /*!
        * @brief Activate AP mode for configuration.
        * @note This will destroy the existing WiFi station connection if active and start the AP portal.
        */
        void ActivateApMode();

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

        /*!
        * @brief Check if AP Portal is active.
        * @return true if AP Portal is active, false otherwise.
        */
        bool IsApPortalActive() const;

        /*!
        * @brief Sync device with server.
        * @return Result indicating success or failure.
        */
        Result SyncDevice();

    protected:

        friend class Base::Singleton<NetworkController>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "NetworkController"; }

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
        * @brief Updates what is necessary when entering battery mode
        */
        void OnBatteryModeEnter() override;

        /*!
        * @brief Updates what is necessary when exiting battery mode
        */
        void OnBatteryModeExit() override;

    private:

        enum class State 
        {
            INIT,
            PRE_START_WIFI,
            START_WIFI,
            WAITING_FOR_WIFI,
            START_TIME_SYNC,
            WAITING_FOR_TIME_SYNC,
            START_MQTT_CLIENT,
            WAITING_FOR_MQTT_CLIENT,
            SETUP_MQTT_CLIENT,
            IDLE,
            SEND_TELEMETRY,
            PRE_START_ACCESS_POINT,
            START_ACCESS_POINT,
            WAITING_FOR_ACCESS_POINT,
            STOP,
            NO_CONNECTIONS,
            ERROR
        };

        /*!
        * @brief Register RPC command handlers.
        */
        void RegisterRpcHandlers();

        /*!
        * @brief Updates the internal state of the NetworkController.
        * @param newState  The new state to transition to.
        * @param delayMs   Optional delay in milliseconds before the state transition takes effect.
         * Note: This method also starts the internal delay timer if a delay is specified.
         *       The OnUpdate() method will check this timer and perform the state transition when the delay has elapsed.
         *       This allows for non-blocking delays between state transitions.
        */
        void ChangeState(const State newState, const int delayMs = -1);

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

        /*!
        * @brief Publish device config as Client Attributes to ThingsBoard.
        *        Called on MQTT connect and after config-changing RPCs.
        *        Enables Device-led Source of Truth (dashboard reads CLIENT_SCOPE).
        * @return Result indicating success or failure.
        */
        Result SendClientAttributes();

        /*!
        * @brief Extracts the request ID from the RPC request URL.
        * @param url   The RPC request URL.
        * @return int  The extracted request ID.
        */
        int ExtractRequestId(const std::string& url);

        //---------------------------------------------

        NetworkController(){}
        ~NetworkController() = default;
        NetworkController(const NetworkController&) = delete;
        NetworkController& operator=(const NetworkController&) = delete;

        //---------------------------------------------
        
        static constexpr const char* TELEMETRY_TOPIC    = "v1/devices/me/telemetry";
        static constexpr const char* RPC_REQUEST_TOPIC  = "v1/devices/me/rpc/request/+";
        static constexpr const char* RPC_RESPONSE_TOPIC = "v1/devices/me/rpc/response/";
        static constexpr const char* ATTRIBUTES_TOPIC   = "v1/devices/me/attributes";

        static constexpr uint32_t WIFI_CONNECTION_TIMEOUT_MS = 5000;    //!< 5 seconds
        static constexpr uint32_t TIME_SYNC_TIMEOUT_MS = 10000;         //!< 10 seconds
        static constexpr uint32_t MQTT_CLIENT_TIMEOUT_MS = 10000;       //!< 10 seconds

        //---------------------------------------------

        Connectivity::WiFiCom* _wifiCom;
        Connectivity::MqttClient* _mqttClient;
        Connectivity::APPortal* _apPortal;

        State _state;
        Delay _telemetrySendDelay;
        Delay _delayTimeout;
        std::map<std::string, std::unique_ptr<Handlers::IRpcHandler>> _rpcHandlers;
        
};

} // namespace Managers

#endif // NETWORK_CONTROLLER_H
