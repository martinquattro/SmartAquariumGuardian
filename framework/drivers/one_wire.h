/*!****************************************************************************
 * @file    OneWire.h
 * @brief   1-Wire communication driver for ESP32 GPIO pins.
 * @author  Quattrone martin
 * @date    Aug 2025
 ******************************************************************************/

#pragma once

#include "driver/gpio.h"
#include "framework/pin_names.h"

class OneWire
{
    public:

        /**
         * @brief Construct a OneWire instance.
         * @param pin GPIO pin used for 1-Wire bus.
         */
        OneWire(PinName pin);

        /**
         * @brief Reset the 1-Wire bus.
         * @return true if a device responds, false otherwise.
         */
        bool Reset();

        /**
         * @brief Write a single bit to the bus.
         * @param bit Value to write (0 or 1).
         */
        void WriteBit(int bit);

        /**
         * @brief Read a single bit from the bus.
         * @return Bit value (0 or 1).
         */
        int ReadBit();

        /**
         * @brief Write a byte to the bus (LSB first).
         * @param data Byte to write.
         */
        void WriteByte(uint8_t data);

        /**
         * @brief Read a byte from the bus (LSB first).
         * @return Byte read from bus.
         */
        uint8_t ReadByte();

    private:

        void DriveLow();
        void Release();

        gpio_num_t _pin;
};
