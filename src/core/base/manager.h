/*!****************************************************************************
 * @file    manager.h
 * @brief   Base abstract class for all Manager implementations.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

#include "src/core/base/module.h"
#include <cstdint>

namespace Base {

/**
 * @brief Abstract base class for Manager components.
 *
 * Managers coordinate business logic and multiple drivers/services.
 *
 * Derived classes must implement:
 * - GetModuleName(): Return human-readable name (e.g., "WaterMonitor")
 * - OnInit(): Initialize manager resources
 * - OnUpdate(): Periodic update logic
 *
 * The parent Module handles Init() and Update() calls and logging.
 * Manager::Update() additionally detects battery mode changes via PowerController.
 *
 * @note Managers typically require periodic updates. Override OnUpdate().
 */
class Manager : public Module
{
    public:
    
        /**
         * @brief Virtual destructor.
         */
        virtual ~Manager() = default;

        /**
         * @brief Periodic update with battery mode detection.
         *        Detects power source changes and calls OnBatteryModeEnter/Exit
         *        before invoking OnUpdate().
         * @param delayAfterMs Delay in milliseconds to apply after OnUpdate() (default 0).
         */
        void Update(int delayAfterMs = 0);

    protected:

        /**
         * @brief Protected constructor.
         */
        Manager() : _lastBatteryMode(false) {}

        /**
         * @brief Optional callback for entering battery mode.
         *        This can be used to reduce power consumption when running on battery.
         *        Default implementation does nothing (empty).
         */
        virtual void OnBatteryModeEnter() {}

        /**
         * @brief Optional callback for exiting battery mode.
         *        This can be used to restore normal operation when switching back to main power.
         *        Default implementation does nothing (empty).
         */
        virtual void OnBatteryModeExit() {}

    private:

        /**
         * @brief Check battery mode and update flags if state changed.
         *        Sets enteredBatteryMode=true if transitioning to battery mode.
         *        Sets exitedBatteryMode=true if transitioning out of battery mode.
         *        Ignores flickering during a recovery period after each detected change.
         * @param enteredBatteryMode Output: true if just entered battery mode
         * @param exitedBatteryMode Output: true if just exited battery mode
         */
        void _CheckBatteryModeChange(bool& enteredBatteryMode, bool& exitedBatteryMode);

        // Prevent copying and moving
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&&) = delete;

        bool _lastBatteryMode;
        uint64_t _batteryModeRecoveryEndUs = 0;  //!< esp_timer timestamp; 0 = not in recovery
        static constexpr uint32_t BATTERY_MODE_RECOVERY_MS = 1000;  //!< Ignore changes for 1s after a transition
};

} // namespace Base
