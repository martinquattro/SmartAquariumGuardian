/*!****************************************************************************
 * @file    ap_portal.h
 * @brief   Access Point (AP) Portal for WiFi credentials configuration.
 *          Provides a web interface for users to enter WiFi credentials.
 * @author  Quattrone Martin
 * @date    Feb 2026
 *******************************************************************************/

#ifndef AP_PORTAL_H
#define AP_PORTAL_H

#include "esp_http_server.h"
#include "esp_netif.h"
#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/core/base/driver.h"
#include <string>

namespace Connectivity {

class APPortal : public Base::Singleton<APPortal>,
                 public Base::Driver
{
    public:

        using Json = nlohmann::json;

        enum class State
        {
            IDLE,
            INIT,
            LISTENING_WIFI_CONFIG,
            WIFI_CREDENTIALS_RECEIVED,
            LISTENING_MQTT_CONFIG,
            MQTT_CREDENTIALS_RECEIVED,
            STOP,
            ERROR
        };

        /**
         * @brief Start the AP Portal. This will enable AP mode and start the HTTP server.
         */
        void Start();

        /**
         * @brief Stop the AP Portal. This will disable AP mode and stop the HTTP server.
         */
        void Stop();

        /*!
         * @brief Reset portal state to IDLE.
         *        Called by NetworkController after processing credentials.
         */
        void ResetState();

        /*!
         * @brief Get current portal state.
         * @return Current PortalState.
         */
        State GetState() const { return _state;};

        /*!
         * @brief Get received WiFi credentials.
         * @param ssid Output parameter for WiFi SSID.
         * @param password Output parameter for WiFi password.
         * @return Result indicating success or failure.
         */
        Result GetWifiCredentials(std::string& ssid, std::string& password) const;

        /*!
         * @brief Get received MQTT credentials.
         * @param broker Output parameter for MQTT broker address.
         * @param port Output parameter for MQTT port.
         * @param username Output parameter for MQTT username.
         * @param password Output parameter for MQTT password.
         * @return Result indicating success or failure.
         */
        Result GetMqttCredentials(std::string& broker, uint16_t& port, 
                                   std::string& username, std::string& password) const;

    protected:

        friend class Base::Singleton<APPortal>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "APPortal"; }

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

    private:

        auto _Start() -> State;
        auto _Stop() -> State;

        // HTTP Request Handlers
        static esp_err_t HandleGetRoot(httpd_req_t* req);
        static esp_err_t HandlePostCredentials(httpd_req_t* req);
        static esp_err_t HandlePostMqttCredentials(httpd_req_t* req);
        static esp_err_t HandleGetWifiNetworks(httpd_req_t* req);
        static esp_err_t HandleGetStatus(httpd_req_t* req);

        // Helper methods
        void SetupHttpServer();
        void StopHttpServer();
        void EnableAPMode();
        void DisableAPMode();

        //---------------------------------------------

        APPortal();
        ~APPortal();
        APPortal(const APPortal&) = delete;
        APPortal& operator=(const APPortal&) = delete;

        //---------------------------------------------

        static constexpr const char* AP_SSID = "SmartAquariumGuardian";
        static constexpr const char* AP_PASSWORD = "guardian2026";
        static constexpr const char* AP_IP = "192.168.4.1";
        static constexpr uint16_t HTTP_PORT = 80;

        //---------------------------------------------
        
        State _state;
        httpd_handle_t _httpServer;
        esp_netif_t* _netif; // forward-declare type to avoid exposing esp-netif here

        // Wi-Fi credentials
        std::string _configuredSsid;
        std::string _configuredPassword;

        // MQTT Broker credentials
        std::string _mqttBroker;
        uint16_t _mqttPort;
        std::string _mqttUsername;
        std::string _mqttPassword;
};

} // namespace Connectivity

#endif // AP_PORTAL_H