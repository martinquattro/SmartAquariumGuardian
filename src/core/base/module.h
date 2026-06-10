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
         * @param delayAfterMs Delay in milliseconds to apply after OnUpdate() (default 0).
         */
        void Update(int delayAfterMs = 0)
        {
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
        Module() = default;

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

    private:

        // Prevent copying and moving
        Module(const Module&) = delete;
        Module& operator=(const Module&) = delete;
        Module(Module&&) = delete;
        Module& operator=(Module&&) = delete;
};

} // namespace Base
