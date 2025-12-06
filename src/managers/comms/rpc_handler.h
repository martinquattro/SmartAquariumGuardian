/*!****************************************************************************
 * @file    rpc_handler.h
 * @brief   RPC handler interface and implementations.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

 #pragma once

#include "framework/common_defs.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/core/guardian_proxy.h"
#include "src/managers/comms/network_config.h"
#include "src/managers/comms/json_parser.h"
#include <optional>
#include <string>

namespace Handlers {

using Json = nlohmann::json;


//-----------------------------------------------------------------------------
class IRpcHandler
{
    public:

        virtual ~IRpcHandler() = default;

        //! Handle the RPC request with the given payload.
        virtual Result Handle(const std::string& payload) = 0;
};

//-----------------------------------------------------------------------------
class SetTempLimitsHandler : public IRpcHandler
{
    public:

        static constexpr const char* NAME = "setTempLimits";

        //!
        Result Handle(const std::string& payload) override
        {
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Invalid JSON payload.");
            }

            const auto minEnabledOpt = parser.GetParam<bool>(NetworkConfig::SharedAttributes::TEMP_LIMIT_MIN_ENABLED);
            const auto maxEnabledOpt = parser.GetParam<bool>(NetworkConfig::SharedAttributes::TEMP_LIMIT_MAX_ENABLED);

            if (!minEnabledOpt.has_value() || !maxEnabledOpt.has_value())
            {
                 return Result::Error("Missing required 'enabled' flags for limits.");
            }

            bool minEnabled = minEnabledOpt.value();
            bool maxEnabled = maxEnabledOpt.value();

            float tempMin = 0.0f;
            float tempMax = 0.0f;

            const auto tempMinOpt = parser.GetParam<float>(NetworkConfig::SharedAttributes::TEMP_LIMIT_MIN);
            const auto tempMaxOpt = parser.GetParam<float>(NetworkConfig::SharedAttributes::TEMP_LIMIT_MAX);

            if (minEnabled)
            {
                if (!tempMinOpt.has_value())
                {
                    return Result::Error("Min limit is enabled but value is invalid or missing (cannot be null).");
                }

                tempMin = tempMinOpt.value();
            }
            else
            {
                if (tempMinOpt.has_value())
                    tempMin = tempMinOpt.value();
            }

            if (maxEnabled)
            {
                if (!tempMaxOpt.has_value())
                    return Result::Error("Max limit is enabled but value is invalid or missing (cannot be null).");

                tempMax = tempMaxOpt.value();
            }
            else
            {
                 if (tempMaxOpt.has_value()) 
                    tempMax = tempMaxOpt.value();
            }

            const auto result = Core::GuardianProxy::GetInstance()->SetTemperatureLimits(tempMin, minEnabled, tempMax, maxEnabled);
            return result;
        }
};

//-----------------------------------------------------------------------------
class AddFeedingScheduleHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "addFeedingSchedule";

        //!
        Result Handle(const std::string& payload) override 
        {
            return Result::Success("Feeding schedule added successfully.");
        }
};

//-----------------------------------------------------------------------------
class DeleteFeedingScheduleHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "deleteFeedingSchedule";

        //!
        Result Handle(const std::string& payload) override 
        {
            return Result::Success("Feeding schedule deleted successfully.");
        }
};

//-----------------------------------------------------------------------------
class FeedNowHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "feedNow";

        //!
        Result Handle(const std::string& payload) override 
        {
            return Result::Success("Feeding executed successfully.");
        }
};

//-----------------------------------------------------------------------------
class SetTimezoneHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "setTimezone";

        //!
        Result Handle(const std::string& payload) override 
        {
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Invalid JSON payload.");
            }

            const auto timezone = parser.GetParam<std::string>(NetworkConfig::SharedAttributes::TIMEZONE);
            
            if (!timezone.has_value())
            {
                return Result::Error("Timezone parameter missing or invalid.");
            }

            const auto result = Core::GuardianProxy::GetInstance()->InitTimeSync(timezone.value().c_str());
            return result;
        };
};

} // namespace Handlers