/*!****************************************************************************
 * @file    mqtt_client.h
 * @brief   MQTT client wrapper (esp-mqtt) with simple Publish/Subscribe API.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include "framework/common_defs.h"
#include "src/core/base/driver.h"
#include <atomic>
#include <functional>
#include <mqtt_client.h>
#include <string>

namespace Connectivity {

class MqttClient : public Base::Singleton<MqttClient>,
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

        using MessageCallback = std::function<void(const std::string &topic, const std::string &payload)>;

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
        * @brief Stop MQTT connection
        */
        void Stop();

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

    protected:

        friend class Base::Singleton<MqttClient>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "MqttClient"; }

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

        State _state;
        esp_mqtt_client_handle_t _client;
        std::string _brokerUri;
        std::string _username;
        std::atomic<bool> _connected;
        MessageCallback _globalCallback;
};

} // namespace Online

#endif // MQTT_CLIENT_H