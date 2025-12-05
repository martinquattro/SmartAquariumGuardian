/*!****************************************************************************
 * @file    memory_config_data.h
 * @brief   Declaration of the MemoryConfigData struct.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include <string>
#include <type_traits>
#include "lib/nlohmann_json/json.hpp"
#include "framework/common_defs.h"

namespace Services {

#define CONFIG_FIELDS                                                                \
    X(std::string, TIMEZONE,            _timezone,            "tz",       "UTC0")    \
    X(float,       TEMP_MIN,            _tempLimitMin,        "tMin",     20.0f)     \
    X(bool,        TEMP_MIN_ENABLED,    _tempLimitMinEnabled, "tMinEn",   false)     \
    X(float,       TEMP_MAX,            _tempLimitMax,        "tMax",     28.0f)     \
    X(bool,        TEMP_MAX_ENALED,     _tempLimitMaxEnabled, "tMaxEn",   false)     \

enum class FieldId 
{
    #define X(type, id, name, key, def) id,
    CONFIG_FIELDS
    #undef X
    COUNT
};

struct MemoryConfigData
{
    using Json = nlohmann::json;

    #define X(type, id, name, key, def) type name = def;
    CONFIG_FIELDS
    #undef X

    //! Serialization to JSON string
    auto ToJson() const -> std::string
    {
        Json j;
        #define X(type, id, name, key, def) j[key] = name;
        CONFIG_FIELDS
        #undef X
        return j.dump(-1);
    }

    //! Deserialization from JSON string
    auto FromJson(const std::string& jsonString) -> bool
    {
        if (jsonString.empty())
            return false;

        Json j = Json::parse(jsonString, nullptr, false);
        if (j.is_discarded() || !j.is_object())
        {
            CORE_ERROR("Config: JSON error. Using defaults.");
            return false;
        }

        #define X(T, id, name, key, def) \
            if (j.contains(key)) { \
                if (std::is_same<T, std::string>::value && j[key].is_string()) { \
                    name = j[key].get<T>(); \
                } \
                else if (std::is_floating_point<T>::value && j[key].is_number()) { \
                    name = j[key].get<T>(); \
                } \
                else if (std::is_same<T, bool>::value && j[key].is_boolean()) { \
                    name = j[key].get<T>(); \
                } \
                else if (std::is_integral<T>::value && j[key].is_number_integer()) { \
                    name = j[key].get<T>(); \
                } \
            }

        CONFIG_FIELDS
        #undef X

        CORE_INFO("Config: Loaded successfully.");
        return true;
    }
};

} // namespace Services