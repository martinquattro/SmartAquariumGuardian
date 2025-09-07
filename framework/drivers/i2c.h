/*!****************************************************************************
 * @file    i2c.h
 * @brief   Simple I2C driver class for ESP32 (ESP-IDF framework).
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#pragma once

#include "driver/i2c_master.h"
#include "framework/pin_names.h"
#include <cstdint>

class I2C
{
    public:

        /**
         * @brief Construct an I2C instance.
         * @param sda      PinName for SDA line.
         * @param scl      PinName for SCL line.
         * @param addr7bit 7-bit I2C address of the device.
         * @param port     I2C port number (I2C_NUM_0 or I2C_NUM_1).
         * @param freqHz   Communication frequency in Hz (default 100 kHz).
         */
        I2C(PinName sda, PinName scl, uint8_t addr7bit, i2c_port_num_t port = I2C_NUM_0, uint32_t freqHz = 100000);

        /**
         * @brief Destructor to clean up resources.
         */
        ~I2C();

        /**
         * @brief Write data to a device.
         * @param dev   Device handle obtained from AddDevice().
         * @param data  Pointer to data buffer.
         * @param len   Number of bytes to write.
         * @return true if success, false otherwise.
         */
        bool Write(const uint8_t* data, size_t len);

        /**
         * @brief Read data from a device.
         * @param dev   Device handle obtained from AddDevice().
         * @param data  Pointer to buffer to store read data.
         * @param len   Number of bytes to read.
         * @return true if success, false otherwise.
         */
        bool Read(uint8_t* data, size_t len);

        /**
         * @brief Write then read with arbitrary write buffer.
         * @param dev         Device handle obtained from AddDevice().
         * @param txBuffer    Buffer to write.
         * @param txLen       Length of data to write.
         * @param rxBuffer    Buffer to store read data.
         * @param rxLen       Length of data to read.
         * @return true if success, false otherwise.
         */
        bool WriteRead(const uint8_t* txBuffer
                    , size_t txLen
                    , uint8_t* rxBuffer
                    , size_t rxLen
        );

        /**
         * @brief Check if I2C initialized correctly.
         */
        bool IsValid() const;

    private:

        i2c_port_num_t _port;
        i2c_master_bus_handle_t _bus{};
        i2c_master_dev_handle_t _dev{};
        bool _valid;
};
