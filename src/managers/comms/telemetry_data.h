#pragma once

#include "src/core/guardian_proxy.h" 
#include "src/managers/comms/network_config.h"
#include "lib/nlohmann_json/json.hpp"
#include <string>

namespace Comms {

using Json = nlohmann::json;

class TelemetryData
{
    public:

        TelemetryData()
        {
            temperature = Core::GuardianProxy::GetInstance()->GetTemperatureReading();
            tds = Core::GuardianProxy::GetInstance()->GetTdsReading();
        }

        std::string ToJsonString() const
        {
            Json json;
            json[NetworkConfig::SharedAttributes::TEMPERATURE] = temperature;
            json[NetworkConfig::SharedAttributes::TDS] = temperature;

            return json.dump();
        }

    private:

        float temperature;
        int tds;
};

} // namespace Core