/*!****************************************************************************
 * @file    graphic_display.cpp
 * @brief   Implementation of the GraphicDisplay driver class.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#include "src/drivers/graphic_display.h"
#include "esp_err.h"
#include "include/config.h"
#include "lvgl.h"

LV_FONT_DECLARE(lv_font_montserrat_14);
LV_FONT_DECLARE(lv_font_montserrat_18);
LV_FONT_DECLARE(lv_font_montserrat_22);
LV_FONT_DECLARE(lv_font_montserrat_26);

namespace Drivers {

GraphicDisplay* GraphicDisplay::_instance = nullptr;
uint32_t GraphicDisplay::_last_click_time = 0;

//-----------------------------------------------------------------------------
GraphicDisplay::UIElement::UIElement() 
    : _lv_obj(nullptr)
    , _linePoints(nullptr)
{
}

//-----------------------------------------------------------------------------
GraphicDisplay::UIElement::~UIElement()
{
    if (_lv_obj != nullptr) 
    {
        if (lvgl_port_lock(portMAX_DELAY)) 
        {
            lv_obj_delete(_lv_obj);
            lvgl_port_unlock();
        }
        _lv_obj = nullptr;
    }

    if (_linePoints != nullptr) 
    {
        delete[] _linePoints;
        _linePoints = nullptr;
    }
}

//-----------------------------------------------------------------------------
bool GraphicDisplay::UIElement::Init(lv_obj_t* parentScreen, lv_align_t align, int x, int y, const char* initialText, lv_font_t* font)
{
    _lv_obj = lv_label_create(parentScreen);
    if (_lv_obj == nullptr) 
    {
        return false;
    }

    lv_obj_align(_lv_obj, align, x, y);
    lv_label_set_text(_lv_obj, initialText);
    lv_obj_set_style_text_font(_lv_obj, font, LV_PART_MAIN);
    
    lv_obj_set_style_text_color(_lv_obj, GetLvglStatusColor(ElementStatus::NORMAL), LV_PART_MAIN);

    return true;
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::SetText(const char* newText)
{
    if (_lv_obj == nullptr) 
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_label_set_text(_lv_obj, newText);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::SetStatus(ElementStatus status)
{
    if (_lv_obj == nullptr) 
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_color_t color = GetLvglStatusColor(status);
        lv_obj_set_style_text_color(_lv_obj, color, LV_PART_MAIN);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::SetColor(ElementColor color)
{
    if (_lv_obj == nullptr) 
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_set_style_text_color(_lv_obj, GetColor(color), LV_PART_MAIN);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::SetBold(bool enable)
{
    if (_lv_obj == nullptr)
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        if (enable)
        {
            static lv_style_t bold_style;
            lv_style_init(&bold_style);
            lv_style_set_text_outline_stroke_width(&bold_style, 2);
            lv_obj_add_style(_lv_obj, &bold_style, LV_PART_MAIN);
        }
        else
        {
            lv_obj_remove_style_all(_lv_obj);
        }

        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::SetBorderColor(ElementColor color)
{
    if (_lv_obj == nullptr) 
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_set_style_border_color(_lv_obj, GetColor(color), LV_PART_MAIN);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::Hide()
{
    if (_lv_obj == nullptr)
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_add_flag(_lv_obj, LV_OBJ_FLAG_HIDDEN);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::UIElement::Show()
{
    if (_lv_obj == nullptr)
        return;

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_clear_flag(_lv_obj, LV_OBJ_FLAG_HIDDEN);
        lvgl_port_unlock();
    }
}

//-----------------------------------------------------------------------------
lv_color_t GraphicDisplay::UIElement::GetLvglStatusColor(ElementStatus status)
{
    switch (status)
    {
        case ElementStatus::NORMAL:            return lv_color_white();             // White color
        case ElementStatus::OK:                return lv_color_make(0, 255, 0);     // No Red, Full Green, No Blue;
        case ElementStatus::WARNING:           return lv_color_make(255, 255, 0);   // Full Red, Full Green, No Blue;
        case ElementStatus::CRITICAL:          return lv_color_make(255, 0, 0);     // Full Red, No Green, No Blue;
        default:
        {
            return lv_color_white();
        }
    }
}

//-----------------------------------------------------------------------------
lv_color_t GraphicDisplay::UIElement::GetColor(ElementColor color)
{
    switch (color)
    {
        case ElementColor::RED:        return lv_color_make(255, 0, 0);     // Full Red, No Green, No Blue;
        case ElementColor::GREEN:      return lv_color_make(0, 255, 0);     // No Red, Full Green, No Blue;
        case ElementColor::BLUE:       return lv_color_make(0, 0, 255);     // No Red, No Green, Full Blue;
        case ElementColor::YELLOW:     return lv_color_make(255, 255, 0);   // Full Red, Full Green, No Blue;
        case ElementColor::WHITE:      return lv_color_white();             // White color
        case ElementColor::BLACK:      return lv_color_make(0, 0, 0);       // Black color
        case ElementColor::GREY:       return lv_color_make(210, 210, 210); // Grey color
        default:
        {
            return lv_color_white();
        }
    }
}

//----static-------------------------------------------------------------------
GraphicDisplay* GraphicDisplay::GetInstance()
{
    if (_instance != nullptr)
    {
        return _instance;
    }
    return _instance;
}

//----static-------------------------------------------------------------------
void GraphicDisplay::Init()
{
    CORE_INFO("Initializing GraphicDisplay...");

    if (_instance != nullptr)
    {
        CORE_ERROR("GraphicDisplay already initialized!"); 
        return;
    }

    _instance = new GraphicDisplay(Config::DISP_MISO_PIN,
                                   Config::DISP_MOSI_PIN,
                                   Config::DISP_CLK_PIN,
                                   Config::DISP_CS_PIN,
                                   Config::DISP_DC_PIN,
                                   Config::DISP_RESET_PIN,
                                   Config::DISP_TOUCH_CS_PIN,
                                   Config::DISP_TOUCH_IRQ_PIN
    );
    
    esp_err_t ret;

    CORE_INFO("Initializing SPI bus");

    spi_bus_config_t buscfg = 
    {
        .mosi_io_num = _instance->_mosiPin,
        .miso_io_num = _instance->_misoPin,
        .sclk_io_num = _instance->_clkPin,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = (DISP_H_RES * 80 * sizeof(uint16_t)),
    };

    // Choosing DMA channel 0 (no DMA) for simplicity; can be changed to SPI_DMA_CH_AUTO if needed
    ret = spi_bus_initialize((spi_host_device_t)DISP_SPI_HOST, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    // Initialize LVGL port
    CORE_INFO("Initializing LVGL port");

    lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    ret = lvgl_port_init(&lvgl_cfg);
    ESP_ERROR_CHECK(ret);

    // Configure and install the ILI9341 panel driver
    CORE_INFO("Installing ILI9341 panel driver");
    
    esp_lcd_panel_io_spi_config_t io_config = 
    {
        .cs_gpio_num = _instance->_csPin,
        .dc_gpio_num = _instance->_dcPin,
        .spi_mode = 0,
        .pclk_hz = 40 * 1000 * 1000, // 40 MHz clock
        .trans_queue_depth = 10,
        .on_color_trans_done = NULL,
        .user_ctx = NULL,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .flags = { .dc_low_on_data = 0 }
    };

    // Create SPI IO handle for the panel
    esp_lcd_panel_io_handle_t io_handle = nullptr;
    ret = esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)DISP_SPI_HOST, &io_config, &io_handle);
    ESP_ERROR_CHECK(ret);

    esp_lcd_panel_dev_config_t panel_config =
    {
        .reset_gpio_num = _instance->_rstPin,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };

    // Create the panel handle
    ret = esp_lcd_new_panel_ili9341(io_handle, &panel_config, &_instance->_panel_handle);
    ESP_ERROR_CHECK(ret);

    // Intialize the panel
    ret = esp_lcd_panel_reset(_instance->_panel_handle);
    ESP_ERROR_CHECK(ret);
    
    ret = esp_lcd_panel_init(_instance->_panel_handle);
    ESP_ERROR_CHECK(ret);

    // Additional panel configurations
    CORE_INFO("Configuring panel orientation and color settings");

    ret = esp_lcd_panel_mirror(_instance->_panel_handle, false, true);
    ESP_ERROR_CHECK(ret);

    ret = esp_lcd_panel_swap_xy(_instance->_panel_handle, false);
    ESP_ERROR_CHECK(ret);

    // Turn on the display
    ret = esp_lcd_panel_disp_on_off(_instance->_panel_handle, true);
    ESP_ERROR_CHECK(ret);

    // Add display to LVGL
    CORE_INFO("Adding display to LVGL");

    lvgl_port_display_cfg_t disp_cfg =
    {
        .io_handle = io_handle,
        .panel_handle = _instance->_panel_handle,
        .buffer_size = DISP_H_RES * 60,
        .double_buffer = true,
        .hres = DISP_H_RES,
        .vres = DISP_V_RES,
        .monochrome = false,
        .rotation = { .swap_xy = false, .mirror_x = false, .mirror_y = true },
        .flags = { .buff_dma = 1, .swap_bytes = 1 }
    };

    _instance->_lvgl_disp = lvgl_port_add_disp(&disp_cfg);

    // Set default background color to black
    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_t* scr = lv_scr_act();

        lv_obj_set_style_bg_color(scr, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, LV_PART_MAIN);

        lvgl_port_unlock();
    }

    CORE_INFO("Initializing XPT2046 touch driver");
    
    esp_lcd_panel_io_handle_t tp_io_handle = nullptr;
    
    esp_lcd_panel_io_spi_config_t tp_io_config = 
    {
        .cs_gpio_num = _instance->_touchCsPin,
        .dc_gpio_num = GPIO_NUM_NC,
        .spi_mode = 0,
        .pclk_hz = 2 * 1000 * 1000,
        .trans_queue_depth = 10,
        .on_color_trans_done = NULL,
        .user_ctx = NULL,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .flags = {}
    };

    // Create SPI IO handle for touch panel
    ret = esp_lcd_new_panel_io_spi((spi_host_device_t)DISP_SPI_HOST, &tp_io_config, &tp_io_handle);
    ESP_ERROR_CHECK(ret);

    esp_lcd_touch_config_t tp_cfg = 
    {
        .x_max = DISP_H_RES,
        .y_max = DISP_V_RES,
        .rst_gpio_num = GPIO_NUM_NC,
        .int_gpio_num = (gpio_num_t)_instance->_touchIrqPin,
        .levels = { .reset = 0, .interrupt = 0 },
        .flags = { .swap_xy = false, .mirror_x = false, .mirror_y = true }
    };

    // Create touch handle
    ret = esp_lcd_touch_new_spi_xpt2046(tp_io_handle, &tp_cfg, &_instance->_tp_handle);
    ESP_ERROR_CHECK(ret);

    // Add touch to LVGL
    CORE_INFO("Add touch to LVGL");

    lvgl_port_touch_cfg_t touch_cfg = 
    {
        .disp = _instance->_lvgl_disp,
        .handle = _instance->_tp_handle,
    };
    lvgl_port_add_touch(&touch_cfg);


    CORE_INFO("Finalizing setup...");

    if (lvgl_port_lock(portMAX_DELAY)) 
    {
        _instance->SetupTouchDetection();
        
        lvgl_port_unlock();
    }

    _instance->_valid = true;
    CORE_INFO("Graphic Display initialized successfully!");
}

//-----------------------------------------------------------------------------
GraphicDisplay::UIElement* GraphicDisplay::CreateTextElement(lv_align_t align, int x, int y, const char* initialText, FontSize size)
{
    if (!_valid) 
        return nullptr;

    UIElement* newElement = new UIElement();

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_t* scr = lv_scr_act();
        lv_font_t* font = GetLvglFont(size);
        
        bool success = newElement->Init(scr, align, x, y, initialText, font);
        
        lvgl_port_unlock();

        if (success) 
        {
            return newElement;
        }
    }

    delete newElement;
    return nullptr;
}

//-----------------------------------------------------------------------------
GraphicDisplay::UIElement* GraphicDisplay::CreateLine(int x1, int y1, int x2, int y2, ElementColor color, int width)
{
    if (!_valid) 
        return nullptr;

    UIElement* newLineElement = new UIElement();

    newLineElement->_linePoints = new lv_point_precise_t[2];

    newLineElement->_linePoints[0] = { (lv_value_precise_t)x1, (lv_value_precise_t)y1 };
    newLineElement->_linePoints[1] = { (lv_value_precise_t)x2, (lv_value_precise_t)y2 };

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_t* scr = lv_scr_act();
        
        newLineElement->_lv_obj = lv_line_create(scr);

        if (newLineElement->_lv_obj)
        {
            lv_line_set_points(newLineElement->_lv_obj, newLineElement->_linePoints, 2);

            lv_obj_set_style_line_color(newLineElement->_lv_obj, newLineElement->GetColor(color), LV_PART_MAIN);
            lv_obj_set_style_line_width(newLineElement->_lv_obj, width, LV_PART_MAIN);
            lv_obj_set_style_line_rounded(newLineElement->_lv_obj, true, LV_PART_MAIN);
            lv_obj_set_style_line_opa(newLineElement->_lv_obj, LV_OPA_10, LV_PART_MAIN);
        } 
        else 
        {
             delete[] newLineElement->_linePoints;
             newLineElement->_linePoints = nullptr;
             delete newLineElement;
             newLineElement = nullptr;
        }
        lvgl_port_unlock();
    }

    return newLineElement;
}

//-----------------------------------------------------------------------------
GraphicDisplay::UIElement* GraphicDisplay::CreateRing(lv_align_t align, int x, int y, int diameter, int thickness, ElementColor color)
{
    if (!_valid) return nullptr;

    UIElement* newElement = new UIElement();

    if (lvgl_port_lock(portMAX_DELAY))
    {
        lv_obj_t* scr = lv_scr_act();
        
        newElement->_lv_obj = lv_obj_create(scr);

        if (newElement->_lv_obj)
        {
            lv_obj_set_size(newElement->_lv_obj, diameter, diameter);
            lv_obj_set_style_radius(newElement->_lv_obj, LV_RADIUS_CIRCLE, LV_PART_MAIN);
            
            lv_obj_set_style_bg_opa(newElement->_lv_obj, LV_OPA_TRANSP, LV_PART_MAIN);
            
            lv_obj_set_style_border_width(newElement->_lv_obj, thickness, LV_PART_MAIN);
            lv_obj_set_style_border_color(newElement->_lv_obj, newElement->GetColor(color), LV_PART_MAIN);

            // ---------------------------

            lv_obj_set_style_shadow_width(newElement->_lv_obj, 0, LV_PART_MAIN);
            lv_obj_remove_flag(newElement->_lv_obj, LV_OBJ_FLAG_SCROLLABLE);

            lv_obj_align(newElement->_lv_obj, align, x, y);
        }
        else
        {
             delete newElement;
             newElement = nullptr;
        }

        lvgl_port_unlock();
    }
    return newElement;
}

//-----------------------------------------------------------------------------
lv_font_t* GraphicDisplay::GetLvglFont(FontSize size)
{
    switch (size) 
    {
        case FontSize::TINY:        return (lv_font_t*)&lv_font_montserrat_14;
        case FontSize::SMALL:       return (lv_font_t*)&lv_font_montserrat_18;
        case FontSize::MEDIUM:      return (lv_font_t*)&lv_font_montserrat_22;
        case FontSize::LARGE:       return (lv_font_t*)&lv_font_montserrat_26;
        default: 
        {
            return (lv_font_t*)&lv_font_montserrat_14;
        }
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::OnTouchEventCallback(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        uint32_t current_time = lv_tick_get();
        const uint32_t double_click_speed_ms = 300;

        if (current_time - _last_click_time < double_click_speed_ms)
        {
            CORE_INFO(">>> Double click detecte<<<");
            _last_click_time = 0; 
        }
        else
        {
            CORE_INFO("Single click detected");
            _last_click_time = current_time;
        }
    }
}

//-----------------------------------------------------------------------------
void GraphicDisplay::SetupTouchDetection()
{
    lv_obj_t * scr = lv_scr_act();
    lv_obj_add_event_cb(scr, OnTouchEventCallback, LV_EVENT_ALL, nullptr);
    
    CORE_INFO("Touch detection setup completed.");
}

//----private------------------------------------------------------------------
GraphicDisplay::GraphicDisplay(PinName miso, PinName mosi, PinName clk, PinName cs, PinName dc, PinName rst, PinName touchCs, PinName touchIrq)
    : _misoPin(static_cast<int>(miso)),
      _mosiPin(static_cast<int>(mosi)),
      _clkPin(static_cast<int>(clk)),
      _csPin(static_cast<int>(cs)),
      _dcPin(static_cast<int>(dc)),
      _rstPin(static_cast<int>(rst)),
      _touchCsPin(static_cast<int>(touchCs)),
      _touchIrqPin(static_cast<int>(touchIrq))
{

}

} // namespace Drivers