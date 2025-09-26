/*!****************************************************************************
 * @file    eeprom_memory.cpp
 * @brief   Implementation of EEPROM memory driver via I2C bus (e.g., AT24C32)
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#include "src/services/eeprom_memory.h"

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
bool EepromMemory::WritePage(uint16_t page, const std::string str)
{
    if (page >= NUM_PAGES) 
    {
        CORE_ERROR("Invalid page number %u", page);
        return false;
    }

    const size_t length = str.length();
    if (length > BYTES_PER_PAGE) 
    {
        CORE_ERROR("Data too long (%u > %u)", str.size(), BYTES_PER_PAGE);
        return false;
    }

    // Pad with null chars if needed
    std::string data = str;
    data.resize(BYTES_PER_PAGE, ENDL_CHAR);

    // Calculate the starting memory address for the page
    uint16_t memAddress = (page * BYTES_PER_PAGE);

    // Prepare buffer: 2 bytes for address + data
    uint8_t buffer[2 + BYTES_PER_PAGE];
    buffer[0] = (memAddress >> 8) & 0xFF;  // MSB
    buffer[1] = memAddress & 0xFF;         // LSB
    memcpy(&buffer[2], data.c_str(), BYTES_PER_PAGE);

    // Write address + data to EEPROM
    if (!_i2c.Write(buffer, 2 + BYTES_PER_PAGE)) 
    {
        CORE_ERROR("Write failed");
        return false;
    }

    // Wait for EEPROM to complete internal write cycle
    TaskDelayMs(20);

    return true;
}

//-----------------------------------------------------------------------------
bool EepromMemory::ReadPage(uint16_t page, std::string& str)
{
    if (page >= NUM_PAGES) 
    {
        CORE_ERROR("Invalid page number %u", page);
        return false;
    }

    // Calculate the starting memory address for the page
    uint16_t memAddress = (page * BYTES_PER_PAGE);

    uint8_t addr[2];
    addr[0] = (memAddress >> 8) & 0xFF;
    addr[1] = memAddress & 0xFF;

    // Set the memory address to read from
    if (!_i2c.Write(addr, 2)) 
    {
        CORE_ERROR("Failed to set read address 0x%04X", memAddress);
        return false;
    }

    // Read the data
    std::vector<uint8_t> vec(BYTES_PER_PAGE);
    if (!_i2c.Read(vec.data(), BYTES_PER_PAGE)) 
    {
        CORE_ERROR("Failed to read page at 0x%04X", memAddress);
        return false;
    }

    str.clear();
    for (auto c : vec) 
    {
        if (c == ENDL_CHAR)
        {
            break;
        }

        str += c;
    }

    return true;
}

//----private------------------------------------------------------------------
EepromMemory::EepromMemory(PinName sda, PinName scl, uint8_t address)
    : _i2c(sda, scl, address)
{}

} // namespace Services
