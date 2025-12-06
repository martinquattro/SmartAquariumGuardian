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

// template<typename T> struct is_vector : std::false_type {};
// template<typename T, typename A> struct is_vector<std::vector<T, A>> : std::true_type {};

struct FeedingScheduleEntry
{
    int _min = 0;           //!< Minutes after midnight (0-1439)
    int _id = 0;            //!< Feeding slot index (0-9)
    int _dose = 1;          //!< Dose amount for this entry
    bool _enabled = false;  //!< Is this entry enabled

    bool operator==(const FeedingScheduleEntry& other) const 
    {
        return std::tie(_min, _id, _dose, _enabled) == 
               std::tie(other._min, other._id, other._dose, other._enabled);
    }
};

using FeeddingScheduleList = std::vector<FeedingScheduleEntry>;

inline void to_json(nlohmann::json& j, const FeedingScheduleEntry& e) 
{
    j = nlohmann::json
    {
        {"_min", e._min},
        {"_id", e._id},
        {"_dose", e._dose}, 
        {"_enabled", e._enabled}
    };
}

inline void from_json(const nlohmann::json& j, FeedingScheduleEntry& e)
{
    e._min = j.value("_min", 0);
    e._id = j.value("_id", 0);
    e._dose = j.value("_dose", 1);
    e._enabled = j.value("_enabled", false);
}

#define CONFIG_FIELDS                                                                     \
    X(std::string,          TIMEZONE,         _timezone,            "tz",       "UTC0")    \
    X(float,                TEMP_MIN,         _tempLimitMin,        "tMin",     20.0f)     \
    X(bool,                 TEMP_MIN_ENABLED, _tempLimitMinEnabled, "tMinEn",   false)     \
    X(float,                TEMP_MAX,         _tempLimitMax,        "tMax",     28.0f)     \
    X(bool,                 TEMP_MAX_ENALED,  _tempLimitMaxEnabled, "tMaxEn",   false)     \
    X(FeeddingScheduleList, FEEDING_SCHEDULE, _feedingSchedule,     "feedSch",  {})

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
                if (std::is_same<T, FeeddingScheduleList>::value && j[key].is_array()) { \
                    name = j[key].get<T>(); \
                } \
                else if (std::is_same<T, std::string>::value && j[key].is_string()) { \
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