/*!****************************************************************************
 * @file    eeprom_memory.h
 * @brief   Driver for external EEPROM (RTC module embedded) via I2C bus
 * @author  Quattrone Martin
 * @date    Sep 2025
 *******************************************************************************/

#ifndef EEPROM_MEMORY_H
#define EEPROM_MEMORY_H

#include "framework/common_defs.h"
#include <string>

namespace System {

class EepromMemory
{
    public:

        /**
         * @brief Get the singleton instance of EepromMemory.
         * @return EepromMemory* Pointer to the EepromMemory instance.
         */
        static EepromMemory* GetInstance();
        
        /**
         * @brief Initialize the EEPROM memory driver.
         */
        static void Init();

        /**
         * @brief Write a string to the EEPROM starting at the specified memory address.
         * @param page  Page number to write to (0 to NUM_PAGES-1).
         * @param str        String to write.
         * @return true if success, false otherwise.
        */
        bool WritePage(uint16_t page, const std::string str);

        /**
         * @brief Read a string from the EEPROM starting at the specified memory address.
         * @param page       Page number to read from (0 to NUM_PAGES-1).
         * @param str        String to store the read data.
         * @return true if success, false otherwise.
        */
        bool ReadPage(uint16_t page, std::string& str);

    private:

        EepromMemory(PinName sda, PinName scl, uint8_t address);
        ~EepromMemory() = default;
        EepromMemory(const EepromMemory&) = delete;
        EepromMemory& operator=(const EepromMemory&) = delete;

        //---------------------------------------------
        
        static constexpr size_t EEPROM_SIZE_BYTES = 4096; // Total EEPROM size in bytes (e.g., 32Kb = 4096B)
        static constexpr size_t BYTES_PER_PAGE = 32;      // EEPROM page size in bytes
        static constexpr size_t NUM_PAGES = (EEPROM_SIZE_BYTES / BYTES_PER_PAGE);        // Total number of pages
        static constexpr size_t ENDL_CHAR = 0x00;       // Null terminator for strings

        //---------------------------------------------

        static EepromMemory* _instance;
        I2C _i2c;
};

} // namespace Drivers

#endif // EEPROM_MEMORY_H
