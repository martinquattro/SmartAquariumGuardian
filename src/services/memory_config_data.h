/*!****************************************************************************
 * @file    memory_config_data.h
 * @brief   Declaration of the MemoryConfigData struct.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include <string>
#include "lib/nlohmann_json/json.hpp"
#include "framework/common_defs.h"

namespace Services {

struct MemoryConfigData
{
    using Json = nlohmann::json;

    static constexpr const char* timezoneKey = "tz";
    static constexpr const char* tempMinKey  = "tMin";
    static constexpr const char* tempMaxKey  = "tMax";
    static constexpr const char* tdsMinKey   = "tdsMin";
    static constexpr const char* tdsMaxKey   = "tdsMax";

    std::string _timezone = "UTC0";
    float _tempLimitMin = 20.0f;
    float _tempLimitMax = 28.0f;
    int _tdsLimitMin = 100;
    int _tdsLimitMax = 500;

    //! Serialization to JSON string
    auto ToJson() const -> std::string
    {
        Json j;

        j[timezoneKey] = _timezone;
        j[tempMinKey] = _tempLimitMin;
        j[tempMaxKey] = _tempLimitMax;
        j[tdsMinKey] = _tdsLimitMin;
        j[tdsMaxKey] = _tdsLimitMax;

        return j.dump(-1);
    }

    //! Deserialization from JSON string
    auto FromJson(const std::string& jsonString) -> bool
    {
        if (jsonString.empty()) return false;

        Json j = Json::parse(jsonString, nullptr, false);

        if (j.is_discarded() || !j.is_object())
        {
            CORE_ERROR("MemoryConfigData: JSON parse error or invalid structure");
            return false;
        }

        if (j.contains(timezoneKey))
        {
            const auto& val = j[timezoneKey];
            if (val.is_string()) _timezone = val.get<std::string>();
            else CORE_WARNING("MemoryConfigData: Invalid type for 'tz'");
        }
        
        if (j.contains(tempMinKey))
        {
            const auto& val = j[tempMinKey];
            if (val.is_number()) _tempLimitMin = val.get<float>();
            else CORE_WARNING("MemoryConfigData: Invalid type for 'tMin'");
        }

        if (j.contains(tempMaxKey))
        {
            const auto& val = j[tempMaxKey];
            if (val.is_number()) _tempLimitMax = val.get<float>();
            else CORE_WARNING("MemoryConfigData: Invalid type for 'tMax'");
        }

        if (j.contains(tdsMinKey))
        {
            const auto& val = j[tdsMinKey];
            if (val.is_number_integer()) _tdsLimitMin = val.get<int>();
            else CORE_WARNING("MemoryConfigData: Invalid type for 'tdsMin'");
        }
        if (j.contains(tdsMaxKey))
        {
            const auto& val = j[tdsMaxKey];
            if (val.is_number_integer()) _tdsLimitMax = val.get<int>();
            else CORE_WARNING("MemoryConfigData: Invalid type for 'tdsMax'");
        }

        return true;
    }
};

} // namespace Services