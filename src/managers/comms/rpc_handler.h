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
                return Result::Error("Internal error: Invalid JSON payload.");
            }

            const auto minEnabledOpt = parser.GetParam<bool>(NetworkConfig::ClientAttributes::TEMP_LIMIT_MIN_ENABLED);
            const auto maxEnabledOpt = parser.GetParam<bool>(NetworkConfig::ClientAttributes::TEMP_LIMIT_MAX_ENABLED);

            if (!minEnabledOpt.has_value() || !maxEnabledOpt.has_value())
            {
                 return Result::Error("Missing required 'enabled' flags for limits.");
            }

            bool minEnabled = minEnabledOpt.value();
            bool maxEnabled = maxEnabledOpt.value();

            float tempMin = 0.0f;
            float tempMax = 0.0f;

            const auto tempMinOpt = parser.GetParam<float>(NetworkConfig::ClientAttributes::TEMP_LIMIT_MIN);
            const auto tempMaxOpt = parser.GetParam<float>(NetworkConfig::ClientAttributes::TEMP_LIMIT_MAX);

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
class SetTdsLimitsHandler : public IRpcHandler
{
    public:

        static constexpr const char* NAME = "setTdsLimits";

        Result Handle(const std::string& payload) override
        {
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Internal error: Invalid JSON payload.");
            }

            const auto minEnabledOpt = parser.GetParam<bool>(NetworkConfig::ClientAttributes::TDS_LIMIT_MIN_ENABLED);
            const auto maxEnabledOpt = parser.GetParam<bool>(NetworkConfig::ClientAttributes::TDS_LIMIT_MAX_ENABLED);

            if (!minEnabledOpt.has_value() || !maxEnabledOpt.has_value())
            {
                return Result::Error("Missing required 'enabled' flags for limits.");
            }

            bool minEnabled = minEnabledOpt.value();
            bool maxEnabled = maxEnabledOpt.value();

            int tdsMin = 0;
            int tdsMax = 0;

            const auto tdsMinOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::TDS_LIMIT_MIN);
            const auto tdsMaxOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::TDS_LIMIT_MAX);

            if (minEnabled)
            {
                if (!tdsMinOpt.has_value())
                {
                    return Result::Error("Min limit is enabled but value is invalid or missing (cannot be null).");
                }
                tdsMin = tdsMinOpt.value();
            }
            else
            {
                if (tdsMinOpt.has_value())
                    tdsMin = tdsMinOpt.value();
            }

            if (maxEnabled)
            {
                if (!tdsMaxOpt.has_value())
                {
                    return Result::Error("Max limit is enabled but value is invalid or missing (cannot be null).");
                }
                tdsMax = tdsMaxOpt.value();
            }
            else
            {
                if (tdsMaxOpt.has_value())
                    tdsMax = tdsMaxOpt.value();
            }

            const auto result = Core::GuardianProxy::GetInstance()->SetTdsLimits(tdsMin, minEnabled, tdsMax, maxEnabled);
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
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Internal error: Invalid JSON payload.");
            }

            const auto slotIdOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::FEED_SLOT_ID);
            const auto timeMinutesOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::FEED_TIME);
            const auto doseOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::FEED_DOSE);
            const auto enabledOpt = parser.GetParam<bool>(NetworkConfig::ClientAttributes::FEED_ENABLED);

            if (!enabledOpt.has_value())
            {
                CORE_ERROR("Missing 'enabled' flag.");
                return Result::Error("Missing parameters");
            }

            const bool enabled = enabledOpt.value();

            if (enabled)
            {
                if (!slotIdOpt.has_value())
                {
                    CORE_ERROR("Missing 'slot_index' for enabled schedule.");
                    return Result::Error("Missing parameters");
                }

                if (!timeMinutesOpt.has_value())
                {
                    CORE_ERROR("Missing 'time_min' for enabled schedule.");
                    return Result::Error("Missing parameters");
                }

                if (!doseOpt.has_value())
                {
                    CORE_ERROR("Missing 'dose' for enabled schedule.");
                    return Result::Error("Missing parameters");
                }
            }

            const auto result = Core::GuardianProxy::GetInstance()->AddFeedingScheduleEntry(
                timeMinutesOpt.value(),
                slotIdOpt.value(), 
                doseOpt.value(), 
                enabled
            );

            return result;
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
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Internal error: Invalid JSON payload.");
            }

            const auto slotIdOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::FEED_SLOT_ID);

            if (!slotIdOpt.has_value())
            {
                CORE_ERROR("Missing 'slot_index' for enabled schedule.");
                return Result::Error("Missing parameters");
            }

            const int slotIndex = slotIdOpt.value();

            const auto result = Core::GuardianProxy::GetInstance()->DeleteFeedingScheduleEntry(
                slotIndex
            );

            return result;
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
            Utils::JsonPayloadParser parser(payload);
            if (!parser.IsValid())
            {
                return Result::Error("Internal error: Invalid JSON payload.");
            }

            int doses = 0;

            const auto dosesOpt = parser.GetParam<int>(NetworkConfig::ClientAttributes::FEED_DOSE);
            if (!dosesOpt.has_value())
            {
                return Result::Error("Dose parameter missing");
            }

            doses = dosesOpt.value();

            const auto result = Core::GuardianProxy::GetInstance()->Feed(doses);
            return result;
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

            const auto timezone = parser.GetParam<std::string>(NetworkConfig::ClientAttributes::TIMEZONE);
            
            if (!timezone.has_value())
            {
                return Result::Error("Timezone parameter missing or invalid.");
            }

            const auto result = Core::GuardianProxy::GetInstance()->InitTimeSync(timezone.value().c_str());
            return result;
        };
};

//-----------------------------------------------------------------------------
class FactoryResetHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "factoryReset";

        //!
        Result Handle(const std::string& payload) override 
        {
            const auto result = Core::GuardianProxy::GetInstance()->FactoryReset();
            return result;
        }
};

//-----------------------------------------------------------------------------
class SyncDeviceHandler : public IRpcHandler 
{
    public:

        static constexpr const char* NAME = "syncDevice";

        //!
        Result Handle(const std::string& payload) override 
        {
            const auto result = Core::GuardianProxy::GetInstance()->SyncDevice();
            return result;
        }
};
} // namespace Handlers