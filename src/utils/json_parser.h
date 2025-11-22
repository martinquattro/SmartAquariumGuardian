/*!****************************************************************************
 * @file    json_parser.h
 * @brief   Utility class for exception-safe JSON payload parsing using nlohmann::json.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include <optional>
#include <string>
#include <type_traits>

namespace Utils {

using Json = nlohmann::json;

class JsonPayloadParser 
{
    public:

        explicit JsonPayloadParser(const std::string& payload);

        bool IsValid() const;

        std::string GetError() const;

        template<typename T>
        std::optional<T> GetValue(const std::string& key, const std::string& parentKey = "") const;

        template<typename T>
        std::optional<T> GetParam(const std::string& key) const;

        std::optional<std::string> GetMethod() const;

    private:

        Json _json;
        bool _isValid;
        std::string _errorMsg;
};

// Template Implementation
//-----------------------------------------------------------------------------
template<typename T>
std::optional<T> JsonPayloadParser::GetValue(const std::string& key, const std::string& parentKey) const
{
    if (!_isValid)
    {
        return std::nullopt;
    }

    const Json* rootPtr = &_json;
    if (!parentKey.empty())
    {
        auto itParent = _json.find(parentKey);
        if (itParent == _json.end() || !itParent->is_object())
        {
            // Parent key doesn't exist or isn't an object
            return std::nullopt;
        }
        rootPtr = &(*itParent);
    }

    const Json& root = *rootPtr;

    // 2. Find the key using .find() (safe for const objects)
    auto it = root.find(key);
    if (it == root.end())
    {
        // Key not found
        return std::nullopt;
    }
    const Json& valueJson = *it;

    // 3. Check type and extract safely without exceptions
    // We use 'if constexpr' so the compiler only generates code for the matching type branch.
    if constexpr (std::is_same_v<T, float>)
    {
        if (valueJson.is_number())
        {
            return valueJson.get<float>(); // Safe conversion
        }
    }
    else if constexpr (std::is_same_v<T, int>)
    {
        if (valueJson.is_number_integer()) {
            return valueJson.get<int>(); // Safe conversion
        }
    }
    else if constexpr (std::is_same_v<T, bool>)
    {
        if (valueJson.is_boolean())
        {
            return valueJson.get<bool>();
        }
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        if (valueJson.is_string())
        {
            return valueJson.get<std::string>();
        }
    }

    // If type mismatch
    CORE_WARNING("JsonPayloadParser: Type mismatch for key '%s' in '%s'", 
                 key.c_str(), 
                 parentKey.empty() ? "root" : parentKey.c_str()
                );
                 
    return std::nullopt;
}

//-----------------------------------------------------------------------------
template<typename T>
std::optional<T> JsonPayloadParser::GetParam(const std::string& key) const
{
    return GetValue<T>(key, "params");

}

} // namespace Utils