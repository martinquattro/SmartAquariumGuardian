/*!****************************************************************************
 * @file    water_monitor.h
 * @brief   WaterMonitor class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef WATER_MONITOR_H
#define WATER_MONITOR_H

#define MIN_TEMP 0
#define MAX_TEMP 85

namespace Subsystems {

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
        int GetTdsReading();

    private:

        WaterMonitor() {}
        ~WaterMonitor() = default;
        WaterMonitor(const WaterMonitor&) = delete;
        WaterMonitor& operator=(const WaterMonitor&) = delete;

        //---------------------------------------------

        static WaterMonitor* _instance;
};

} // namespace Subsystems

#endif // WATER_MONITOR_H
