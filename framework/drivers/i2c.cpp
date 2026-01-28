/*!****************************************************************************
 * @file    i2c.cpp
 * @brief   Implementation of I2C class using new ESP-IDF master API (v5+).
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "framework/drivers/i2c.h" 
#include "framework/common_defs.h"

i2c_master_bus_handle_t I2C::_busHandles[I2C_NUM_MAX] = {nullptr};

//-----------------------------------------------------------------------------
I2C::I2C(PinName sda, PinName scl, uint8_t addr7bit, i2c_port_num_t port, uint32_t freqHz)
    : _port(port)
    , _valid(false)
{
    _mutex = xSemaphoreCreateMutex();
    if (_mutex == nullptr)
    {
        CORE_ERROR("Failed to create I2C mutex!");
        return;
    }

    // Initialize bus only once
    if (_busHandles[port] == nullptr) 
    {
        i2c_master_bus_config_t bus_config = 
        {
            .i2c_port = port,
            .sda_io_num = static_cast<gpio_num_t>(sda),
            .scl_io_num = static_cast<gpio_num_t>(scl),
            .clk_source = I2C_CLK_SRC_DEFAULT,
            .glitch_ignore_cnt = 7,
            .intr_priority = 0,
            .trans_queue_depth = 0,
            .flags = { .enable_internal_pullup = 1, .allow_pd = 0 }
        };

        if (i2c_new_master_bus(&bus_config, &_busHandles[port]) == ESP_OK)
        {
            CORE_INFO("Bus initialized on port %d", port);
        }
        else 
        {
            CORE_ERROR("Failed to init bus on port %d", port);
            return;
        }
    }

    // Register device
    i2c_device_config_t dev_cfg = 
    {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = addr7bit,
        .scl_speed_hz = freqHz,
        .scl_wait_us = 0,
        .flags = { .disable_ack_check = 0 }
    };

    if (i2c_master_bus_add_device(_busHandles[port], &dev_cfg, &_dev) == ESP_OK)
    {
        _valid = true;
        CORE_INFO("Device 0x%02X added on port %d", addr7bit, port);
    }
    else
    {
        CORE_ERROR("Failed to add device 0x%02X", addr7bit);
    }
}

//-----------------------------------------------------------------------------
I2C::~I2C()
{
    if (_dev) 
    {
        i2c_master_bus_rm_device(_dev);
    }

    if (_mutex != nullptr)
    {
        vSemaphoreDelete(_mutex);
    }
}

//-----------------------------------------------------------------------------
bool I2C::Write(const uint8_t* data, size_t len)
{
if (!_valid || _mutex == NULL)
    {
        return false;
    }

    if (xSemaphoreTake(_mutex, portMAX_DELAY) == pdTRUE)
    {
        esp_err_t err = i2c_master_transmit(_dev, data, len, 100);
        
        xSemaphoreGive(_mutex);
        
        return (err == ESP_OK);
    }
    
    return false;
}

//-----------------------------------------------------------------------------
bool I2C::Read(uint8_t* data, size_t len)
{
if (!_valid || _mutex == NULL)
    {
        return false;
    }

    if (xSemaphoreTake(_mutex, portMAX_DELAY) == pdTRUE)
    {
        esp_err_t err = i2c_master_receive(_dev, data, len, 100);
        xSemaphoreGive(_mutex);

        return (err == ESP_OK);
    }

    return false;
}

//-----------------------------------------------------------------------------
bool I2C::WriteRead(const uint8_t* txBuffer
                    , size_t txLen
                    , uint8_t* rxBuffer
                    , size_t rxLen)
{
    if (!_valid || _mutex == NULL)
    {
        return false;
    }

    if (xSemaphoreTake(_mutex, 500 / portTICK_PERIOD_MS) == pdTRUE)
    {
        esp_err_t err = i2c_master_transmit_receive(_dev, txBuffer, txLen, rxBuffer, rxLen, 100);
        xSemaphoreGive(_mutex);

        return (err == ESP_OK);
    }

    return false;
}

//-----------------------------------------------------------------------------
bool I2C::IsValid() const
{
    return _valid;
}
