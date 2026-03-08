/*!****************************************************************************
 * @file    wifi_com.h
 * @brief   WiFi connectivity wrapper (non-blocking state-machine).
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef WIFI_COM_H
#define WIFI_COM_H

#include "esp_event.h"
#include "esp_wifi.h"
#include "framework/common_defs.h"
#include "src/core/base/driver.h"
#include <atomic>
#include <string>

namespace Connectivity {

class WiFiCom : public Base::Singleton<WiFiCom>,
                public Base::Driver
{
    public:

        enum class State 
        {
            IDLE,
            INIT,
            CONNECTING,
            CONNECTED,
            DISCONNECTING,
            ERROR
        };

        /*!
        * @brief Check if connected to WiFi
        * @return true if connected, false otherwise
        */
        bool IsConnected() const;

        /*!
        * @brief Get the SSID of the currently connected AP.
        * @return SSID string when connected, empty string otherwise.
        */
        std::string GetSsid() const;

        /*!
        * @brief Get the RSSI (signal strength) of the current connection.
        * @return RSSI in dBm when connected, 0 otherwise.
        */
        int8_t GetRssi() const;

        /*!
        * @brief Start WiFi connection
        */
        void Start();

        /*!
        * @brief Disconnect from WiFi
        */
        void Disconnect();

        /*!
        * @brief Set WiFi credentials to use for connection.
        * @param ssid WiFi SSID
        * @param password WiFi password
        * Note: This does not trigger a reconnect. Call Start() after this to connect with new credentials.
        */
        void SetCredentials(const std::string& ssid, const std::string& password)
        {
            _ssid = ssid;
            _password = password;
        }

        /**
         * @brief Get the current state of the WiFiCom.
         * @return Current state as a State enum value.
         */
        State GetState() const { return _state; }

    protected:

        friend class Base::Singleton<WiFiCom>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "WiFiCom"; }

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
        void _Stop();
        
        /*! 
         * @brief Event handler for WiFi and IP events.
         * @param arg          User argument (not used).
         * @param event_base   Event base (WIFI_EVENT or IP_EVENT).
         * @param event_id     Event ID.
         * @param event_data   Pointer to event data.
        */
        static void EventHandler(
              void* arg
            , esp_event_base_t event_base
            , int32_t event_id
            , void* event_data
        );

        //---------------------------------------------

        WiFiCom();
        ~WiFiCom();
        WiFiCom(const WiFiCom&) = delete;
        WiFiCom& operator=(const WiFiCom&) = delete;

        //---------------------------------------------

        State _state;
        std::string _ssid;
        std::string _password;
        std::atomic<bool> _got_ip;
        std::atomic<bool> _connected;
        esp_netif_t* _netif; // forward-declare type to avoid exposing esp-netif here
    };

} // namespace Connectivity

#endif // WIFI_COM_H