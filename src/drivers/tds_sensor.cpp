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
    // const float analogReading = mPin.read_voltage();

    // // Add reading to vector
    // (*mReadingsVectorIter) = analogReading;

    // // Check if we were at last element of the readings vector
    // if (mReadingsVectorIter++ >= mReadingsVector.end())
    // {
    //     mReadingsVectorIter = mReadingsVector.begin();
    // }

    // // Obtain average
    // float tdsReadingSum = 0.0;
    // int amountOfReadings = 0;
    // for (auto it = mReadingsVector.begin(); it != mReadingsVector.end(); ++it) 
    // {
    //     if ((*it) > 0.0)
    //     {
    //         tdsReadingSum += (*it);
    //         ++amountOfReadings;
    //     }
    // }

    // float avgAnalogReading = (tdsReadingSum / amountOfReadings);

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
TdsSensor::TdsSensor(const PinName pin)
    : _pin(pin)
    , _readingsVector(TDS_SENSOR_NUM_AVG_SAMPLES, -1.0)
    , _readingsVectorIter(_readingsVector.begin())
{
}

} // namespace Drivers