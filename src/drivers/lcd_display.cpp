/*!****************************************************************************
 * @file    lcd_display.cpp
 * @brief   Implementation of LcdDisplay class (20x4 LCD, 4-bit GPIO mode)
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "src/drivers/lcd_display.h"

#include "include/config.h"

namespace Drivers {

LcdDisplay* LcdDisplay::_instance = nullptr;

//----static-------------------------------------------------------------------
LcdDisplay* LcdDisplay::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void LcdDisplay::Init()
{
    CORE_INFO("Initializing LcdDisplay...");

    if (_instance != nullptr)
    {
        CORE_ERROR("LcdDisplay already initialized!");
        return;
    }

    _instance = new LcdDisplay(
          Config::LCD_RS_PIN
        , Config::LCD_EN_PIN
        , Config::LCD_D4_PIN
        , Config::LCD_D5_PIN
        , Config::LCD_D6_PIN
        , Config::LCD_D7_PIN
    );

    // Initialization sequence from datasheet
    TaskDelayMs(50);

    _instance->WriteCommand(COMMANDS::CMD_INITIALIZE);
    _instance->WriteCommand(COMMANDS::CMD_SET_4BIT_MODE);
    _instance->WriteCommand(COMMANDS::CMD_FUNCTION_SET);
    _instance->WriteCommand(COMMANDS::CMD_DISPLAY_ON);
    _instance->WriteCommand(COMMANDS::CMD_CLEAR_DISPLAY);
    _instance->WriteCommand(COMMANDS::CMD_ENTRY_MODE);
}

//-----------------------------------------------------------------------------
void LcdDisplay::Clear()
{
    WriteCommand(COMMANDS::CMD_CLEAR_DISPLAY);
    TaskDelayMs(2);
}

//-----------------------------------------------------------------------------
void LcdDisplay::SetCursor(uint8_t x, uint8_t y)
{
    WriteCommand(CMD_CURSOR_SET | (LINE_ADDR[y] + x));
}

//-----------------------------------------------------------------------------
void LcdDisplay::Write(const char* str)
{
    while (*str)
    {
        WriteData(*str++);
    }
}

//----private------------------------------------------------------------------
void LcdDisplay::WriteCommand(uint8_t cmd)
{
    _rsPin.Write(0);

    Write4Bits(cmd >> 4);
    Write4Bits(cmd & 0x0F);
}

//----private------------------------------------------------------------------
void LcdDisplay::WriteData(uint8_t data)
{
    _rsPin.Write(1);

    Write4Bits(data >> 4);
    Write4Bits(data & 0x0F);
}

//----private------------------------------------------------------------------
void LcdDisplay::PulseEnable()
{
    _enPin.Write(0);
    TaskDelayUs(1);

    _enPin.Write(1);
    TaskDelayUs(1);

    _enPin.Write(0);
    TaskDelayUs(100);
}

//----private------------------------------------------------------------------
void LcdDisplay::Write4Bits(uint8_t value)
{
    _d4Pin.Write((value >> 0) & 0x01);
    _d5Pin.Write((value >> 1) & 0x01);
    _d6Pin.Write((value >> 2) & 0x01);
    _d7Pin.Write((value >> 3) & 0x01);

    PulseEnable();
}

//----private------------------------------------------------------------------
LcdDisplay::LcdDisplay(PinName rs, PinName en, PinName d4, PinName d5, PinName d6, PinName d7)
    : _rsPin(rs, DigitalInOut::PinMode::OUTPUT_MODE)
    , _enPin(en, DigitalInOut::PinMode::OUTPUT_MODE)
    , _d4Pin(d4, DigitalInOut::PinMode::OUTPUT_MODE)
    , _d5Pin(d5, DigitalInOut::PinMode::OUTPUT_MODE)
    , _d6Pin(d6, DigitalInOut::PinMode::OUTPUT_MODE)
    , _d7Pin(d7, DigitalInOut::PinMode::OUTPUT_MODE)
{}

} // namespace Drivers