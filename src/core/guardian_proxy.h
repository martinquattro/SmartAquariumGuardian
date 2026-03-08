/*!****************************************************************************
 * @file    guardian_proxy.h
 * @brief   Central proxy delegating cross-manager interactions.
 *          Managers depend only on this Proxy (and the public interfaces),
 *          never directly on each other. Ensures clean architecture layers.
 * @author  Quattrone Martin
 * @date    Oct 2025
 *******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "src/core/guardian_public_interfaces.h"
#include "src/core/base/module.h"

namespace Core {

class GuardianProxy : public Base::Singleton<GuardianProxy>,
                      public Base::Module,
                      public IStorageService,
                      public IFoodFeeder,
                      public INetworkController,
                      public IPowerController,
                      public IRealTimeClock,
                      public IUserInterface,
                      public IWaterMonitor
{
    public:

    // IFoodFeeder --------------------------------------------------------------

        //! Feed a specific dose of food
        auto Feed(int dose) -> Result override;

        //! Add or modify feeding schedule entry
        auto AddFeedingScheduleEntry(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -> Result override;

        //! Delete feeding schedule entry
        auto DeleteFeedingScheduleEntry(int slotIndex) -> Result override;

        //! Get feeder information
        auto GetFeederStatus() const -> Managers::FoodFeeder::FeederStatus override;

    // INetworkController --------------------------------------------------------

        //! Activate AP mode for configuration
        auto ActivateApMode() -> void override;

        //! Check if WiFi is connected
        auto IsWifiConnected() const -> bool override;

        //! Get connected WiFi SSID
        auto GetWifiSsid() const -> std::string override;

        //! Get WiFi RSSI in dBm
        auto GetWifiRssi() const -> int8_t override;

        //! Check if MQTT client is connected
        auto IsMqttConnected() const -> bool override;

        //! Check AP Portal state
        auto IsApPortalActive() const -> bool override;

        //! Sync device with server
        auto SyncDevice() -> Result override;

    // IPowerController --------------------------------------------------------

        //! Get current power mode
        auto GetCurrentMode() -> Services::PowerController::Mode override;
        
        //! Get battery level
        auto GetBatteryLevel() -> Services::PowerController::BatteryLevel override;

    // IRealTimeClock --------------------------------------------------------

        //! Get current date and time
        auto GetDateTime(Utils::DateTime& time) const -> bool override;
        
        //! Is time synchronized
        auto IsTimeSynced() const -> bool override;

        // Init time synchronization
        auto InitTimeSync(const char* timezone = nullptr) const -> Result override;

    // IStorageService -----------------------------------------------------------

        //! Save WiFi credentials
        auto SaveWifiCredentialsInStorage(const std::string& ssid, const std::string& password) -> bool override;

        //! Get WiFi SSID
        auto GetWifiSsidFromStorage() const -> std::string override;

        //! Get WiFi Password
        auto GetWifiPasswordFromStorage() const -> std::string override;
        
        //! Save timezone at EEPROM
        auto SaveTimezoneInStorage(const std::string& tz) -> bool override;

        //! Get timezone from EEPROM
        auto GetTimezoneFromStorage() const -> std::string override;

        //! Save temperature limits in storage
        auto SaveTempLimitsInStorage(float minTemp, bool minEnabled, float maxTemp, bool maxEnabled) -> bool override;

        //! Get temperature limits from storage
        auto GetTempLimitsFromStorage(float& minTemp, bool& minEnabled, float& maxTemp, bool& maxEnabled) const -> void override;

        //! Save TDS limits in storage
        auto SaveTdsLimitsInStorage(int minTds, bool minEnabled, int maxTds, bool maxEnabled) -> bool override;

        //! Get TDS limits from storage
        auto GetTdsLimitsFromStorage(int& minTds, bool& minEnabled, int& maxTds, bool& maxEnabled) const -> void override;

        //! Save feeding schedule in storage
        auto SaveFeedingScheduleInStorage(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled) -> bool override;
    
        //! Get feeding schedule list
        auto GetFeedingScheduleFromStorage() const -> Services::FeeddingScheduleList override;
        
        //! Remove feeding schedule from storage
        auto RemoveFeedingScheduleFromStorage(const int slotIndex) -> bool override;

        //! Factory reset (clear all stored data)
        auto FactoryReset() -> Result override;
        
    // IUserInterface --------------------------------------------------------

        //! Update feeding status indicator
        void UpdateFeedingStatusIndicator(bool isFeeding) override;

    // IWaterMonitor --------------------------------------------------------

        //! Get last TDS reading
        auto GetTdsReading() const -> int override;

        //! Get last Temperature reading
        auto GetTemperatureReading() const -> float override;

        //! Set Temperature limits
        auto SetTemperatureLimits(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled) -> Result override;

        //! Get Temperature limits
        auto GetTemperatureLimits(float& minTemp, bool& isMinLimitEnabled, float& maxTemp, bool& isMaxLimitEnabled) const -> void override;

        //! Check if temperature reading is out of limits
        auto IsTemperatureOutOfLimits() const -> bool override;

        //! Set TDS limits
        auto SetTdsLimits(const int minTds, const bool isMinLimitEnabled, const int maxTds, const bool isMaxLimitEnabled) -> Result override;

        //! Get TDS limits
        auto GetTdsLimits(int& minTds, bool& isMinLimitEnabled, int& maxTds, bool& isMaxLimitEnabled) const -> void override;

        //! Check if TDS reading is out of limits
        auto IsTdsOutOfLimits() const -> bool override;

    protected:

        friend class Base::Singleton<GuardianProxy>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "GuardianProxy"; }

        /*!
         * @brief Initializes the Module.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override { return true; }

        /*!
         * @brief Updates the Module state.
         *        This method should be called periodically to update the system state.
         */
        void OnUpdate() override {}

    private:

        GuardianProxy() = default;
        ~GuardianProxy() = default;
        GuardianProxy(const GuardianProxy&) = delete;
        GuardianProxy& operator=(const GuardianProxy&) = delete;

        //---------------------------------------------
};

} // namespace Core
