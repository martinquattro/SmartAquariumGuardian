/*!****************************************************************************
 * @file    led.cpp
 * @brief   Implementation of a simple LED driver class.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#include "src/drivers/led.h"

namespace Drivers {

//-----------------------------------------------------------------------------
Led::Led(PinName pin, bool activeHigh)
    : _pin(pin, DigitalInOut::PinMode::INPUT_OUTPUT_MODE, activeHigh ? HIGH : LOW)
{}

//-----------------------------------------------------------------------------
void Led::TurnOn()
{
    _pin.Write(ON);
}

//-----------------------------------------------------------------------------
void Led::TurnOff()
{
    _pin.Write(OFF);
}

//-----------------------------------------------------------------------------
void Led::Toggle()
{
    _pin.Toggle();
}

//-----------------------------------------------------------------------------
bool Led::IsOn() const
{
    return (_pin.Read() == HIGH);
}

} // namespace Drivers