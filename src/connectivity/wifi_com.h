/*!****************************************************************************
 * @file    wifi_com.h
 * @brief   WiFi connectivity wrapper (non-blocking state-machine).
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef WIFI_COM_H
#define WIFI_COM_H

#include "framework/common_defs.h"
#include <string>
#include <atomic>
#include "esp_event.h"
#include "esp_wifi.h"

namespace Connectivity {

class WiFiCom
{
    public:

        /*!
        * @brief Get the singleton instance of WiFiCom.
        * @return WiFiCom* Pointer to the WiFiCom instance.
        */
        static WiFiCom * GetInstance();

        /*!
        * @brief Initialize the WiFiCom.
        */
        static void Init();

        /*!
        * @brief Periodically poll/update (non-blocking)
        */
        void Update();

        /*!
        * @brief Check if connected to WiFi
        * @return true if connected, false otherwise
        */
        bool IsConnected() const;

        /*!
        * @brief Disconnect from WiFi
        */
        void Disconnect();

    private:

        enum class State 
        {
            INIT,
            CONNECTING,
            CONNECTED,
            DISCONNECTING,
            ERROR
        };

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

        static WiFiCom * _instance;
        State _state;
        std::string _ssid;
        std::string _password;
        std::atomic<bool> _got_ip;
        std::atomic<bool> _connected_flag;
        void* _netif; // forward-declare type to avoid exposing esp-netif here
    };
} // namespace Connectivity

#endif // WIFI_COM_H