/*!****************************************************************************
 * @file    water_monitor.h
 * @brief   WaterMonitor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef WATER_MONITOR_H
#define WATER_MONITOR_H

#include "src/core/base/manager.h"
#include "src/drivers/tds_sensor.h"
#include "src/drivers/temperature_sensor.h"

struct Result;

namespace Managers {

class WaterMonitor : public Base::Singleton<WaterMonitor>
                   , public Base::Manager
{
    public:

        /*!
        * @brief Gets the last TDS reading.
        * @return int Last TDS reading.
        */
        int GetTdsReading() const;

        /*!
        * @brief Gets the last Temperature reading.
        * @return int Last Temperature reading.
        */
        float GetTemperatureReading() const;

        /*!
        * @brief Sets the temperature limits.
        * @param minTemp Minimum temperature limit.
        * @param isMinLimitEnabled Flag indicating if the minimum limit is enabled.
        * @param maxTemp Maximum temperature limit.
        * @param isMaxLimitEnabled Flag indicating if the maximum limit is enabled.
        * @return Result Result indicating success or failure.
        */
        Result SetTemperatureLimits(const float minTemp, const bool isMinLimitEnabled, const float maxTemp, const bool isMaxLimitEnabled);

        /*!
        * @brief Gets the temperature limits.
        * @param minTemp Reference to store the minimum temperature limit.
        * @param isMinLimitEnabled Reference to store if the minimum limit is enabled.
        * @param maxTemp Reference to store the maximum temperature limit.
        * @param isMaxLimitEnabled Reference to store if the maximum limit is enabled.
        */
        void GetTemperatureLimits(float& minTemp, bool& isMinLimitEnabled, float& maxTemp, bool& isMaxLimitEnabled) const;

        /*!
        * @brief Checks if the temperature reading is out of limits.
        * @return bool True if out of limits, false otherwise.
        */
        bool IsTemperatureOutOfLimits() const;

    private:

        friend class Base::Singleton<WaterMonitor>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "WaterMonitor"; }

        /*!
         * @brief Initializes the Module.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override;

        /*!
         * @brief Updates the Module state.
         *        This method should be called periodically to update the system state.
         */
        void OnUpdate() override;

        //---------------------------------------------

        WaterMonitor() {}
        ~WaterMonitor() = default;
        WaterMonitor(const WaterMonitor&) = delete;
        WaterMonitor& operator=(const WaterMonitor&) = delete;

        //---------------------------------------------

        static constexpr float MIN_TEMP_VALID_VALUE = 10.0f;
        static constexpr float MAX_TEMP_VALID_VALUE = 40.0f;

        //---------------------------------------------

        Drivers::TemperatureSensor* _temperatureSensor = nullptr;
        Drivers::TdsSensor* _tdsSensor = nullptr;
};

} // namespace Managers

#endif // WATER_MONITOR_H
