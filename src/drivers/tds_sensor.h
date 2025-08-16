/*!****************************************************************************
 * @file    tds_sensor.h
 * @brief   TdsSensor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include "framework/common_defs.h"
#include <vector>

namespace Drivers { 

    class TdsSensor 
    {
        public:

            /*!
             * @brief Gets the singleton instance of the TdsSensor.
             * @return TdsSensor* Pointer to the TdsSensor instance.
             */
            static TdsSensor* GetInstance();

            /*!
             * @brief Initializes the TdsSensor.
             */
            static void Init();

            //! TODO
            void Update(const float temperature = 25.0);

            /*!
             * @brief Gets the last TDS reading.
             * @return int Last TDS reading.
             */
            int GetLastReading();

        private:

            /*!
             * @brief Stores an analog reading and returns the average of the stored readings.
             * @param reading The new analog reading to store.
             * @return float The average of the stored analog readings.
             */
            float StoreAnalogReading(const float reading);

            using TdsReadingsVec = std::vector<float>;
            
            TdsSensor(const PinName pin);
            ~TdsSensor() = default;
            TdsSensor(const TdsSensor&) = delete;
            TdsSensor& operator=(const TdsSensor&) = delete;

            static constexpr int NUM_AVG_SAMPLES = 20;
            static constexpr int MIN_TDS_VALUE   = 0;
            static constexpr int MAX_TDS_VALUE   = 999;

            //---------------------------------------------

            static TdsSensor* _instance;
            AnalogIn _pin;
            
            TdsReadingsVec _analogReadingsVec;
            TdsReadingsVec::iterator _analogReadingsVecIter;
            
            int   _lastTdsReading;
    };

} // namespace Drivers

#endif // TDS_SENSOR_H