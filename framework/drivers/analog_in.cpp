/*!****************************************************************************
 * @file    analog_in.cpp
 * @brief   Implementation of AnalogIn using ESP-IDF adc_oneshot driver.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "framework/drivers/analog_in.h"
#include "esp_err.h"

//-----------------------------------------------------------------------------
AnalogIn::AnalogIn(PinName pin, float vref, adc_atten_t atten)
    : _vref(vref)
    , _width(ADC_BITWIDTH_12)
    , _valid(false)
{
    if (PinToAdcChannel(pin, _channel)) 
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
                adc_cali_line_fitting_config_t cal_cfg = 
                {
                    .unit_id = ADC_UNIT_1,
                    .atten = atten,
                    .bitwidth = ADC_BITWIDTH_DEFAULT,
                    .default_vref = static_cast<uint32_t>(_vref * 1000.0f)
                };

                if (adc_cali_create_scheme_line_fitting(&cal_cfg, &_cali) == ESP_OK)
                {
                    _valid = true;
                }
            }
        }
    }
}

//-----------------------------------------------------------------------------
float AnalogIn::ReadVoltage(const int samples) const
{
    if (!_valid) return 0;

    int raw = 0;
    int sumRaw = 0;
    int count = 0;
    for (size_t i = 0; i < samples; i++)
    {
        if (adc_oneshot_read(_handle, _channel, &raw) == ESP_OK) 
        {
            sumRaw += raw;
            count++;
        }
    }

    const float avgRaw = static_cast<float>(sumRaw) / count;
    
    int mv = 0;
    if (adc_cali_raw_to_voltage(_cali, avgRaw, &mv) == ESP_OK)
    {
        return mv / 1000.0f;
    }

    const int max_raw = (1 << _width) - 1;
    float volts = (static_cast<float>(avgRaw) / static_cast<float>(max_raw)) * _vref;

    return static_cast<int>(volts * 1000.0f + 0.5f);
}

//-----------------------------------------------------------------------------
bool AnalogIn::IsValid() const
{
    return _valid;
}

//----private------------------------------------------------------------------
bool AnalogIn::PinToAdcChannel(PinName pin, adc_channel_t& out) const
{
    switch (pin) 
    {
        case PinName::P36:      out = ADC_CHANNEL_0;        return true;
        case PinName::P39:      out = ADC_CHANNEL_3;        return true;
        case PinName::P32:      out = ADC_CHANNEL_4;        return true;
        case PinName::P33:      out = ADC_CHANNEL_5;        return true;
        case PinName::P34:      out = ADC_CHANNEL_6;        return true;
        case PinName::P35:      out = ADC_CHANNEL_7;        return true;
        default: return false;
    }
}
