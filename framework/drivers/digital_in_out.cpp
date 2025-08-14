/*!****************************************************************************
 * @file    digital_in_out.cpp
 * @brief   Implementation of the DigitalOut class for GPIO output control.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "digital_in_out.h"
#include "common_defs.h"

//-----------------------------------------------------------------------------
DigitalInOut::DigitalInOut(PinName pin, PinMode mode, int value)
    : _pin(static_cast<gpio_num_t>(pin))
    , _mode(mode)
{
    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = (1ULL << _pin);

    if (mode == PinMode::INPUT_MODE)
    {
        io_conf.mode = GPIO_MODE_INPUT;
    }
    else if (mode == PinMode::OUTPUT_MODE)
    {
        io_conf.mode = GPIO_MODE_OUTPUT;
    }
    else
    {
        io_conf.mode = GPIO_MODE_INPUT_OUTPUT;
    }

    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&io_conf);

    if (mode != INPUT_MODE)
    {
        Write(value);
    }
}

//-----------------------------------------------------------------------------
void DigitalInOut::Write(int value)
{
    ASSERT_MSG(_mode != INPUT_MODE, "DigitalInOut::Write - Cannot write to pin configured as INPUT_MODE");
    gpio_set_level(_pin, value ? 1 : 0);
}

//-----------------------------------------------------------------------------
int DigitalInOut::Read() const
{
    return gpio_get_level(_pin);
}

//-----------------------------------------------------------------------------
void DigitalInOut::Toggle()
{
    ASSERT_MSG(_mode != INPUT_MODE, "DigitalInOut::Toggle - Cannot toggle pin configured as INPUT");
    int current = gpio_get_level(_pin);
    gpio_set_level(_pin, !current);
}