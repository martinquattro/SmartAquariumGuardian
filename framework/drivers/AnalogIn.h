#pragma once
/*!****************************************************************************
 * @file    AnalogIn.h
 * @brief   GPIO analog input class for ESP32 (ESP-IDF framework).
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include <cstdint>
#include "esp_adc/adc_oneshot.h"
#include "PinNames.h"

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
         * @brief Read normalized value from ADC (0.0 to 1.0).
         */
        float Read() const;

        /**
         * @brief Read ADC value scaled to 16-bit range (0 to 65535).
         */
        uint16_t Read_u16() const;

        /**
         * @brief Read ADC value in volts.
         */
        float ReadVoltage() const;

        /**
         * @brief Check if this instance is valid (pin supports ADC1).
         */
        bool IsValid() const;

    private:

        static bool pin_to_adc1_channel(PinName pin, adc_channel_t& out);

        adc_oneshot_unit_handle_t _handle{};
        adc_channel_t _channel{};
        float _vref;
        adc_bitwidth_t _width;
        bool _valid;
};