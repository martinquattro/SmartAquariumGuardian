/*!****************************************************************************
 * @file    rpc_handler.h
 * @brief   RPC handler interface and implementations.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

 #pragma once

#include "framework/common_defs.h"
#include "src/core/guardian_proxy.h"
#include "lib/nlohmann_json/json.hpp"
#include <optional>
#include <string>

namespace Handlers {

using Json = nlohmann::json;

struct RpcResult 
{
    bool success;
    std::optional<std::string> responseMessage;
    std::optional<Json> responseData;

    static RpcResult Success(const std::optional<std::string>& message = std::nullopt, const std::optional<Json>& data = std::nullopt)
    {
        return { true, message, data };
    }

    static RpcResult Error(const std::string& message)
    {
        return { false, message, std::nullopt };
    }
};

//-----------------------------------------------------------------------------
class IRpcHandler
{
    public:

        virtual ~IRpcHandler() = default;

        //! Handle the RPC request with the given payload.
        virtual RpcResult Handle(const std::string& payload) = 0;
};

//-----------------------------------------------------------------------------
class SetTempLimitsHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "setTempLimits";

        //!
        RpcResult Handle(const std::string& payload) override 
        {
            return RpcResult::Success();
            // return Core::GuardianProxy::GetInstance()->SetTemperatureLimits(); 
        }
};

} // namespace Handlers