/*!****************************************************************************
 * @file    guardian_proxy.cpp
 * @brief   Central proxy delegating cross-manager interactions.
 *          Managers depend only on this Proxy (and the public interfaces),
 *          never directly on each other. Ensures clean architecture layers.
 * @author  Quattrone Martin
 * @date    Oct 2025
 *******************************************************************************/

#include "src/core/guardian_proxy.h"

#include "src/managers/food_feeder.h"
#include "src/managers/network_controller.h"
#include "src/managers/user_interface.h"
#include "src/managers/water_monitor.h"
#include "src/services/real_time_clock.h"
#include "src/services/storage_service.h"

namespace Core {

GuardianProxy* GuardianProxy::_instance = nullptr;

//----static-------------------------------------------------------------------
void GuardianProxy::Init()
{
    CORE_INFO("Initializing GuardianProxy...");

    if (_instance != nullptr)
    {
        CORE_ERROR("GuardianProxy already initialized!");
        return;
    }

    _instance = new GuardianProxy();
}

//----static-------------------------------------------------------------------
GuardianProxy* GuardianProxy::GetInstance()
{
    return _instance;
}

//----IFoodFeeder--------------------------------------------------------------
auto GuardianProxy::Feed(int dose) -> Result
{
    return Managers::FoodFeeder::GetInstance()->Feed(dose);
}

//----IFoodFeeder--------------------------------------------------------------
auto GuardianProxy::AddFeedingScheduleEntry(int minutesAfterMidnight, int slotIndex, int dose, bool enabled) -> Result
{
    return Managers::FoodFeeder::GetInstance()->AddFeedingScheduleEntry(minutesAfterMidnight, slotIndex, dose, enabled);
}

//----IFoodFeeder--------------------------------------------------------------
auto GuardianProxy::DeleteFeedingScheduleEntry(int slotIndex) -> Result
{
    return Managers::FoodFeeder::GetInstance()->DeleteFeedingScheduleEntry(slotIndex);
}

//----INetworkController--------------------------------------------------------
auto GuardianProxy::IsWifiConnected() const -> bool
{
    return Managers::NetworkController::GetInstance()->IsWiFiConnected();
}

//----INetworkController--------------------------------------------------------
auto GuardianProxy::IsMqttConnected() const -> bool
{
    return Managers::NetworkController::GetInstance()->IsMqttClientConnected();
}

//----IRealTimeClock------------------------------------------------------------
auto GuardianProxy::GetDateTime() const -> Utils::DateTime
{
    return Services::RealTimeClock::GetInstance()->GetTime();
}

//----IRealTimeClock------------------------------------------------------------
auto GuardianProxy::IsTimeSynced() const -> bool
{
    return Services::RealTimeClock::GetInstance()->IsTimeSynced();
}

//----IRealTimeClock------------------------------------------------------------
auto GuardianProxy::InitTimeSync(const char* timezone) const -> Result
{
    return Services::RealTimeClock::GetInstance()->InitTimeSync(timezone);
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::SaveTimezoneInStorage(const std::string& tz) -> bool
{
    return Services::StorageService::GetInstance()->Set<std::string>(
        Services::FieldId::TIMEZONE,
        tz
    );
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::GetTimezoneFromStorage() const -> std::string
{
    return Services::StorageService::GetInstance()->Get<std::string>(
        Services::FieldId::TIMEZONE
    );
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::SaveTempLimitsInStorage(float minTemp, bool minEnabled, float maxTemp, bool maxEnabled) -> bool
{
    bool successMin = Services::StorageService::GetInstance()->Set<float>(
        Services::FieldId::TEMP_MIN,
        minTemp
    );

    bool successMinEn = Services::StorageService::GetInstance()->Set<bool>(
        Services::FieldId::TEMP_MIN_ENABLED,
        minEnabled
    );

    bool successMax = Services::StorageService::GetInstance()->Set<float>(
        Services::FieldId::TEMP_MAX,
        maxTemp
    );

    bool successMaxEn = Services::StorageService::GetInstance()->Set<bool>(
        Services::FieldId::TEMP_MAX_ENALED,
        maxEnabled
    );

    return (successMin && successMinEn && successMax && successMaxEn);
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::GetTempLimitsFromStorage(float& minTemp, bool& minEnabled, float& maxTemp, bool& maxEnabled) const -> void
{
    minTemp = Services::StorageService::GetInstance()->Get<float>(
        Services::FieldId::TEMP_MIN
    );

    minEnabled = Services::StorageService::GetInstance()->Get<bool>(
        Services::FieldId::TEMP_MIN_ENABLED
    );

    maxTemp = Services::StorageService::GetInstance()->Get<float>(
        Services::FieldId::TEMP_MAX
    );

    maxEnabled = Services::StorageService::GetInstance()->Get<bool>(
        Services::FieldId::TEMP_MAX_ENALED
    );
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::SaveFeedingScheduleInStorage(const int timeMinutesAfterMidnight, const int slotIndex, const int dose, const bool enabled) -> bool
{
    auto scheduleList = Services::StorageService::GetInstance()->Get<Services::FeeddingScheduleList>(
        Services::FieldId::FEEDING_SCHEDULE
    );

    // Find existing entry by slotIndex
    auto it = std::find_if(
        scheduleList.begin(),
        scheduleList.end(),
        [slotIndex](const Services::FeedingScheduleEntry& entry)
        {
            return entry._id == slotIndex;
        }
    );

    if (it != scheduleList.end())
    {
        // Update existing entry
        it->_min = timeMinutesAfterMidnight;
        it->_dose = dose;
        it->_enabled = enabled;
    }
    else
    {
        // Add new entry
        Services::FeedingScheduleEntry newEntry;
        newEntry._min = timeMinutesAfterMidnight;
        newEntry._id = slotIndex;
        newEntry._dose = dose;
        newEntry._enabled = enabled;
        scheduleList.push_back(newEntry);
    }

    // Save updated schedule back to storage
    return Services::StorageService::GetInstance()->Set<Services::FeeddingScheduleList>(
        Services::FieldId::FEEDING_SCHEDULE,
        scheduleList
    );
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::GetFeedingScheduleFromStorage() const -> Services::FeeddingScheduleList
{
    return Services::StorageService::GetInstance()->Get<Services::FeeddingScheduleList>(
        Services::FieldId::FEEDING_SCHEDULE
    );
}

//----IStorageService-----------------------------------------------------------
auto GuardianProxy::RemoveFeedingScheduleFromStorage(const int slotIndex) -> bool
{ 
    return Services::StorageService::GetInstance()->RemoveFeedingScheduleFromStorage(slotIndex);
}

//----IUserInterface------------------------------------------------------------
void GuardianProxy::UpdateFeedingStatusIndicator(bool isFeeding)
{
    Managers::UserInterface::GetInstance()->UpdateFeedingStatusIndicator(isFeeding);
}

//----IWaterMonitor-------------------------------------------------------------
auto GuardianProxy::GetTdsReading() const -> int
{
    return Managers::WaterMonitor::GetInstance()->GetTdsReading();
}

//----IWaterMonitor-------------------------------------------------------------
auto GuardianProxy::GetTemperatureReading() const -> float
{
    return Managers::WaterMonitor::GetInstance()->GetTemperatureReading();
}

//----IWaterMonitor-------------------------------------------------------------
auto GuardianProxy::SetTemperatureLimits(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled) -> Result
{
    return Managers::WaterMonitor::GetInstance()->SetTemperatureLimits(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);
}

//----IWaterMonitor-------------------------------------------------------------
auto GuardianProxy::GetTemperatureLimits(float& minTemp, bool& isMinLimitEnabled, float& maxTemp, bool& isMaxLimitEnabled) const -> void
{
    Managers::WaterMonitor::GetInstance()->GetTemperatureLimits(minTemp, isMinLimitEnabled, maxTemp, isMaxLimitEnabled);
}

//----IWaterMonitor-------------------------------------------------------------
auto GuardianProxy::IsTemperatureOutOfLimits() const -> bool
{
    return Managers::WaterMonitor::GetInstance()->IsTemperatureOutOfLimits();
}

} // namespace Core
