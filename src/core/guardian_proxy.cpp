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
#include "src/managers/water_monitor.h"
#include "src/services/real_time_clock.h"

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
auto GuardianProxy::SetDateTime(const Utils::DateTime& dateTime) -> bool
{
    return Services::RealTimeClock::GetInstance()->SetTime(dateTime);
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

} // namespace Core
