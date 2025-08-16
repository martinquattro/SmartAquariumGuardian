/*!****************************************************************************
 * @file    analog_in.h
 * @brief   GPIO analog input class for ESP32 (ESP-IDF framework).
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
         * @param pin   PinName corresponding to an ADC1-capable GPIO.
         * @param vref  Reference voltage in volts (default 3.3V).
         * @param atten Attenuation setting for ADC channel (default ADC_ATTEN_DB_12).
         */
        AnalogIn(PinName pin, float vref = 3.3f, adc_atten_t atten = ADC_ATTEN_DB_12);

        /**
         * @brief Read ADC value in volts.
         */
        float ReadVoltage() const;



        /**
         * @brief Check if this instance is valid (pin supports ADC1).
         */
        bool IsValid() const;

    private:

        /**
         * @brief Read ADC value in millivolts, calibrated.
         */
        int ReadCalibrated() const;

        /**
         * @brief Convert pin name to ADC1 channel.
         * @param pin PinName to convert.
         * @param out Output channel.
         * @return true if conversion was successful, false otherwise.
         */
        bool PinToAdcChannel(PinName pin, adc_channel_t& out) const;

        adc_oneshot_unit_handle_t _handle{};
        adc_channel_t _channel{};
        float _vref;
        adc_bitwidth_t _width;
        bool _valid;

        adc_cali_handle_t _cali{};
};