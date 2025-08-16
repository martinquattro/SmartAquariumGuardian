/*!****************************************************************************
 * @file    tds_sensor.cpp
 * @brief   Implementation of the TdsSensor class functions.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "src/drivers/tds_sensor.h"

#include "include/config.h"

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

    _instance->_temperature = 25.0;
    _instance->_adcRange = 1024.0;
    _instance->_ref = 5.0;
    _instance->_kValue = 1.0;
    _instance->_lastReading = 0;
}

//-----------------------------------------------------------------------------
void TdsSensor::Update(const float temperature /* = 25.0*/)
{
    const float analogReading = _pin.ReadVoltage();

    float avgAnalogReading = StoreAnalogReading(analogReading);

    CORE_TRACE("TdsSensor - Average read voltage: %.4f V", avgAnalogReading);

    // // Logic to transform reading to ppm units
    // const float voltage = avgAnalogReading * mRef;
    // const float ecValue = ((133.42 * voltage * voltage * voltage) - (255.86 * voltage * voltage) + (857.39 * voltage)) * mKValue;
    // const float ecValue25 = ecValue / (1.0 + 0.02 * (temperature - 25.0));  // Temperature compensation
    // const int tdsValue = ecValue25 * 0.5;

    // // check if we are out of boundaries
    // if (tdsValue < MIN_TDS_VALUE)
    // {
    //     mLastReading = MIN_TDS_VALUE;
    // }
    // else if (tdsValue > MAX_TDS_VALUE)
    // {
    //     mLastReading = MAX_TDS_VALUE;
    // }
    // else
    // {
    //     mLastReading = tdsValue;
    // }
}

//-----------------------------------------------------------------------------
int TdsSensor::GetLastReading()
{
    return _lastReading;
}

//----private------------------------------------------------------------------
float TdsSensor::StoreAnalogReading(const float reading)
{
    if (reading < 0.0f || reading > _ref)
    {
        CORE_ERROR("TdsSensor::StoreAnalogReading - Invalid analog reading: %.4f", reading);
        return 0.0f;
    }

    // Add reading to vector
    (*_readingsVectorIter) = reading;

    // Check if we were at last element of the readings vector
    if (_readingsVectorIter++ >= _readingsVector.end())
    {
        _readingsVectorIter = _readingsVector.begin();
    }

    // Obtain average
    float tdsReadingSum = 0.0;
    int amountOfReadings = 0;
    for (auto it = _readingsVector.begin(); it != _readingsVector.end(); ++it) 
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
    , _readingsVector(NUM_AVG_SAMPLES, -1.0)
    , _readingsVectorIter(_readingsVector.begin())
{
}

} // namespace Drivers