/*!****************************************************************************
 * @file    temperature_sensor.h
 * @brief   DS18B20 temperature sensor driver using OneWire class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "framework/common_defs.h"
#include "src/core/base/driver.h"
#include <vector>

namespace Drivers {

class TemperatureSensor : public Base::Singleton<TemperatureSensor>,
                          public Base::Driver
{
    public:

        /*!
         * @brief Get the last averaged temperature.
         * @return Temperature in Celsius.
         */
        float GetLastReading() const;

    protected:

        friend class Base::Singleton<TemperatureSensor>;

        TemperatureSensor();
        ~TemperatureSensor() = default;

        /*!
         * @brief Get the module name.
         * @return Module name.
         */
        const char* GetModuleName() const override { return "TemperatureSensor"; }

        /*!
         * @brief Initialize the module.
         * @return true when initialization succeeds.
         */
        bool OnInit() override;

        /*!
         * @brief Update the averaged sensor reading.
         */
        void OnUpdate() override;

        /*!
         * @brief Read a raw temperature value from the sensor.
         * @return Raw temperature in DS18B20 units.
         */
        virtual int16_t GetRawReading();

    private:

        uint8_t CalculateCRC8(const uint8_t* addr, uint8_t len);
        float StoreReading(float reading);

        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;

        static constexpr uint8_t CMD_SKIP_ROM = 0xCC;
        static constexpr uint8_t CMD_CONVERT_T = 0x44;
        static constexpr uint8_t CMD_READ_SCRATCH = 0xBE;

        static constexpr int NUM_AVG_SAMPLES = 12;
        static constexpr int16_t MIN_VALID_RAW_READING = 160;
        static constexpr float MIN_TEMP_VALUE = 10.0f;
        static constexpr float MAX_TEMP_VALUE = 85.0f;

        OneWire _oneWirePin;
        std::vector<float> _rawReadingsVec;
        std::vector<float>::iterator _rawReadingsVecIter;
        float _lastReading;
};

} // namespace Drivers

#endif // TEMPERATURE_SENSOR_H
