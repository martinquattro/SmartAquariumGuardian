/*!****************************************************************************
 * @file    PwmOut.cpp
 * @brief   Implementation of the PwmOut class using ESP32 LEDC driver.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "framework/drivers/pwm_out.h"

//-----------------------------------------------------------------------------
PwmOut::PwmOut(PinName pin, uint32_t freq, ledc_mode_t mode, ledc_timer_bit_t resolution,
               ledc_channel_t channel, ledc_timer_t timer)
    : _pin(pin)
    , _mode(mode)
    , _channel(channel)
    , _timer(timer)
    , _freq(freq)
    , _resolution(resolution)
    , _valid(false)
{
    _maxDuty = (1 << _resolution) - 1;

    // Configure timer
    ledc_timer_config_t timer_conf = 
    {
        .speed_mode = _mode,
        .duty_resolution = _resolution,
        .timer_num = _timer,
        .freq_hz = _freq,
        .clk_cfg = LEDC_AUTO_CLK,
        .deconfigure = false
    };
    
    if (ledc_timer_config(&timer_conf) == ESP_OK) 
    {
        ledc_channel_config_t channel_conf = 
        {
            .gpio_num = (int)_pin,
            .speed_mode = _mode,
            .channel = _channel,
            .intr_type = LEDC_INTR_FADE_END,
            .timer_sel = _timer,
            .duty = 0,
            .hpoint = 0,
            .sleep_mode = LEDC_SLEEP_MODE_NO_ALIVE_NO_PD,
            .flags = 
            {
                .output_invert = 0 // No output inversion by default
            }
        };

        if (ledc_channel_config(&channel_conf) == ESP_OK && 
            ledc_fade_func_install(0) == ESP_OK)
        {
            _valid = true;
        }
    }
}

//-----------------------------------------------------------------------------
void PwmOut::SetDuty(float duty)
{
    if (duty < 0.0f) 
    {
        duty = 0.0f;
    }

    if (duty > 1.0f) 
    {
        duty = 1.0f;
    }

    uint32_t val = (duty * _maxDuty);

    ledc_set_duty(_mode, _channel, val);
    ledc_update_duty(_mode, _channel);
}

//-----------------------------------------------------------------------------
void PwmOut::FadeToDuty(float duty, uint32_t timeMs)
{
    if (duty < 0.0f) 
    {
        duty = 0.0f;
    }

    if (duty > 1.0f) 
    {
        duty = 1.0f;
    }

    uint32_t val = (duty * _maxDuty);

    ledc_set_fade_with_time(_mode, _channel, val, timeMs);
    ledc_fade_start(_mode, _channel, LEDC_FADE_WAIT_DONE);
}

//-----------------------------------------------------------------------------
void PwmOut::Stop()
{
    ledc_stop(_mode, _channel, 0);
}