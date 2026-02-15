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

        /**
         * @brief Get last averaged temperature.
         * @return Temperature in Celsius.
         */
        float GetLastReading() const;

    protected:

        friend class Base::Singleton<TemperatureSensor>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "TemperatureSensor"; }

        /*!
        * @brief Initializes the Module.
        *        This method should be called once at the start of the application.
        *       * @return bool True if initialization successful, false otherwise.
        */
        bool OnInit() override;

        /*!
        * @brief Updates the Module state.
        *        This method should be called periodically to update the system state.
        */
        void OnUpdate() override;

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

        /**
         * @brief Calculate CRC8 for data validation.
         * @param addr Pointer to the data array.
         * @param len Length of the data array.
         * @return uint8_t Calculated CRC8 value.
         */
        uint8_t CalculateCRC8(const uint8_t *addr, uint8_t len);

        using TempReadingsVec = std::vector<float>;

        //---------------------------------------------

        TemperatureSensor();
        ~TemperatureSensor() = default;
        TemperatureSensor(const TemperatureSensor&) = delete;
        TemperatureSensor& operator=(const TemperatureSensor&) = delete;

        //---------------------------------------------

        static constexpr uint8_t CMD_SKIP_ROM     = 0xCC;
        static constexpr uint8_t CMD_CONVERT_T    = 0x44;
        static constexpr uint8_t CMD_READ_SCRATCH = 0xBE;

        static constexpr int NUM_AVG_SAMPLES      = 10;

        static constexpr float MIN_TEMP_VALUE   = 0.0f;
        static constexpr float MAX_TEMP_VALUE   = 85.0f;

        //---------------------------------------------

        OneWire _oneWirePin;

        TempReadingsVec _rawReadingsVec;
        TempReadingsVec::iterator _rawReadingsVecIter;

        float _lastReading;
};

} // namespace Drivers

#endif // TEMPERATURE_SENSOR_H
