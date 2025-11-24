/*!****************************************************************************
 * @file    storage_service.h
 * @brief   Declaration of the StorageService manager.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include <string>
#include <cstdint>
#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/services/memory_config_data.h"

namespace Services {

class StorageService
{
    using Json = nlohmann::json;
   
    public:

        /*!
         * @brief Get the singleton instance of StorageService.
         * @return StorageService* Pointer to the StorageService instance.
        */
        static StorageService* GetInstance();

        /*!
         * @brief Initialize the StorageService.
         */
        static void Init();

        bool SetTimezone(const std::string& tz);
        std::string GetTimezone() const;
        
    private:
 
        /*!
            * @brief Save configuration data to EEPROM.
            * @return true if success, false otherwise.
        */
        bool SaveConfigInternal();

        /*!
            * @brief Load configuration data from EEPROM.
            * @return true if success, false otherwise.
        */
        bool LoadConfigInternal();

        //---------------------------------------------

        StorageService() {}
        ~StorageService() = default;
        StorageService(const StorageService&) = delete;
        StorageService& operator=(const StorageService&) = delete;

        //---------------------------------------------

        static constexpr uint16_t CONFIG_START_ADDR = 0x0000;
        static constexpr size_t MAX_CONFIG_SIZE = 512;

        //---------------------------------------------

        static StorageService* _instance;
        MemoryConfigData _configCache;
};

} // namespace Services