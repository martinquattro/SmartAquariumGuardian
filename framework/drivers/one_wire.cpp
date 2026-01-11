/*!****************************************************************************
 * @file    OneWire.cpp
 * @brief   Implementation of OneWire class for ESP32 GPIO pins.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "framework/drivers/one_wire.h"
#include "framework/common_defs.h"

//-----------------------------------------------------------------------------
OneWire::OneWire(PinName pin)
    : _pin(static_cast<gpio_num_t>(pin))
{
    gpio_set_direction(_pin, GPIO_MODE_INPUT_OUTPUT_OD);
    gpio_set_pull_mode(_pin, GPIO_PULLUP_ONLY);

    Release();
}

//-----------------------------------------------------------------------------
bool OneWire::Reset()
{
    portENTER_CRITICAL(&_mux);
    DriveLow();
    TaskDelayUs(480);
    Release();
    TaskDelayUs(70);

    int presence = !gpio_get_level(_pin);
    TaskDelayUs(250);
    portEXIT_CRITICAL(&_mux);

    return presence;
}

//-----------------------------------------------------------------------------
void OneWire::WriteBit(int bit)
{
    portENTER_CRITICAL(&_mux);
    {
        DriveLow();

        if (bit)
        {
            TaskDelayUs(6);
            Release();
            TaskDelayUs(64);
        }
        else
        {
            TaskDelayUs(60);
            Release();
            TaskDelayUs(10);
        }
    }
    portEXIT_CRITICAL(&_mux);
}

//-----------------------------------------------------------------------------
int OneWire::ReadBit()
{
    portENTER_CRITICAL(&_mux);
    DriveLow();
    TaskDelayUs(2);

    Release();
    TaskDelayUs(8);

    int bit = gpio_get_level(_pin);
    TaskDelayUs(50);
    portEXIT_CRITICAL(&_mux);

    return bit;
}

//-----------------------------------------------------------------------------
void OneWire::WriteByte(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
        WriteBit(data & 0x01);
        data >>= 1;
    }
}

//-----------------------------------------------------------------------------
uint8_t OneWire::ReadByte()
{
    uint8_t value = 0;
    for (int i = 0; i < 8; i++)
    {
        value >>= 1;
        if (ReadBit())
        {
            value |= 0x80;
        }
    }
    return value;
}

//-----------------------------------------------------------------------------
void OneWire::DriveLow()
{
    gpio_set_level(_pin, OFF);
}

//-----------------------------------------------------------------------------
void OneWire::Release()
{
    gpio_set_level(_pin, ON);
}