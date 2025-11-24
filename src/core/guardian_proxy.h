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

namespace Core {

class GuardianProxy : public IFoodFeeder,
                      public INetworkController,
                      public IRealTimeClock,
                      public IUserInterface,
                      public IWaterMonitor
{
    public:

        static void Init();
        static GuardianProxy* GetInstance();

    // IFoodFeeder

    // INetworkController

        //! Check if WiFi is connected
        auto IsWifiConnected() const -> bool override;

        //! Check if MQTT client is connected
        auto IsMqttConnected() const -> bool override;

    // IRealTimeClock

        //! Get current date and time
        auto GetDateTime() const -> Utils::DateTime override;
        
        //! Is time synchronized
        auto IsTimeSynced() const -> bool override;

        // Init time synchronization
        auto InitTimeSync(const char* timezone = nullptr) const -> void override;

    // IUserInterface

    // IWaterMonitor

        //! Get last TDS reading
        auto GetTdsReading() const -> int override;

        //! Get last Temperature reading
        auto GetTemperatureReading() const -> float override;

        //! Set Temperature limits
        auto SetTemperatureLimits(float minTemp, float maxTemp) -> Result override;

    private:

        GuardianProxy() = default;
        ~GuardianProxy() = default;
        GuardianProxy(const GuardianProxy&) = delete;
        GuardianProxy& operator=(const GuardianProxy&) = delete;

        //---------------------------------------------

        static GuardianProxy* _instance;
};

} // namespace Core
