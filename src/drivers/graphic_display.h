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
#include "framework/drivers/pwm_out.h"
#include "lvgl.h"
#include "src/core/base/driver.h"
#include <stdint.h>
#include <string>

namespace Drivers {

class GraphicDisplay : public Base::Singleton<GraphicDisplay>,
                       public Base::Driver
{
    public:

        static constexpr int DISP_H_RES = 320;
        static constexpr int DISP_V_RES = 240;

        using TouchCallback = std::function<void()>;

        class UIElement
        {
            public:

                explicit UIElement(lv_obj_t * lv_obj);
                ~UIElement();

                void SetText(const char* newText);
                void Hide();
                void Show();
                void SetState1();
                void ClearState1();

                bool IsValid() const { return _lv_obj != nullptr; }

                friend class GraphicDisplay;

            private:

                lv_obj_t* _lv_obj;
        };

        /**
         * @brief Sets the callback function to be called on double click events.
         * @param callback Function to call on double click.
         */
        void SetOnDoubleClickAction(TouchCallback callback);
    
    private:

        friend class Base::Singleton<GraphicDisplay>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "GraphicDisplay"; }

        /*!
        * @brief Initializes the Module.
        *        This method should be called once at the start of the application.
        *       * @return bool True if initialization successful, false otherwise.
        */
        bool OnInit() override;

        /*!
        * @brief Updates the Module state.
        *        This method should be called periodically to update the system state.
        */
        void OnUpdate() override;

        void SetupTouchDetection();
        static void OnTouchTimer(lv_timer_t* timer);
        static void OnTouchEventCallback(lv_event_t* e);

        void SetBrightness(uint8_t brightness);

        //---------------------------------------------
        
        GraphicDisplay();
        ~GraphicDisplay() = default;
        GraphicDisplay(const GraphicDisplay&) = delete;
        GraphicDisplay& operator=(const GraphicDisplay&) = delete;

        //---------------------------------------------

        static constexpr int DISP_SPI_HOST = SPI2_HOST; // VSPI

        // ---------------------------------------------

        int _misoPin;
        int _mosiPin;
        int _clkPin;
        int _csPin;
        int _dcPin;
        int _rstPin;
        int _touchCsPin;
        int _touchIrqPin;
        PwmOut _bklPin;

        TouchCallback _onDoubleClickAction = nullptr;

        // Handles for ESP-IDF LCD panel and touch
        esp_lcd_panel_handle_t _panel_handle = nullptr;
        esp_lcd_touch_handle_t _tp_handle = nullptr;

        // Handle for LVGL display
        lv_display_t* _lvgl_disp = nullptr;

        static uint32_t _last_click_time;

        bool _valid = false;
};

} // namespace Drivers