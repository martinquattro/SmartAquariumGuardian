/*!****************************************************************************
 * @file    DigitalOut.cpp
 * @brief   Implementation of the DigitalOut class for GPIO output control.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "DigitalOut.h"

//-----------------------------------------------------------------------------
DigitalOut::DigitalOut(PinName pin, int value)
    : _pin(static_cast<gpio_num_t>(pin))
{
    gpio_reset_pin(_pin);
    gpio_set_direction(_pin, GPIO_MODE_OUTPUT);
    Write(value);
}

//-----------------------------------------------------------------------------
void DigitalOut::Write(int value)
{
    gpio_set_level(_pin, value ? 1 : 0);
}

//-----------------------------------------------------------------------------
int DigitalOut::Read() const
{
    return gpio_get_level(_pin);
}

//-----------------------------------------------------------------------------
void DigitalOut::Toggle()
{
    Write(!Read());
}
