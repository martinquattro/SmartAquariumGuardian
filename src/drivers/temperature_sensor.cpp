/*!****************************************************************************
 * @file    temperature_sensor.cpp
 * @brief   Implementation of DS18B20 temperature reading via OneWire class.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "src/drivers/temperature_sensor.h"

#include "include/config.h"
#include <algorithm>
#include <cmath>

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

    if (_instance != nullptr)
    {
        CORE_ERROR("TemperatureSensor already initialized!");
        return;
    }

    _instance = new TemperatureSensor(Config::TEMP_SENSOR_PIN);
    _instance->_lastReading = 0.0f;
}

//-----------------------------------------------------------------------------
void TemperatureSensor::Update()
{
    int16_t rawReading = GetRawReading();
    if (rawReading == -1)
    {
        CORE_ERROR("Failed to get valid temperature reading!");
        return;
    }
    
    float rawReadingAvg = StoreReading(rawReading);

    // Convert raw temperature to Celsius
    _lastReading = (rawReadingAvg / 16.0f);
    _lastReading = std::clamp(_lastReading, MIN_TEMP_VALUE, MAX_TEMP_VALUE);

    CORE_INFO("Raw Reading = %d | Average: %.2f | Temp = %.2f °C"
        , rawReading
        , rawReadingAvg
        , _lastReading
    );
}

//-----------------------------------------------------------------------------
float TemperatureSensor::GetLastReading() const
{
    // return (rand() % 4000 / 100.0f);
    return _lastReading;
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

    uint8_t scratchpad[9];
    for (int i = 0; i < 9; i++)
    {
        scratchpad[i] = _oneWirePin.ReadByte();
    }

    // Verify CRC
    uint8_t crcCalculated = CalculateCRC8(scratchpad, 8);
    if (crcCalculated != scratchpad[8])
    {
        CORE_ERROR("DS18B20 CRC check failed! Calculated: 0x%02X, Received: 0x%02X", crcCalculated, scratchpad[8]);
        return -1;
    }

    uint8_t tempLSB = scratchpad[0];
    uint8_t tempMSB = scratchpad[1];

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
        if (val > -1.0f)
        {
            sum += val;
            count++;
        }
    }
    
    return (count > 0) ? (sum / count) : reading;
}

//----private------------------------------------------------------------------
uint8_t TemperatureSensor::CalculateCRC8(const uint8_t *addr, uint8_t len)
{
    uint8_t crc = 0;

    for (uint8_t i = 0; i < len; i++)
    {
        uint8_t inbyte = addr[i];
        for (uint8_t j = 0; j < 8; j++)
        {
            uint8_t mix = (crc ^ inbyte) & 0x01;
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
TemperatureSensor::TemperatureSensor(const PinName pin)
    : _oneWirePin(pin)
    , _rawReadingsVec(NUM_AVG_SAMPLES, -1.0f)
    , _rawReadingsVecIter(_rawReadingsVec.begin())
{
}

} // namespace Drivers
