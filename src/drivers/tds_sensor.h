/*!****************************************************************************
 * @file    tds_sensor.h
 * @brief   TdsSensor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include "src/core/base/driver.h"
#include "framework/common_defs.h"
#include <vector>

namespace Drivers { 

class TdsSensor : public Base::Singleton<TdsSensor>,
                  public Base::Driver
{
    public:

        /*!
            * @brief Gets the last TDS reading.
            * @return int Last TDS reading.
            */
        int GetLastReading();

        /**
         * @brief Set the current temperature for compensation calculations.
         * @param temperature The current temperature in Celsius.
         */
        void SetTemperature(float temperature) { _temperature = temperature; }

    protected:

        friend class Base::Singleton<TdsSensor>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "TdsSensor"; }

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
    
        /*!
        * @brief Stores an analog reading and returns the average of the stored readings.
        * @param reading The new analog reading to store.
        * @return float The average of the stored analog readings.
        */
        float StoreAnalogReading(const float reading);

        using TdsReadingsVec = std::vector<float>;
    
        //---------------------------------------------

        TdsSensor();
        ~TdsSensor() = default;
        TdsSensor(const TdsSensor&) = delete;
        TdsSensor& operator=(const TdsSensor&) = delete;

        //---------------------------------------------

        static constexpr int NUM_AVG_SAMPLES = 20;
        
        static constexpr int MIN_TDS_VALUE   = 0;
        static constexpr int MAX_TDS_VALUE   = 999;

        //---------------------------------------------

        AnalogIn _analogInPin;
        
        TdsReadingsVec _analogReadingsVec;
        TdsReadingsVec::iterator _analogReadingsVecIter;
        
        float _temperature;
        int _lastReading;
};

} // namespace Drivers

#endif // TDS_SENSOR_H