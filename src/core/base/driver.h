/*!****************************************************************************
 * @file    driver_base.h
 * @brief   Base abstract class for all Driver implementations.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

#include "src/core/base/module.h"

namespace Base {

/**
 * @brief Abstract base class for Driver components.
 *
 * Drivers interface directly with hardware (sensors, actuators, LCD, etc.).
 *
 * Derived classes must implement:
 * - GetModuleName(): Return human-readable name (e.g., "TemperatureSensor")
 * - OnInit(): Initialize hardware resources
 *
 * Drivers typically don't need periodic updates.
 * If needed, override OnUpdate().
 *
 * The parent Module handles Init() call and logging.
 *
 * @note Drivers should be stateless where possible.
 *
 */
class Driver : public Module
{
    public:

        /**
         * @brief Virtual destructor.
         */
        virtual ~Driver() = default;

    protected:

        /**
         * @brief Protected constructor.
         */
        Driver() = default;

    private:

        // Prevent copying and moving
        Driver(const Driver&) = delete;
        Driver& operator=(const Driver&) = delete;
        Driver(Driver&&) = delete;
        Driver& operator=(Driver&&) = delete;
};

} // namespace Base
