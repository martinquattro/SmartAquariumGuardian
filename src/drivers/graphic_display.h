/*!****************************************************************************
 * @file    graphic_display.h
 * @brief   Driver class for ILI9341 display with XPT2046 touch, using LVGL via esp_lvgl_port.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#pragma once

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_lcd_ili9341.h"
#include "esp_lcd_panel_interface.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch_xpt2046.h"
#include "esp_lcd_types.h"
#include "esp_lvgl_port.h"
#include "framework/common_defs.h"
#include "lvgl.h"
#include <stdint.h>
#include <string>

namespace Drivers {

class GraphicDisplay
{
    public:

        /**
         * @brief Get the singleton instance of GraphicDisplay.
         * @return Pointer to the singleton instance.
         */
        static GraphicDisplay* GetInstance();

        /**
         * @brief Initializes the display, touch, and LVGL subsystem.
         * Should be called once at startup.
         */
        static void Init();

    private:

        void TestDisplay();

        void SetupTouchDetection();
        static void OnTouchTimer(lv_timer_t* timer);
        static void OnTouchEventCallback(lv_event_t* e);

        //---------------------------------------------
        
        GraphicDisplay(PinName miso, PinName mosi, PinName clk, PinName cs, PinName dc, PinName rst, PinName touchCs, PinName touchIrq);
        ~GraphicDisplay() = default;
        GraphicDisplay(const GraphicDisplay&) = delete;
        GraphicDisplay& operator=(const GraphicDisplay&) = delete;

        //---------------------------------------------

        static constexpr int DISP_H_RES = 320;
        static constexpr int DISP_V_RES = 240;

        static constexpr int DISP_SPI_HOST = SPI2_HOST; // VSPI

        // ---------------------------------------------

        static GraphicDisplay* _instance;

        int _misoPin;
        int _mosiPin;
        int _clkPin;
        int _csPin;
        int _dcPin;
        int _rstPin;
        int _touchCsPin;
        int _touchIrqPin;

        // Handles for ESP-IDF LCD panel and touch
        esp_lcd_panel_handle_t _panel_handle = nullptr;
        esp_lcd_touch_handle_t _tp_handle = nullptr;

        // Handle for LVGL display
        lv_display_t* _lvgl_disp = nullptr;

        static uint32_t _last_click_time;

        bool _valid = false;
};

} // namespace Drivers