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
#include "src/services/memory/memory_config_data.h"

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

        /*!
         * @brief Save a feeding schedule entry in storage.
         * @param timeMinutesAfterMidnight Minutes after midnight (0-1439).
         * @param slotIndex Feeding slot index.
         * @param dose Dose amount for this entry.
         * @param enabled Is this entry enabled.
         * @return true if the operation was successful, false otherwise.
        */
        bool SaveFeedingScheduleInStorage(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled);
        
        /*!
         * @brief Get the value of a configuration field.
         * @tparam T Type of the field to get.        
        */
        template<typename T>
        T Get(FieldId fieldId) const
        {
            switch (fieldId)
            {
                #define X(type, id, name, key, def) \
                    case FieldId::id: return *reinterpret_cast<const T*>(&_configCache.name);

                CONFIG_FIELDS
                #undef X

                default:
                    CORE_ERROR("Invalid FieldId in Get operation");
                    return T{};
            }
        }

        /*!
         * @brief Set the value of a configuration field.
         * @tparam T Type of the field to set.        
        */
        template<typename T>
        bool Set(FieldId fieldId, T newValue)
        {
            bool changed = false;
            switch (fieldId) 
            {
                #define X(type, id, name, key, def) \
                    case FieldId::id: \
                        if (*reinterpret_cast<const T*>(&_configCache.name) != newValue) \
                        { \
                            *reinterpret_cast<T*>(&_configCache.name) = newValue; \
                            changed = true; \
                        } \
                        break;

                CONFIG_FIELDS
                #undef X
                default:
                    CORE_ERROR("Invalid FieldId in Set operation");
                    return false;
            }

            if (changed) 
            {
                CORE_INFO("Storage: Field changed. Saving to EEPROM...");
                return SaveConfigInternal();
            }
            else
            {
                return true;
            }
        }
    
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