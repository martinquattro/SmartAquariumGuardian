/*!****************************************************************************
 * @file    module.h
 * @brief   Base abstract class for all modules (Managers, Drivers, Services).
 *          Defines common Init and Update lifecycle methods.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "src/core/base/singleton.h"
#include <cstdint>

namespace Services { class PowerController; }

namespace Base {

/**
 * @brief Base abstract class for all modules in the system.
 *
 * Provides the common lifecycle management:
 * - Init(): Initialize the module (calls OnInit internally)
 * - Update(): Periodic update (calls OnUpdate internally, optional)
 * - GetModuleName(): Get human-readable module name for logging
 *
 * All modules (Managers, Drivers, Services) inherit from this.
 *
 * @note The parent handles "Initializing <name>" logging automatically.
 *       Derived classes just need to implement OnInit(), OnUpdate() (optional).
 *
 */
class Module
{
    public:

        /**
         * @brief Virtual destructor.
         */
        virtual ~Module() = default;

        /**
         * @brief Initialize the module.
         *        Prints "Initializing <module_name>..." automatically.
         *        Calls OnInit() internally, then optionally delays.
         * @param delayAfterMs Delay in milliseconds to apply after OnInit() (default 0).
         * @return bool True if initialization successful, false otherwise.
         */
        bool Init(int delayAfterMs = 0)
        {
            CORE_INFO("%s Initializing...", GetModuleName());
            
            if (!OnInit())
            {
                CORE_ERROR("%s Failed to initialize", GetModuleName());
                return false;
            }

            CORE_INFO("%s initialized successfully", GetModuleName());

            if (delayAfterMs > 0)
            {
                TaskDelayMs(delayAfterMs);
            }

            return true;
        }

        /**
         * @brief Periodic update (optional).
         *        Calls OnUpdate() internally, then optionally delays.
         *        Only implemented by Managers and Services.
         *        Automatically detects battery mode changes and calls appropriate handlers.
         * @param delayAfterMs Delay in milliseconds to apply after OnUpdate() (default 0).
         */
        void Update(int delayAfterMs = 0)
        {
            bool enteredBatteryMode = false;
            bool exitedBatteryMode = false;
            
            _CheckBatteryModeChange(enteredBatteryMode, exitedBatteryMode);
            
            if (enteredBatteryMode)
            {
                CORE_INFO("%s entering battery mode", GetModuleName());
                OnBatteryModeEnter();
            }
            else if (exitedBatteryMode)
            {
                CORE_INFO("%s exiting battery mode", GetModuleName());
                OnBatteryModeExit();
            }
            
            OnUpdate();

            if (delayAfterMs > 0)
            {
                TaskDelayMs(delayAfterMs);
            }
        }

    protected:

        /**
         * @brief Protected constructor to prevent direct instantiation.
         */
        Module() : _lastBatteryMode(false) {}

        /**
         * @brief Get the module name for logging and debugging.
         *        Must be implemented by derived classes.
         * @return const char* Human-readable module name (e.g., "WaterMonitor").
         */
        virtual const char* GetModuleName() const = 0;

        /**
         * @brief Pure virtual initialization method.
         *        Must be implemented by derived classes.
         *        Parent Init() calls this internally.
         * @return bool True if successful, false otherwise.
         */
        virtual bool OnInit() = 0;

        /**
         * @brief Optional periodic update method.
         *        Only needs implementation if module requires periodic updates.
         *        Parent Update() calls this internally.
         *        Default implementation does nothing (empty).
         */
        virtual void OnUpdate() {}

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
        Module(const Module&) = delete;
        Module& operator=(const Module&) = delete;
        Module(Module&&) = delete;
        Module& operator=(Module&&) = delete;

        bool _lastBatteryMode;
        uint64_t _batteryModeRecoveryEndUs = 0;  //!< esp_timer timestamp; 0 = not in recovery
        static constexpr uint32_t BATTERY_MODE_RECOVERY_MS = 1000;  //!< Ignore changes for 1s after a transition
};

} // namespace Base
