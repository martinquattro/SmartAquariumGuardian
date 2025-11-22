/*!****************************************************************************
 * @file    mqtt_client.cpp
 * @brief   MQTT client wrapper (esp-mqtt) with simple Publish/Subscribe API.
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "connectivity/mqtt_client.h"

#include "esp_log.h"
#include "esp_system.h"
#include "include/config.h"
#include <cstring>

namespace Connectivity {

MqttClient* MqttClient::_instance = nullptr;

//----static-------------------------------------------------------------------
MqttClient* MqttClient::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void MqttClient::Init()
{
    CORE_INFO("Initializing MqttClient...");

    if (_instance != nullptr)
    {
        CORE_ERROR("MqttClient already initialized!");
        return;
    }

    _instance = new MqttClient();
    _instance->_brokerUri = "mqtt://192.168.0.51:1883";
    _instance->_username = "Ltew0gHjxRjGTSxYj85t";
    _instance->_state = State::IDLE;
    _instance->_connected = false;
}

//-----------------------------------------------------------------------------
void MqttClient::Update()
{
    switch (_state)
    {
        case State::IDLE:
        {
            // nothing to do
        }
        break;

        case State::INIT:
        {
            _state = _Start();
        }
        break;

        case State::CONNECTING:
        {
            if (IsConnected()) 
            {
                _state = State::CONNECTED;
            }
        }
        break;

        case State::CONNECTED:
        {
            if (!IsConnected()) 
            {
                CORE_WARNING("MqttClient disconnected");
                _state = State::ERROR;
            }
        }
        break;

        case State::ERROR:
        {
        }
        break;

        default:
        {
            CORE_ERROR("Unknown state");
            _state = State::ERROR;
        }
        break;
    }
}

//-----------------------------------------------------------------------------
bool MqttClient::IsConnected() const
{
    return _connected.load();
}

//-----------------------------------------------------------------------------
void MqttClient::Start()
{
    if (_state == State::IDLE || _state == State::ERROR)
    {
        _state = State::INIT;
    }
}

//-----------------------------------------------------------------------------
bool MqttClient::Publish(const std::string &topic, const std::string &payload, int qos)
{
    if (!_client) 
    {
        return false;
    }

    int msg_id = esp_mqtt_client_publish(
        _client, 
        topic.c_str(),
        payload.c_str(),
        payload.size(),
        qos,
        0
    );

    return (msg_id >= 0);
}

//-----------------------------------------------------------------------------
bool MqttClient::Subscribe(const std::string &topic, MessageCallback cb)
{
    if (!_client) 
    {
        return false;
    }

    int sub_id = esp_mqtt_client_subscribe(_client, topic.c_str(), 1);

    if (sub_id >= 0) 
    {
        if (cb) 
        {
            _globalCallback = cb; // simple single-callback model
        }

        return true;
    }

    return false;
}

//-----------------------------------------------------------------------------
void MqttClient::SetMessageCallback(MessageCallback cb)
{
    _globalCallback = cb;
}

//----private------------------------------------------------------------------
auto MqttClient::_Start() -> State
{
    if (_client) 
    {
        CORE_WARNING("Client already started");
        return State::ERROR;
    }

    esp_mqtt_client_config_t cfg;
    memset(&cfg, 0, sizeof(cfg));
    cfg.broker.address.uri = _brokerUri.c_str();
    cfg.credentials.username = _username.c_str();

    _client = esp_mqtt_client_init(&cfg);
    if (_client == nullptr)
    {
        CORE_ERROR("Init failed");
        return State::ERROR;
    }

    esp_mqtt_client_register_event(_client, MQTT_EVENT_ANY, MqttClient::EventHandler, this);
    esp_err_t result = esp_mqtt_client_start(_client);

    if (result != ESP_OK) 
    {
        CORE_ERROR("Start failed %d", result);
        esp_mqtt_client_destroy(_client);
        _client = nullptr;
        return State::ERROR;
    }

    CORE_INFO("MqttClient connecting to broker at %s", _brokerUri.c_str());
    return State::CONNECTING;
}

//----private------------------------------------------------------------------
void MqttClient::_Stop()
{
    if (_client) 
    {
        esp_mqtt_client_stop(_client);
        esp_mqtt_client_destroy(_client);
        _client = nullptr;
        _connected = false;

        CORE_INFO("MqttClient stopped");
    }
}

//----private------------------------------------------------------------------
void MqttClient::EventHandler(
    void* handler_args,
    esp_event_base_t base,
    int32_t event_id,
    void* event_data)
{
    esp_mqtt_event_handle_t event = static_cast<esp_mqtt_event_handle_t>(event_data);

    switch (event->event_id)
    {
        case MQTT_EVENT_CONNECTED:
        {
            CORE_INFO("MqttClient: connected");
            _instance->_connected = true;
        }
        break;

        case MQTT_EVENT_DISCONNECTED:
        {
            CORE_WARNING("MqttClient: disconnected");
            _instance->_connected = false;
        }
        break;

        case MQTT_EVENT_DATA:
        {
            std::string topic(event->topic, event->topic_len);
            std::string payload(event->data, event->data_len);

            if (_instance->_globalCallback) 
            {
                _instance->_globalCallback(topic, payload);
            }
        }
        break;

        default:
        {
            // Do nothing
        }
        break;
    }
}

//----private------------------------------------------------------------------
MqttClient::MqttClient()
    : _client(nullptr)
    , _connected(false)
    , _globalCallback(nullptr)
{}

//----private------------------------------------------------------------------
MqttClient::~MqttClient()
{
    _Stop();
}

} // namespace Online