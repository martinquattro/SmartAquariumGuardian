/*!****************************************************************************
 * @file    cloud_payloads.h
 * @brief   JSON payload builders for ThingsBoard: telemetry and client attributes.
 * @author  Quattrone Martin
 * @date    Mar 2026
 *******************************************************************************/

#pragma once

#include "src/core/guardian_proxy.h"
#include "src/managers/comms/network_config.h"
#include "lib/nlohmann_json/json.hpp"
#include "src/services/memory/memory_config_data.h"
#include <string>

namespace Comms {

using Json = nlohmann::json;

/*!
 * @brief Builds JSON payload for telemetry (sensor data) published to v1/devices/me/telemetry.
 */
class TelemetryPayload
{
    public:

        TelemetryPayload()
        {
            _temperature = Core::GuardianProxy::GetInstance()->GetTemperatureReading();
            _tds = Core::GuardianProxy::GetInstance()->GetTdsReading();
        }

        std::string ToJsonString() const
        {
            Json json;
            json[NetworkConfig::TelemetryKeys::TEMPERATURE] = _temperature;
            json[NetworkConfig::TelemetryKeys::TDS] = _tds;
            return json.dump();
        }

    private:

        float _temperature;
        int _tds;
};

/*!
 * @brief Builds JSON payload for client attributes published to v1/devices/me/attributes.
 *        Feeding schedule sent as single array - replace, not delete (ThingsBoard doesn't remove on null).
 */
class ClientAttributesPayload
{
    public:

        ClientAttributesPayload()
        {
            auto* proxy = Core::GuardianProxy::GetInstance();
            _timezone = proxy->GetTimezoneFromStorage();
            proxy->GetTempLimitsFromStorage(_minTemp, _minEnabled, _maxTemp, _maxEnabled);
            _scheduleList = proxy->GetFeedingScheduleFromStorage();
        }

        std::string ToJsonString() const
        {
            Json doc;

            doc[NetworkConfig::ClientAttributes::TIMEZONE] = _timezone;
            doc[NetworkConfig::ClientAttributes::TEMP_LIMIT_MIN] = _minTemp;
            doc[NetworkConfig::ClientAttributes::TEMP_LIMIT_MIN_ENABLED] = _minEnabled;
            doc[NetworkConfig::ClientAttributes::TEMP_LIMIT_MAX] = _maxTemp;
            doc[NetworkConfig::ClientAttributes::TEMP_LIMIT_MAX_ENABLED] = _maxEnabled;

            Json scheduleArray = Json::array();
            for (const auto& e : _scheduleList)
            {
                Json entry;
                entry[NetworkConfig::ClientAttributes::FEED_SLOT_ID] = e._id;
                entry[NetworkConfig::ClientAttributes::FEED_TIME] = e._min;
                entry[NetworkConfig::ClientAttributes::FEED_DOSE] = e._dose;
                entry[NetworkConfig::ClientAttributes::FEED_ENABLED] = e._enabled;
                scheduleArray.push_back(entry);
            }
            doc[NetworkConfig::ClientAttributes::FEEDING_SCHEDULE] = scheduleArray;

            return doc.dump();
        }

    private:

        std::string _timezone;
        float _minTemp = 0.0f;
        bool _minEnabled = false;
        float _maxTemp = 0.0f;
        bool _maxEnabled = false;
        Services::FeeddingScheduleList _scheduleList;
};

} // namespace Comms
