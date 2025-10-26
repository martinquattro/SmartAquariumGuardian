/*!****************************************************************************
 * @file    mqtt_client.h
 * @brief   MQTT client wrapper (esp-mqtt) with simple Publish/Subscribe API.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include "framework/common_defs.h"
#include <mqtt_client.h>
#include <atomic>
#include <functional>
#include <string>

namespace Connectivity {

class MqttClient
{
    public:

        using MessageCallback = std::function<void(const std::string &topic, const std::string &payload)>;

        /*!
        * @brief Get the singleton instance of MqttClient.
        * @return MqttClient* Pointer to the MqttClient instance.
        */
        static MqttClient * GetInstance();

        /*!
        * @brief Initialize the MqttClient. Must be called after WiFi is connected.
        */
        static void Init();

        /*!
        * @brief Periodically poll/update (non-blocking)
        */
        void Update();

        /*!
        * @brief Check if connected to the MQTT broker
        * @return true if connected, false otherwise
        */
        bool IsConnected() const;

        /*!
        * @brief Start MQTT connection
        */
       void Start();

        /*!
        * @brief Publish a message to a topic
        * @param topic     Topic to publish to.
        * @param payload   Message payload.
        * @param qos       Quality of Service level (0, 1, or 2). Default is 1.
        * @return true if publish was successful, false otherwise
        */
        bool Publish(const std::string &topic, const std::string &payload, int qos = 1);

        /*!
        * @brief Subscribe to a topic with an optional message callback
        * @param topic     Topic to subscribe to.
        * @param cb        Optional callback function to handle incoming messages for this topic.
        * @return true if subscription was successful, false otherwise
        */
        bool Subscribe(const std::string &topic, MessageCallback cb = nullptr);

        /*!
        * @brief Set a global message callback for all incoming messages
        * @param cb    Callback function to handle incoming messages.
        */  
        void SetMessageCallback(MessageCallback cb);

    private:

        enum class State 
        {
            IDLE,
            INIT,
            CONNECTING,
            CONNECTED,
            ERROR
        };

        
        //---------------------------------------------

        /*!
        * @brief Start the MQTT client and connect to the broker
        */
        auto _Start() -> State;

        /*! 
        * @brief Stop the MQTT client and disconnect from the broker
        */
        void _Stop();

        /*!
        * @brief Handle MQTT events
        * @param event   Pointer to the MQTT event data.
        */
        static void EventHandler(void* handler_args, esp_event_base_t base, int32_t event_id, void* event_data);

        //---------------------------------------------

        MqttClient();
        ~MqttClient();
        MqttClient(const MqttClient&) = delete;
        MqttClient& operator=(const MqttClient&) = delete;

        //---------------------------------------------

        static MqttClient* _instance;
        State _state;
        esp_mqtt_client_handle_t _client;
        std::string _brokerUri;
        std::string _username;
        std::atomic<bool> _connected;
        MessageCallback _globalCallback;
};

} // namespace Online

#endif // MQTT_CLIENT_H