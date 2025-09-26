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

        static WiFiCom * GetInstance();

        static void Init();

        void Update();

        bool IsConnected() const;

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

        void _Start();
        void _Stop();
        
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