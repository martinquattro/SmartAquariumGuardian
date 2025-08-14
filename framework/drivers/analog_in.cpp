/*!****************************************************************************
 * @file    analog_in.cpp
 * @brief   Implementation of AnalogIn using ESP-IDF adc_oneshot driver.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "analog_in.h"
#include "esp_err.h"

//-----------------------------------------------------------------------------
AnalogIn::AnalogIn(PinName pin, float vref, adc_atten_t atten)
    : _vref(vref)
    , _width(ADC_BITWIDTH_12)
    , _valid(false)
{
    if (pin_to_adc1_channel(pin, _channel)) 
    {
        adc_oneshot_unit_init_cfg_t init_cfg = 
        {
            .unit_id = ADC_UNIT_1,
            .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
            .ulp_mode = ADC_ULP_MODE_DISABLE
        };

        if (adc_oneshot_new_unit(&init_cfg, &_handle) == ESP_OK) 
        {
            adc_oneshot_chan_cfg_t chan_cfg = 
            {
                .atten = atten,
                .bitwidth = _width
            };

            if (adc_oneshot_config_channel(_handle, _channel, &chan_cfg) == ESP_OK)
            {
                _valid = true;
            }
        }
    }
}

//-----------------------------------------------------------------------------
float AnalogIn::Read() const
{
    if (!_valid) return 0.0f;

    int raw = 0;

    if (adc_oneshot_read(_handle, _channel, &raw) != ESP_OK) 
    {
        return 0.0f;
    }

    const int max_raw = (1 << _width) - 1;
    float x = static_cast<float>(raw) / static_cast<float>(max_raw);

    return (x < 0.0f) ? 0.0f : (x > 1.0f ? 1.0f : x);
}

//-----------------------------------------------------------------------------
uint16_t AnalogIn::Read_u16() const
{
    float norm = Read();
    uint32_t u = static_cast<uint32_t>(norm * 65535.0f + 0.5f);

    return (u > 65535) ? 65535 : static_cast<uint16_t>(u);
}

//-----------------------------------------------------------------------------
float AnalogIn::ReadVoltage() const
{
    return Read() * _vref;
}

//-----------------------------------------------------------------------------
bool AnalogIn::IsValid() const
{
    return _valid;
}

//----private------------------------------------------------------------------
bool AnalogIn::pin_to_adc1_channel(PinName pin, adc_channel_t& out)
{
    switch (pin) 
    {
        case P36: out = ADC_CHANNEL_0; return true;
        case P39: out = ADC_CHANNEL_3; return true;
        case P32: out = ADC_CHANNEL_4; return true;
        case P33: out = ADC_CHANNEL_5; return true;
        case P34: out = ADC_CHANNEL_6; return true;
        case P35: out = ADC_CHANNEL_7; return true;
        default: return false;
    }
}
