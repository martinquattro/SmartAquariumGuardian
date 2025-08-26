/*!****************************************************************************
 * @file    lcd_display.h
 * @brief   Driver for 20x4 LCD display (HD44780) using 4-bit GPIO mode
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include "framework/common_defs.h"

namespace Drivers {

class LcdDisplay
{
    public:
        /**
        * @brief Get the singleton instance of LcdDisplay.
        * @return LcdDisplay* Pointer to the LcdDisplay instance.
        */
        static LcdDisplay* GetInstance();

        /**
         * @brief Initialize the LCD display.
         */
        static void Init();

        /**
         * @brief Clear the display and reset cursor position.
         */
        void Clear();

         /**
          * @brief Set the cursor position.
          * @param x Column (0-19).
          * @param y Row (0-3).
          */
        void SetCursor(uint8_t x, uint8_t y);

        /**
         * @brief Write a string to the display at the current cursor position.
         * @param str Null-terminated string to display.
         */
        void Write(const char* str);

    private:

        /**
         * @brief Send a command to the LCD.
         * @param cmd Command byte.
         */
        void WriteCommand(uint8_t cmd);

        /**
         * @brief Send a data byte (character) to the LCD.
         * @param data Data byte.
         */
        void WriteData(uint8_t data);

        /**
         * @brief Pulse the enable pin to latch data/command.
         */
        void PulseEnable();

        /**
         * @brief Write 4 bits to the data pins.
         * @param value 4-bit value to write.
         */
        void Write4Bits(uint8_t value);

        LcdDisplay(PinName rs, PinName en, PinName d4, PinName d5, PinName d6, PinName d7);
        ~LcdDisplay() = default;
        LcdDisplay(const LcdDisplay&) = delete;
        LcdDisplay& operator=(const LcdDisplay&) = delete;

        //---------------------------------------------

        enum COMMANDS
        {
            CMD_INITIALIZE      = 0x33,
            CMD_SET_4BIT_MODE   = 0x32,
            CMD_CLEAR_DISPLAY   = 0x01,
            CMD_RETURN_HOME     = 0x02,
            CMD_ENTRY_MODE      = 0x06,
            CMD_DISPLAY_ON      = 0x0C,
            CMD_FUNCTION_SET    = 0x28,   // 4-bit, 2-line, 5x8 dots
            CMD_CURSOR_SET      = 0x80
        };

        static constexpr uint8_t LINE_ADDR[4] = { 0x00, 0x40, 0x14, 0x54 };

        //---------------------------------------------

        static LcdDisplay* _instance;
        DigitalInOut _rsPin;
        DigitalInOut _enPin;
        DigitalInOut _d4Pin, _d5Pin, _d6Pin, _d7Pin;
};

} // namespace Drivers

#endif // LCD_DISPLAY_H
