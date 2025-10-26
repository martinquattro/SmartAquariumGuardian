/*!****************************************************************************
 * @file    guardian_public_interfaces.h
 * @brief   Collection of abstract public interfaces exposing manager behaviors.
 *          Each interface defines the contract a Proxy can call without
 *          revealing the underlying implementation or dependencies.
 * @author  Quattrone Martin
 * @date    Oct 2025
 *******************************************************************************/

#pragma once

#include <string>
#include <cstdint>
#include "src/utils/date_time.h"

namespace Core {

//-----------------------------------------------------------------------------
class IFoodFeeder
{
    public:

};

//-----------------------------------------------------------------------------
class INetworkController
{
    public:

        //! Check if WiFi is connected
        virtual auto IsWifiConnected() const -> bool = 0;

        //! Check if MQTT client is connected
        virtual auto IsMqttConnected() const -> bool = 0;
};

//-----------------------------------------------------------------------------
class IRealTimeClock
{
    public:

        //! Get current date and time
        virtual auto GetDateTime() const -> Utils::DateTime = 0;

        //! Set date and time
        virtual auto SetDateTime(const Utils::DateTime& dateTime) -> bool = 0;
};

//-----------------------------------------------------------------------------
class IUserInterface
{
    public:
};

//-----------------------------------------------------------------------------
class IWaterMonitor
{
    public:

        //! Get last TDS reading
        virtual auto GetTdsReading() const -> int = 0;

        //! Get last Temperature reading
        virtual auto GetTemperatureReading() const -> float = 0;
};

} // namespace Core
