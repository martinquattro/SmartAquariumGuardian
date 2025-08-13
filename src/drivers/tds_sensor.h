/*!****************************************************************************
 * @file    tds_sensor.h
 * @brief   TdsSensor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include <vector>
#include "framework/commondefs.h"

#define TDS_SENSOR_NUM_AVG_SAMPLES 20
#define MIN_TDS_VALUE  0.0
#define MAX_TDS_VALUE  999

namespace Drivers { 

    class TdsSensor 
    {
        public:

            //! Returns the singleton instance of the TDS sensor.
            static TdsSensor* GetInstance();

            //! Initialize the TDS sensor.
            static void Init();

            //! Update the TDS sensor readings.
            void Update(const float temperature = 25.0);

            //! Get the last TDS reading.
            int GetLastReading();

        private:

            using TdsReadingsVec = std::vector<float>;

            TdsSensor(const PinName pin);
            ~TdsSensor() = default;
            TdsSensor(const TdsSensor&) = delete;
            TdsSensor& operator=(const TdsSensor&) = delete;

            static TdsSensor* _instance;
            AnalogIn _pin;
            
            TdsReadingsVec _readingsVector;
            TdsReadingsVec::iterator _readingsVectorIter;
            float _temperature;
            float _ref;
            float _adcRange;
            float _kValue;
            int   _lastReading;
    };

} // namespace Drivers

#endif // TDS_SENSOR_H