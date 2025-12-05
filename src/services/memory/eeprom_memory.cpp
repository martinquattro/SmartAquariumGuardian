/*!****************************************************************************
 * @file    eeprom_memory.cpp
 * @brief   Implementation of EEPROM memory driver via I2C bus (e.g., AT24C32)
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/services/memory/eeprom_memory.h"

#include "framework/common_defs.h"
#include "include/config.h"
#include <vector>

namespace Services {

EepromMemory* EepromMemory::_instance = nullptr;

//----static-------------------------------------------------------------------
EepromMemory* EepromMemory::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void EepromMemory::Init()
{
    CORE_INFO("Initializing EepromMemory...");

    if (_instance != nullptr)
    {
        CORE_ERROR("EepromMemory already initialized!");
        return;
    }

    _instance = new EepromMemory(
          Config::I2C_SDA_PIN
        , Config::I2C_SCL_PIN
        , Config::EEPROM_I2C_ADDRESS
    );
}

//-----------------------------------------------------------------------------
bool EepromMemory::WriteBytes(uint16_t address, const uint8_t* data, size_t length)
{
    if (address + length > EEPROM_SIZE_BYTES)
    {
        CORE_ERROR("Write out of bounds");
        return false;
    }

    uint16_t currentAddress = address;
    size_t bytesWritten = 0;

    while (bytesWritten < length)
    {
        uint16_t pageOffset = currentAddress % BYTES_PER_PAGE;
        size_t bytesCanWrite = BYTES_PER_PAGE - pageOffset;
        size_t bytesToWrite = std::min(bytesCanWrite, length - bytesWritten);

        if (!WritePageInternal(currentAddress, &data[bytesWritten], bytesToWrite))
        {
            return false;
        }

        currentAddress += bytesToWrite;
        bytesWritten += bytesToWrite;
    }

    return true;
}

//-----------------------------------------------------------------------------
bool EepromMemory::ReadBytes(uint16_t address, uint8_t* buffer, size_t length)
{
    if (address + length > EEPROM_SIZE_BYTES)
    {
        CORE_ERROR("Read out of bounds");
        return false;
    }

    uint8_t addrPtr[2];
    addrPtr[0] = (address >> 8) & 0xFF;
    addrPtr[1] = address & 0xFF;

    if (!_i2c.Write(addrPtr, 2))
    {
        CORE_ERROR("Failed to set read address");
        return false;
    }

    if (!_i2c.Read(buffer, length))
    {
        CORE_ERROR("Failed to read data");
        return false;
    }
    return true;
}

//----private------------------------------------------------------------------
bool EepromMemory::WritePageInternal(uint16_t memAddress, const uint8_t* data, size_t length)
{
    std::vector<uint8_t> buffer(2 + length);
    buffer[0] = (memAddress >> 8) & 0xFF;
    buffer[1] = memAddress & 0xFF;
    memcpy(&buffer[2], data, length);

    if (!_i2c.Write(buffer.data(), buffer.size()))
    {
        CORE_ERROR("Write failed");
        return false;
    }

    TaskDelayMs(10);
    return true;
}

//----private------------------------------------------------------------------
EepromMemory::EepromMemory(PinName sda, PinName scl, uint8_t address)
    : _i2c(sda, scl, address)
{}

} // namespace Services
