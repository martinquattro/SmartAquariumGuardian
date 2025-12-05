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

namespace Services {

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
         * @brief Write bytes to the EEPROM starting at the specified memory address.
         * @param address    Memory address to start writing to (0 to EEPROM_SIZE_BYTES-1).
         * @param data       Pointer to the data to write.
         * @param length     Number of bytes to write.
         * @return true if success, false otherwise.
        */
        bool WriteBytes(uint16_t address, const uint8_t* data, size_t length);

        /**
         * @brief Read bytes from the EEPROM starting at the specified memory address.
         * @param address    Memory address to start reading from (0 to EEPROM_SIZE_BYTES-1).
         * @param buffer     Pointer to the buffer to store read data.
         * @param length     Number of bytes to read.
         * @return true if success, false otherwise.
        */
        bool ReadBytes(uint16_t address, uint8_t* buffer, size_t length);

    private:

        /*!
         * @brief Write a full page to the EEPROM.
         * @param pageAddress   Page address to write to.
         * @param data          Pointer to the data to write.
         * @param length        Number of bytes to write.
         * @return true if success, false otherwise.
        */
        bool WritePageInternal(uint16_t pageAddress, const uint8_t* data, size_t length);

        //---------------------------------------------

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

} // namespace Services

#endif // EEPROM_MEMORY_H
