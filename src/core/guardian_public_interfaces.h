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
class IDataStore
{
    public:

        //! Save timezone at EEPROM
        virtual bool SaveTimezoneInStorage(const std::string& tz) = 0;

        //! Get timezone from EEPROM
        virtual std::string GetTimezoneFromStorage() const = 0;
};

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

        //! Is time synchronized
        virtual auto IsTimeSynced() const -> bool = 0;

        // Init time synchronization
        virtual auto InitTimeSync() const -> void = 0;
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

        //! Set Temperature limits
        virtual auto SetTemperatureLimits(float minTemp, float maxTemp) -> Result = 0;
};

} // namespace Core
