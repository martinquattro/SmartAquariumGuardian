/*!****************************************************************************
 * @file    tds_sensor.cpp
 * @brief   Implementation of the TdsSensor class functions.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "src/drivers/tds_sensor.h"

#include "include/config.h"
#include <algorithm>
#include <cmath>

namespace Drivers {

//----private------------------------------------------------------------------
bool TdsSensor::OnInit()
{
    _temperature = 25.0f; // Default to 25°C for initial readings
    _lastReading = 0;
    return true;
}

//-----------------------------------------------------------------------------
void TdsSensor::OnUpdate()
{
    const float K_CAL = 0.745f;

    const float analogReading = _analogInPin.ReadVoltage(64);
    float avgAnalogReading = StoreAnalogReading(analogReading);

    // Logic to transform reading to ppm units
    // ppm = (133.42 * V³ - 255.86 * V² + 857.39 * V) / factorTemp * 0.5
    // factorTemp ≈ 1.0 + 0.02 * (temp - 25)
    float factorTemp = (1.0 + 0.02 * (_temperature - 25.0));
    avgAnalogReading /= factorTemp; // Adjust for temperature compensation

    // CORE_INFO("TdsSensor: Analog reading = %.4f, Avg reading = %.4f, Temp = %.2f°C, FactorTemp = %.4f", analogReading, avgAnalogReading, _temperature, factorTemp);

    _lastReading = K_CAL *(133.42 * pow(avgAnalogReading, 3) 
                     - 255.86 * pow(avgAnalogReading, 2) 
                     + 857.39 * avgAnalogReading) * 0.5;


    CORE_INFO("Tds avg reading - PPM = %d at %.2f°C", _lastReading, _temperature);
}

//-----------------------------------------------------------------------------
int TdsSensor::GetLastReading()
{
    // return rand() % 1000;
    return _lastReading;
}

//----private------------------------------------------------------------------
float TdsSensor::StoreAnalogReading(const float reading)
{
    if (reading < 0.0f || reading > 3.3f)
    {
        CORE_ERROR("Invalid analog reading: %.4f", reading);
        return 0.0f;
    }

    // Add reading to vector
    (*_analogReadingsVecIter) = reading;

    // Check if we were at last element of the readings vector
    if (_analogReadingsVecIter++ >= _analogReadingsVec.end())
    {
        _analogReadingsVecIter = _analogReadingsVec.begin();
    }

    // Obtain average
    float tdsReadingSum = 0.0;
    int amountOfReadings = 0;
    for (auto it = _analogReadingsVec.begin(); it != _analogReadingsVec.end(); ++it) 
    {
        if ((*it) > -1.0f)
        {
            tdsReadingSum += (*it);
            ++amountOfReadings;
        }
    }

    float avgAnalogReading = (tdsReadingSum / amountOfReadings);
    return avgAnalogReading;
}

//----private------------------------------------------------------------------
TdsSensor::TdsSensor()
    : _analogInPin(Config::TDS_SENSOR_ADC_PIN)
    , _analogReadingsVec(NUM_AVG_SAMPLES, -1.0)
    , _analogReadingsVecIter(_analogReadingsVec.begin())
{
}

} // namespace Drivers