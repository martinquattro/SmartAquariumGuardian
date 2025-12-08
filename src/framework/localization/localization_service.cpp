/*!****************************************************************************
 * @file    localization_service.h
 * @brief   Implementation of the LocalizationService for application i18n.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#include "src/framework/localization/localization_service.h"
#include <fstream>
#include <cstdio>

LocalizationService* LocalizationService::_instance = nullptr;

//-----------------------------------------------------------------------------
LocalizationService* LocalizationService::GetInstance()
{
    return _instance;
}

//-----------------------------------------------------------------------------
void LocalizationService::Init()
{
    CORE_INFO("Initializing LocalizationService...");

    if (_instance != nullptr)
    {
        CORE_ERROR("LocalizationService already initialized!");
        return;
    }

    _instance = new LocalizationService();

    // TODO - It should load the one saved in EEPROM config once that is implemented
    const bool success = _instance->SetLanguage(DEFAULT_LANG);
    if (!success)
    {
        CORE_ERROR("Failed to load default language '%s'", DEFAULT_LANG);
    }
    else
    {
        CORE_INFO("Default language '%s' loaded successfully.", DEFAULT_LANG);
    }
}

//-----------------------------------------------------------------------------
bool LocalizationService::SetLanguage(const std::string& langCode)
{
    // Avoid reloading if it's already the active language
    if (_currentLangCode == langCode && !_locIdsMap.empty())
    {
        return true;
    }

    CORE_INFO("Attempting to switch language to '%s'...", langCode.c_str());

    if (LoadLanguageFile(langCode))
    {
        _currentLangCode = langCode;
        CORE_INFO("Language switched successfully.");
        return true;
    }
    else
    {
        CORE_ERROR("Failed to switch to '%s'. Keeping previous lang: '%s'.",
                   langCode.c_str(), _currentLangCode.c_str());
        return false;
    }
}

//-----------------------------------------------------------------------------
void LocalizationService::Localize(std::string& outputString, const char* locId) const
{
    auto it = _locIdsMap.find(locId);

    if (it != _locIdsMap.end())
    {
        outputString = it->second;
    }

    CORE_WARNING("Localization: String ID '%s' not found in current language '%s'",
                 locId, _currentLangCode.c_str());

    outputString = "*" +  std::string(locId);
}

//-----------------------------------------------------------------------------
void LocalizationService::LocalizeWithFormat(std::string& outputString, const char* locId, ...)
{
    char formatBuffer[256]; //!< Buffer for formatted strings

    std::string formatBase = "";
    Localize(formatBase, locId);

    va_list args;
    va_start(args, locId);

    int written = vsnprintf(formatBuffer, sizeof(formatBuffer), formatBase.c_str(), args);

    va_end(args);

    if (written < 0 || written >= sizeof(formatBuffer))
    {
         CORE_WARNING("Localize buffer overflow or error for ID '%s'", locId);
         // Ensure null-termination in case of overflow truncation
         formatBuffer[sizeof(formatBuffer) - 1] = '\0';
    }

    outputString = std::string(formatBuffer);
}

//---- private ----------------------------------------------------------------
bool LocalizationService::LoadLanguageFile(const std::string& langCode)
{
    std::string filePath = std::string(BASE_PATH) + langCode + ".json";
    CORE_INFO("Loading file: %s", filePath.c_str());

    std::ifstream file(filePath.c_str());
    if (!file.is_open())
    {
        CORE_ERROR("Could not open file: %s", filePath.c_str());
        return false;
    }

    nlohmann::json j = nlohmann::json::parse(file, nullptr, false);
    file.close();

    if (j.is_discarded())
    {
        CORE_ERROR("JSON parse error in %s", filePath.c_str());
        return false;
    }

    if (!j.is_object())
    {
         CORE_ERROR("JSON root is not an object in %s", filePath.c_str());
         return false;
    }

    _locIdsMap.clear();

    for (auto& [key, value] : j.items()) 
    {
        if (value.is_string()) 
        {
            _locIdsMap[key] = value.get<std::string>();
        }
        else
        {
             CORE_WARNING("Localization: Skipping non-string value for key '%s' in %s",
                          key.c_str(), filePath.c_str());
        }
    }

    CORE_INFO("Loaded %d strings into RAM.", _locIdsMap.size());
    return true;
}

//----private------------------------------------------------------------------
LocalizationService::LocalizationService()
{
    _currentLangCode = ""; // No language loaded initially
}