/*!****************************************************************************
 * @file    water_monitor.h
 * @brief   WaterMonitor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef WATER_MONITOR_H
#define WATER_MONITOR_H

struct Result;

namespace Managers {

class WaterMonitor 
{
    public:

        /*!
        * @brief Gets the singleton instance of the WaterMonitor.
        * @return WaterMonitor* Pointer to the WaterMonitor instance.
        */
        static WaterMonitor* GetInstance();

        /*!
        * @brief Initializes the WaterMonitor.
        */
        static void Init();

        /*!
        * @brief Updates the WaterMonitor readings.
        */
        void Update();

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

    private:

        WaterMonitor() {}
        ~WaterMonitor() = default;
        WaterMonitor(const WaterMonitor&) = delete;
        WaterMonitor& operator=(const WaterMonitor&) = delete;

        //---------------------------------------------

        static constexpr float MIN_TEMP_VALID_VALUE = 10.0f;
        static constexpr float MAX_TEMP_VALID_VALUE = 40.0f;

        //---------------------------------------------

        static WaterMonitor* _instance;
};

} // namespace Managers

#endif // WATER_MONITOR_H
