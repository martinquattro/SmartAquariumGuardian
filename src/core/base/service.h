/*!****************************************************************************
 * @file    service.h
 * @brief   Base abstract class for all Service implementations.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

#include "src/core/base/module.h"

namespace Base {

/**
 * @brief Abstract base class for Service components.
 *
 * Services provide technical functionality (config, storage, time, etc.).
 * They coordinate multiple drivers and provide reusable functionality.
 *
 * Derived classes must implement:
 * - GetModuleName(): Return human-readable name (e.g., "ConfigService")
 * - OnInit(): Initialize service resources
 *
 * Services may optionally override OnUpdate() if they need periodic updates.
 *
 * The parent Module handles Init() and Update() calls and logging.
 
 */
class Service : public Module
{
    public:

        /**
         * @brief Virtual destructor.
         */
        virtual ~Service() = default;

        /**
         * @brief Services typically don't require periodic updates.
         */
        void Update() = delete;

    protected:

        /**
         * @brief Protected constructor.
         */
        Service() {}

    private:

        // Prevent copying and moving
        Service(const Service&) = delete;
        Service& operator=(const Service&) = delete;
        Service(Service&&) = delete;
        Service& operator=(Service&&) = delete;
};

} // namespace Base
