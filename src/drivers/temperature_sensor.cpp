/*!****************************************************************************
 * @file    temperature_sensor.cpp
 * @brief   Implementation of DS18B20 temperature reading via OneWire class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "src/drivers/temperature_sensor.h"

#include "include/config.h"
#include <algorithm>

namespace Drivers {

TemperatureSensor* TemperatureSensor::_instance = nullptr;

//----static-------------------------------------------------------------------
TemperatureSensor* TemperatureSensor::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void TemperatureSensor::Init()
{
    CORE_INFO("Initializing TemperatureSensor...");

    if (_instance == nullptr)
    {
        _instance = new TemperatureSensor(Config::TEMP_SENSOR_PIN);
    }

    _instance->_lastReading = 0.0f;
}

//-----------------------------------------------------------------------------
void TemperatureSensor::Update()
{
    int16_t rawReading = GetRawReading();
    float rawReadingAvg = StoreReading(rawReading);

    // Convert raw temperature to Celsius
    _lastReading = (rawReadingAvg / 16.0f);

    // _lastTempReading = std::clamp(_lastTempReading, MIN_TEMP_VALUE, MAX_TEMP_VALUE);

    CORE_INFO("Raw Reading = %d | Average: %.4f V | Temp = %.3f °C"
        , rawReading
        , rawReadingAvg
        , _lastReading
    );
}

//----private------------------------------------------------------------------
int16_t TemperatureSensor::GetRawReading()
{
    if (!_oneWirePin.Reset())
    {
        CORE_ERROR("No DS18B20 detected!");
        return 0;
    }

    _oneWirePin.WriteByte(CMD_SKIP_ROM);
    _oneWirePin.WriteByte(CMD_CONVERT_T);

    // Wait for conversion (750 ms for 12-bit resolution)
    TaskDelayMs(750);

    if (!_oneWirePin.Reset())
    {
        CORE_ERROR("Lost device after conversion!");
        return 0;
    }

    _oneWirePin.WriteByte(CMD_SKIP_ROM);
    _oneWirePin.WriteByte(CMD_READ_SCRATCH);

    uint8_t tempLSB = _oneWirePin.ReadByte();
    uint8_t tempMSB = _oneWirePin.ReadByte();

    int16_t rawTemp = (tempMSB << 8) | tempLSB;
    return rawTemp;
}

//----private------------------------------------------------------------------
float TemperatureSensor::StoreReading(float reading)
{
    (*_rawReadingsVecIter) = reading;

    if (++_rawReadingsVecIter >= _rawReadingsVec.end())
    {
        _rawReadingsVecIter = _rawReadingsVec.begin();
    }

    float sum = 0.0f;
    int count = 0;
    for (auto val : _rawReadingsVec)
    {
        if (val > -100.0f)
        {
            sum += val;
            count++;
        }
    }
    
    return (count > 0) ? (sum / count) : reading;
}

//----private------------------------------------------------------------------
float TemperatureSensor::GetLastReading() const
{
    return _lastReading;
}

//----private------------------------------------------------------------------
TemperatureSensor::TemperatureSensor(const PinName pin)
    : _oneWirePin(pin)
    , _rawReadingsVec(NUM_AVG_SAMPLES, -1.0f)
    , _rawReadingsVecIter(_rawReadingsVec.begin())
{
}

} // namespace Drivers
