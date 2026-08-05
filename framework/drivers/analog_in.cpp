/*!****************************************************************************
 * @file    analog_in.cpp
 * @brief   Implementation of the AnalogIn ADC wrapper for ESP32.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#include "framework/drivers/analog_in.h"
#include "esp_err.h"
#include "esp_log.h"

adc_oneshot_unit_handle_t AnalogIn::_handle = nullptr;

//-----------------------------------------------------------------------------
AnalogIn::AnalogIn(PinName pin, float vref, adc_atten_t atten)
    : _vref(vref)
    , _width(ADC_BITWIDTH_12)
    , _valid(false)
    , _cali_handle(nullptr)
    , _cali_enabled(false)
{
    if (PinToAdcChannel(pin, _channel))
    {
        if (_handle == nullptr)
        {
            adc_oneshot_unit_init_cfg_t init_cfg;
            init_cfg.unit_id = ADC_UNIT_1;
            init_cfg.clk_src = ADC_RTC_CLK_SRC_DEFAULT;
            init_cfg.ulp_mode = ADC_ULP_MODE_DISABLE;

            esp_err_t err = adc_oneshot_new_unit(&init_cfg, &_handle);
            if (err != ESP_OK)
            {
                return;
            }
        }

        adc_oneshot_chan_cfg_t chan_cfg;
        chan_cfg.atten = atten;
        chan_cfg.bitwidth = _width;

        if (adc_oneshot_config_channel(_handle, _channel, &chan_cfg) == ESP_OK)
        {
            _valid = true;
        }

        adc_cali_line_fitting_config_t cali_cfg;
        cali_cfg.unit_id = ADC_UNIT_1;
        cali_cfg.atten = atten;
        cali_cfg.bitwidth = _width;
        cali_cfg.default_vref = static_cast<uint32_t>(_vref * 1000.0f);

        esp_err_t cali_err = adc_cali_create_scheme_line_fitting(&cali_cfg, &_cali_handle);
        if (cali_err == ESP_OK)
        {
            _cali_enabled = true;
        }
    }
}

//-----------------------------------------------------------------------------
AnalogIn::~AnalogIn()
{
    if (_cali_handle != nullptr)
    {
        adc_cali_delete_scheme_line_fitting(_cali_handle);
    }
}

//-----------------------------------------------------------------------------
float AnalogIn::ReadVoltage(const int samples) const
{
    if (!_valid)
    {
        return 0.0f;
    }

    int accumulatedRaw = 0;
    int rawValue = 0;

    for (int i = 0; i < samples; ++i)
    {
        if (adc_oneshot_read(_handle, _channel, &rawValue) == ESP_OK)
        {
            accumulatedRaw += rawValue;
        }
    }

    int averageRaw = accumulatedRaw / samples;

    if (_cali_enabled && _cali_handle != nullptr)
    {
        int voltageMv = 0;
        if (adc_cali_raw_to_voltage(_cali_handle, averageRaw, &voltageMv) == ESP_OK)
        {
            return static_cast<float>(voltageMv) / 1000.0f;
        }
    }

    return (static_cast<float>(averageRaw) * _vref) / 4095.0f;
}

//-----------------------------------------------------------------------------
bool AnalogIn::IsValid() const
{
    return _valid;
}

//-----------------------------------------------------------------------------
bool AnalogIn::PinToAdcChannel(PinName pin, adc_channel_t& out) const
{
    switch (pin)
    {
        case PinName::P36: out = ADC_CHANNEL_0; return true;
        case PinName::P39: out = ADC_CHANNEL_3; return true;
        case PinName::P32: out = ADC_CHANNEL_4; return true;
        case PinName::P33: out = ADC_CHANNEL_5; return true;
        case PinName::P34: out = ADC_CHANNEL_6; return true;
        case PinName::P35: out = ADC_CHANNEL_7; return true;
        default: return false;
    }
}
