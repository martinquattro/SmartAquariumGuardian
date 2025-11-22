/*!****************************************************************************
 * @file    json_parser.cpp
 * @brief   Implementation of the JsonPayloadParser class.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#include "src/utils/json_parser.h"

namespace Utils {

//-----------------------------------------------------------------------------
JsonPayloadParser::JsonPayloadParser(const std::string& payload) 
    : _isValid(false) 
{
    // 1. Quick check for valid JSON syntax
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

    if (_json.is_discarded())
    {
        CORE_ERROR("JsonPayloadParser: Parse error (is_discarded)");
        _errorMsg = "Error parsing JSON.";
        _isValid = false;
    }
    else
    {
        _isValid = true;
    }
}

//-----------------------------------------------------------------------------
bool JsonPayloadParser::IsValid() const
{
    return _isValid;
}

//-----------------------------------------------------------------------------
std::string JsonPayloadParser::GetError() const
{
    return _errorMsg;
}

//-----------------------------------------------------------------------------
std::optional<std::string> JsonPayloadParser::GetMethod() const
{
    return GetValue<std::string>("method");
}

} // namespace Utils