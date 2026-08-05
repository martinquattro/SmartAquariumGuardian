/*!****************************************************************************
 * @file    analog_in.h
 * @brief   ADC input abstraction for ESP32 (ESP-IDF framework).
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include "esp_adc/adc_cali_scheme.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_oneshot.h"
#include "framework/pin_names.h"
#include <cstdint>

class AnalogIn
{
    public:

        /**
         * @brief Construct an AnalogIn instance.
         * @param pin   PinName for an ADC1-capable GPIO.
         * @param vref  Reference voltage in volts (default 1.1V).
         * @param atten ADC attenuation setting (default ADC_ATTEN_DB_12).
         */
        AnalogIn(PinName pin, float vref = 1.1f, adc_atten_t atten = ADC_ATTEN_DB_12);

        /**
         * @brief Destructor to release calibration resources.
         */
        ~AnalogIn();

        /**
         * @brief Read the averaged input voltage.
         * @param samples Number of samples to average.
         * @return Measured voltage in volts.
         */
        float ReadVoltage(const int samples = 64) const;

        /**
         * @brief Check whether ADC initialization succeeded.
         * @return true if the ADC channel is valid.
         */
        bool IsValid() const;

    private:

        bool PinToAdcChannel(PinName pin, adc_channel_t& out) const;

        static adc_oneshot_unit_handle_t _handle;
        adc_channel_t _channel;
        float _vref;
        adc_bitwidth_t _width;
        bool _valid;

        adc_cali_handle_t _cali_handle;
        bool _cali_enabled;
};
