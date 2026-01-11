/*!****************************************************************************
 * @file    PwmOut.h
 * @brief   Abstraction for ESP32 LEDC-based PWM output channel.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#pragma once

#include "driver/ledc.h"
#include "framework/pin_names.h"

class PwmOut
{
    public:
        /**
         * @brief Construct a PWM output on a given pin.
         * @param pin PinName where PWM signal will be output.
         * @param freq Frequency in Hz.
         * @param mode LEDC speed mode (LEDC_HIGH_SPEED_MODE or LEDC_LOW_SPEED_MODE).
         * @param resolution Resolution in bits (e.g. 8–15).
         * @param channel LEDC channel (0–7).
         * @param timer LEDC timer index (0–3).
         */
        PwmOut(PinName pin,
               uint32_t freq = 50,
               ledc_mode_t mode = LEDC_HIGH_SPEED_MODE,
               ledc_timer_bit_t resolution = LEDC_TIMER_10_BIT,
               ledc_channel_t channel = LEDC_CHANNEL_0,
               ledc_timer_t timer = LEDC_TIMER_0);

        /**
         * @brief Set duty cycle as a float (0.0–1.0).
         */
        void SetDuty(float duty);

        /**
         * @brief Fade smoothly to a duty cycle in a given time.
         * @param duty Duty cycle (0.0–1.0).
         * @param time_ms Transition time in milliseconds.
         */
        void FadeToDuty(float duty, uint32_t time_ms);

        /**
         * @brief Stop PWM output.
         */
        void Stop();

    private:

        PinName _pin;
        ledc_mode_t _mode;
        ledc_channel_t _channel;
        ledc_timer_t _timer;
        uint32_t _freq;
        ledc_timer_bit_t _resolution;
        uint32_t _maxDuty;
        bool _valid;

        static bool _fade_service_installed;
};