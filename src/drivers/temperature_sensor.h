/*!****************************************************************************
 * @file    temperature_sensor.h
 * @brief   DS18B20 temperature sensor driver using OneWire class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "framework/common_defs.h"
#include <vector>

namespace Drivers {

class TemperatureSensor
{
    public:
        /**
         * @brief Gets the singleton instance of the TemperatureSensor.
         * @return TemperatureSensor* Pointer to the TemperatureSensor instance.
         */
        static TemperatureSensor* GetInstance();

        /**
         * @brief Initializes the TemperatureSensor.
         *        This method should be called once at the start of the application.
         */
        static void Init();

        /**
         * @brief Request and read temperature from DS18B20.
         */
        void Update();

        /**
         * @brief Get last averaged temperature.
         * @return Temperature in Celsius.
         */
        float GetLastReading() const;

    private:

        /**
         * @brief Get raw temperature reading from the sensor.
         * @return int16_t Raw temperature value.
         */
        int16_t GetRawReading();

        /**
         * @brief Store a temperature reading and return the average of the stored readings.
         * @param reading The new temperature reading to store.
         * @return float The average of the stored temperature readings.
         */
        float StoreReading(float reading);

        using TempReadingsVec = std::vector<float>;

        TemperatureSensor(const PinName pin);
        ~TemperatureSensor() = default;
        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;

        static constexpr uint8_t CMD_SKIP_ROM     = 0xCC;
        static constexpr uint8_t CMD_CONVERT_T    = 0x44;
        static constexpr uint8_t CMD_READ_SCRATCH = 0xBE;

        static constexpr int NUM_AVG_SAMPLES      = 10;

        static constexpr float MIN_TEMP_VALUE   = 0.0f;
        static constexpr float MAX_TEMP_VALUE   = 100.0f;

        //---------------------------------------------

        static TemperatureSensor* _instance;
        OneWire _oneWirePin;

        TempReadingsVec _rawReadingsVec;
        TempReadingsVec::iterator _rawReadingsVecIter;

        float _lastReading;
};

} // namespace Drivers

#endif // TEMPERATURE_SENSOR_H
