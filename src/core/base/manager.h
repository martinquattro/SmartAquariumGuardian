/*!****************************************************************************
 * @file    manager.h
 * @brief   Base abstract class for all Manager implementations.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

#include "src/core/base/module.h"

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
 * The parent Module handles Init() and Update() calls and logging
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

    protected:

        /**
         * @brief Protected constructor.
         */
        Manager() {}

    private:

        // Prevent copying and moving
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&&) = delete;
};

} // namespace Base
