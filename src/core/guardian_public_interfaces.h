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
#include "src/services/storage_service.h"
#include "src/utils/date_time.h"
#include "src/managers/food_feeder.h"

namespace Core {

//-----------------------------------------------------------------------------
class IFoodFeeder
{
    public:

        //! Feed a specific dose of food
        virtual auto Feed(int dose) -> Result = 0;

        //! Add or modify feeding schedule entry
        virtual auto AddFeedingScheduleEntry(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -> Result = 0;

        //! Delete feeding schedule entry
        virtual auto DeleteFeedingScheduleEntry(int slotIndex) -> Result = 0;

        //! Get feeder information
        virtual auto GetFeederStatus() const -> Managers::FoodFeeder::FeederStatus = 0;
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
        virtual auto InitTimeSync(const char* timezone = nullptr) const -> Result = 0;
};

//-----------------------------------------------------------------------------
class IStorageService
{
    public:

        //! Save timezone at EEPROM
        virtual bool SaveTimezoneInStorage(const std::string& tz) = 0;

        //! Get timezone from EEPROM
        virtual std::string GetTimezoneFromStorage() const = 0;

        //! Save temperature limits in storage
        virtual auto SaveTempLimitsInStorage(float minTemp, bool minEnabled, float maxTemp, bool maxEnabled) -> bool = 0;

        //! Get temperature limits from storage
        virtual auto GetTempLimitsFromStorage(float& minTemp, bool& minEnabled, float& maxTemp, bool& maxEnabled) const -> void = 0;

        //! Save feeding schedule in storage
        virtual auto SaveFeedingScheduleInStorage(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled) -> bool = 0;

        //! Get feeding schedule list
        virtual auto GetFeedingScheduleFromStorage() const -> Services::FeeddingScheduleList = 0;

        //! Remove feeding schedule from storage
        virtual auto RemoveFeedingScheduleFromStorage(const int slotIndex) -> bool = 0;

};

//-----------------------------------------------------------------------------
class IUserInterface
{
    public:

        //! Update feeding status indicator
        virtual void UpdateFeedingStatusIndicator(bool isFeeding) = 0;
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
        virtual auto SetTemperatureLimits(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled) -> Result = 0;

        //! Get Temperature limits
        virtual auto GetTemperatureLimits(float& minTemp, bool& isMinLimitEnabled, float& maxTemp, bool& isMaxLimitEnabled) const -> void = 0;

        //! Check if temperature reading is out of limits
        virtual auto IsTemperatureOutOfLimits() const -> bool = 0;
};

} // namespace Core
