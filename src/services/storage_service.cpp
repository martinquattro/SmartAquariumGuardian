/*!****************************************************************************
 * @file    storage_service.cpp
 * @brief   Implementation of the StorageService service.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#include "src/services/storage_service.h"

#include "src/services/eeprom/eeprom_memory.h"
#include "framework/common_defs.h"
#include <vector>
#include <cstring>

namespace Services {

StorageService* StorageService::_instance = nullptr;

//----static-------------------------------------------------------------------
StorageService* StorageService::GetInstance() 
{
    if (_instance == nullptr) _instance = new StorageService();
    return _instance;
}

//----static-------------------------------------------------------------------
void StorageService::Init()
{
    CORE_INFO("Initializing StorageService...");

    if (_instance != nullptr)
    {
        CORE_ERROR("FoodFeeder already initialized!");
        return;
    }

    _instance = new StorageService();

    Services::EepromMemory::Init();

    if (!_instance->LoadConfigInternal())
    {
        CORE_WARNING("Could not load config from EEPROM. Using defaults.");
        _instance->SaveConfigInternal();
    }
    else
    {
        CORE_INFO("Memory config loaded successfully: %s", _instance->_configCache.ToJson().c_str());
    }
}

//-----------------------------------------------------------------------------
bool StorageService::SetTimezone(const std::string& tz)
{
    if (_configCache._timezone == tz) return true;

    _configCache._timezone = tz;
    return SaveConfigInternal();
}

//-----------------------------------------------------------------------------
std::string StorageService::GetTimezone() const 
{
    return _configCache._timezone;
}

//----private------------------------------------------------------------------
bool StorageService::SaveConfigInternal()
{
    CORE_INFO("Saving config to EEPROM...");
    
    std::string jsonStr = _configCache.ToJson();

    if (jsonStr.length() >= MAX_CONFIG_SIZE)
    {
        CORE_ERROR("Config data too large for buffer (%u > %u)", jsonStr.length(), MAX_CONFIG_SIZE);
        return false;
    }

    std::vector<uint8_t> buffer(jsonStr.begin(), jsonStr.end());
    buffer.push_back('\0');

    bool success = Services::EepromMemory::GetInstance()->WriteBytes(
        CONFIG_START_ADDR, 
        buffer.data(), 
        buffer.size()
    );
    
    if (success)
    {
        CORE_INFO("Config saved.");
    }
    else
    {
        CORE_ERROR("Failed to write to EEPROM.");
    }
    
    return success;
}

//----private------------------------------------------------------------------
bool StorageService::LoadConfigInternal()
{
    CORE_INFO("Loading config from EEPROM...");

    std::vector<uint8_t> buffer(MAX_CONFIG_SIZE);
    if (!Services::EepromMemory::GetInstance()->ReadBytes(CONFIG_START_ADDR, buffer.data(), MAX_CONFIG_SIZE))
    {
        return false;
    }

    buffer.back() = '\0'; 

    std::string jsonStr(reinterpret_cast<char*>(buffer.data()));

    if (jsonStr.empty() || jsonStr[0] == (char)0xFF)
    {
        CORE_INFO("EEPROM appears empty or uninitialized.");
        return false;
    }

    if (_configCache.FromJson(jsonStr))
    {
        return true;
    }
    else
    {
        CORE_ERROR("Failed to parse JSON from EEPROM.");
        return false;
    }
}

} // namespace Services