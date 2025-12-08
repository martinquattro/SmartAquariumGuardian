/*!****************************************************************************
 * @file    localization_service.h
 * @brief   Declaration of the LocalizationService for application i18n.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#pragma once

#include "framework/common_defs.h" 
#include "lib/nlohmann_json/json.hpp"
#include "src/framework/localization/loc_ids.h"
#include <cstdarg>
#include <map>
#include <string>
#include <vector>

class LocalizationService
{
    public:

        /**
         * @brief Gets the singleton instance.
         * @return Pointer to the LocalizationService instance.
         */
        static LocalizationService* GetInstance();

        /**
         * @brief Initializes the manager and loads the default language.
         * Should be called once at startup, AFTER the filesystem is mounted.
         */
        static void Init();

        /**
         * @brief Switches the active language at runtime.
         * @param langCode The language code (e.g., "eng").
         * @return true if successful, false otherwise (keeps previous language on failure).
         */
        bool SetLanguage(const std::string& langCode);

        /**
         * @brief Retrieves a static translated string by its ID.
         * @param outputString Reference to string where the result will be stored.
         * @param locId The unique identifier string (from string_ids.h).
         */
        void Localize(std::string& outputString, const char* locId) const;

        /**
         * @brief Retrieves a translated string and formats it with dynamic arguments.
         * @param outputString Reference to string where the result will be stored.
         * @param locId The unique identifier string containing format specifiers.
         * @param ... Variadic arguments corresponding to the format specifiers.
         */
        void LocalizeWithFormat(std::string& outputString, const char* locId, ...);

    private:

        LocalizationService();
        ~LocalizationService() = default;
        LocalizationService(const LocalizationService&) = delete;
        LocalizationService& operator=(const LocalizationService&) = delete;

        //---------------------------------------------

        /**
         * @brief Internal helper to load and parse the JSON file from storage.
         */
        bool LoadLanguageFile(const std::string& langCode);

        //---------------------------------------------

        static constexpr const char* DEFAULT_LANG = "eng";
        static constexpr const char* BASE_PATH = "/littlefs/lang/";

        //---------------------------------------------

        static LocalizationService* _instance;

        std::string _currentLangCode;
        std::map<std::string, std::string> _locIdsMap;
};