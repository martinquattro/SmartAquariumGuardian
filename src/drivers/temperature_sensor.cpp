/*!****************************************************************************
 * @file    temperature_sensor.cpp
 * @brief   Implementation of DS18B20 temperature reading via OneWire class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "temperature_sensor.h"

#include "include/config.h"
#include <algorithm>

namespace Drivers {

//----private------------------------------------------------------------------
bool TemperatureSensor::OnInit()
{
    _rawReadingsVec.assign(NUM_AVG_SAMPLES, -1.0f);
    _rawReadingsVecIter = _rawReadingsVec.begin();
    _lastReading = 0.0f;
    return true;
}

//----private------------------------------------------------------------------
void TemperatureSensor::OnUpdate()
{
    const int16_t rawReading = GetRawReading();
    if (rawReading < MIN_VALID_RAW_READING)
    {
        CORE_ERROR("Temperature reading is invalid or below the 10 C minimum.");
        return;
    }

    const float rawReadingAvg = StoreReading(rawReading);
    _lastReading = rawReadingAvg / 16.0f;
    _lastReading = std::clamp(_lastReading, MIN_TEMP_VALUE, MAX_TEMP_VALUE);

    CORE_INFO("Temperature avg reading - Celsius = %.2f", _lastReading);
}

//-----------------------------------------------------------------------------
float TemperatureSensor::GetLastReading() const
{
    return _lastReading;
}

//----protected----------------------------------------------------------------
int16_t TemperatureSensor::GetRawReading()
{
    if (!_oneWirePin.Reset())
    {
        CORE_ERROR("No DS18B20 detected!");
        return 0;
    }

    _oneWirePin.WriteByte(CMD_SKIP_ROM);
    _oneWirePin.WriteByte(CMD_CONVERT_T);
    TaskDelayMs(750);

    if (!_oneWirePin.Reset())
    {
        CORE_ERROR("Lost device after conversion!");
        return 0;
    }

    _oneWirePin.WriteByte(CMD_SKIP_ROM);
    _oneWirePin.WriteByte(CMD_READ_SCRATCH);

    uint8_t scratchpad[9];
    for (int i = 0; i < 9; ++i)
    {
        scratchpad[i] = _oneWirePin.ReadByte();
    }

    const uint8_t crcCalculated = CalculateCRC8(scratchpad, 8);
    if (crcCalculated != scratchpad[8])
    {
        CORE_ERROR("DS18B20 CRC check failed! Calculated: 0x%02X, Received: 0x%02X",
                   crcCalculated, scratchpad[8]);
        return -1;
    }

    return static_cast<int16_t>((scratchpad[1] << 8) | scratchpad[0]);
}

//----private------------------------------------------------------------------
float TemperatureSensor::StoreReading(float reading)
{
    *_rawReadingsVecIter = reading;

    if (++_rawReadingsVecIter >= _rawReadingsVec.end())
    {
        _rawReadingsVecIter = _rawReadingsVec.begin();
    }

    float sum = 0.0f;
    int count = 0;
    for (const float value : _rawReadingsVec)
    {
        if (value > -1.0f)
        {
            sum += value;
            ++count;
        }
    }

    return count > 0 ? sum / count : reading;
}

//----private------------------------------------------------------------------
uint8_t TemperatureSensor::CalculateCRC8(const uint8_t* addr, uint8_t len)
{
    uint8_t crc = 0;

    for (uint8_t i = 0; i < len; ++i)
    {
        uint8_t inbyte = addr[i];
        for (uint8_t j = 0; j < 8; ++j)
        {
            const uint8_t mix = (crc ^ inbyte) & 0x01;
            crc >>= 1;
            if (mix)
            {
                crc ^= 0x8C;
            }
            inbyte >>= 1;
        }
    }

    return crc;
}

//----private------------------------------------------------------------------
TemperatureSensor::TemperatureSensor()
    : _oneWirePin(Config::TEMP_SENSOR_PIN)
    , _rawReadingsVec(NUM_AVG_SAMPLES, -1.0f)
    , _rawReadingsVecIter(_rawReadingsVec.begin())
    , _lastReading(0.0f)
{
}

} // namespace Drivers
