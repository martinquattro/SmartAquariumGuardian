/*!****************************************************************************
 * @file    json_parser.h
 * @brief   Utility class for exception-safe JSON payload parsing using nlohmann::json.
 * Header-only implementation.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include <string>
#include <optional>
#include <type_traits>

namespace Utils {

using Json = nlohmann::json;

class JsonPayloadParser 
{
    public:
        
        explicit JsonPayloadParser(const std::string& payload) 
            : _isValid(false) 
        {
            // 1. Quick check for valid JSON syntax using accept()
            if (!Json::accept(payload)) 
            {
                CORE_ERROR("JsonPayloadParser: Invalid JSON format (accept failed)");
                _errorMsg = "Invalid JSON format.";
                return;
            }

            // 2. Parse without throwing exceptions.
            // The third argument 'false' disables exception throwing.
            // The second argument 'nullptr' is for a parse event callback (not used here).
            _json = Json::parse(payload, nullptr, false);

            // 3. Check if parsing was successful using .is_discarded()
            if (_json.is_discarded()) 
            {
                CORE_ERROR("JsonPayloadParser: Parse error (is_discarded)");
                _errorMsg = "Internal error parsing JSON structure.";
                _isValid = false;
            } 
            else 
            {
                // Parsing successful
                _isValid = true;
            }
        }

        bool IsValid() const { return _isValid; }

        std::string GetError() const{ return _errorMsg; }

        std::optional<std::string> GetMethod() const { return GetValue<std::string>("method"); }

        // Template method declarations
        template<typename T>
        std::optional<T> GetValue(const std::string& key, const std::string& parentKey = "") const;

        template<typename T>
        std::optional<T> GetParam(const std::string& key) const;

    private:

        Json _json;
        bool _isValid;
        std::string _errorMsg;
};

//-----------------------------------------------------------------------------
template<typename T>
std::optional<T> JsonPayloadParser::GetValue(const std::string& key, const std::string& parentKey) const 
{
    if (!_isValid) 
    {
        return std::nullopt;
    }

    // 1. Determine the root object to search in
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

        if (valueJson.is_null())
        {
            return 0.0f;
        }
    }
    else if constexpr (std::is_same_v<T, int>) 
    {
        if (valueJson.is_number_integer())
        {
            return valueJson.get<int>(); // Safe conversion
        }

        if (valueJson.is_null())
        {
            return 0;
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

    // If type mismatch found
    CORE_WARNING("JsonPayloadParser: Type mismatch for key '%s'.", key.c_str());
    return std::nullopt;
}

//-----------------------------------------------------------------------------
template<typename T>
std::optional<T> JsonPayloadParser::GetParam(const std::string& key) const 
{
    return GetValue<T>(key, "params");
}

} // namespace Utils