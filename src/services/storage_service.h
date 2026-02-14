/*!****************************************************************************
 * @file    storage_service.h
 * @brief   Declaration of the StorageService manager.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/core/base/service.h"
#include "src/services/memory/eeprom_memory.h"
#include "src/services/memory/memory_config_data.h"
#include <cstdint>
#include <string>

namespace Services {

class StorageService : public Base::Singleton<StorageService>
                     , public Base::Service
{
    using Json = nlohmann::json;
   
    public:
        
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
         * @brief Remove a feeding schedule entry from storage.
         * @param slotIndex Feeding slot index to delete.
         * @return true if the operation was successful, false otherwise.
        */
        bool RemoveFeedingScheduleFromStorage(const int slotIndex);

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
 
        friend class Base::Singleton<StorageService>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "StorageService"; }

        /*!
         * @brief Initializes the Module.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override;

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

        Services::EepromMemory* _eepromMemory = nullptr;
        MemoryConfigData _configCache;
};

} // namespace Services