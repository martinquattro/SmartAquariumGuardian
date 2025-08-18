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

TdsSensor* TdsSensor::_instance = nullptr;

//----static-------------------------------------------------------------------
TdsSensor* TdsSensor::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void TdsSensor::Init()
{
    if (_instance == nullptr)
    {
        _instance = new TdsSensor(TDS_SENSOR_ADC_PIN);
    }

    _instance->_lastTdsReading = 0;
}

//-----------------------------------------------------------------------------
void TdsSensor::Update(const float temperature /* = 25.0*/)
{
    const float analogReading = _pin.ReadVoltage();
    const float avgAnalogReading = StoreAnalogReading(analogReading);

    // Logic to transform reading to ppm units
    // ppm = (133.42 * V³ - 255.86 * V² + 857.39 * V) / factorTemp * 0.5
    // factorTemp ≈ 1.0 + 0.02 * (temp - 25)
    float factorTemp = (1.0 + 0.02 * (temperature - 25.0));

    _lastTdsReading = (133.42 * pow(avgAnalogReading, 3) 
                     - 255.86 * pow(avgAnalogReading, 2) 
                     + 857.39 * avgAnalogReading) / factorTemp * 0.5;

    _lastTdsReading = std::clamp(_lastTdsReading, MIN_TDS_VALUE, MAX_TDS_VALUE);

    CORE_INFO("TdsSensor::Update - Analog Reading = %.4f V | Average: %.4f V | PPM = %d"
        , analogReading
        , avgAnalogReading
        , _lastTdsReading
    );
}

//-----------------------------------------------------------------------------
int TdsSensor::GetLastReading()
{
    return _lastTdsReading;
}

//----private------------------------------------------------------------------
float TdsSensor::StoreAnalogReading(const float reading)
{
    if (reading < 0.0f || reading > 3.3f)
    {
        CORE_ERROR("TdsSensor::StoreAnalogReading - Invalid analog reading: %.4f", reading);
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
        if ((*it) > 0.0)
        {
            tdsReadingSum += (*it);
            ++amountOfReadings;
        }
    }

    float avgAnalogReading = (tdsReadingSum / amountOfReadings);
    return avgAnalogReading;
}

//----private------------------------------------------------------------------
TdsSensor::TdsSensor(const PinName pin)
    : _pin(pin)
    , _analogReadingsVec(NUM_AVG_SAMPLES, -1.0)
    , _analogReadingsVecIter(_analogReadingsVec.begin())
{
}

} // namespace Drivers