/*!****************************************************************************
 * @file    smart_aquarium_guardian.h
 * @brief   SmartAquariumGuardian class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef SMART_AQUARIUM_GUARDIAN_H
#define SMART_AQUARIUM_GUARDIAN_H

#include "framework/util/delay.h"
#include "src/core/base/manager.h"

class SmartAquariumGuardian : public Base::Singleton<SmartAquariumGuardian>,
                              public Base::Manager
{
    public:

    private:

        friend class Base::Singleton<SmartAquariumGuardian>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "SmartAquariumGuardian"; }

        /*!
         * @brief Initializes the SmartAquariumGuardian.
         *        This method should be called once at the start of the application.
         *       * @return bool True if initialization successful, false otherwise.
         */
        bool OnInit() override;

        /*!
         * @brief Updates the SmartAquariumGuardian state.
         *        This method should be called periodically to update the system state.
         */
        void OnUpdate() override;

        //---------------------------------------------

        SmartAquariumGuardian() {}
        ~SmartAquariumGuardian() = default;
        SmartAquariumGuardian(const SmartAquariumGuardian&) = delete;
        SmartAquariumGuardian& operator=(const SmartAquariumGuardian&) = delete;

        //---------------------------------------------

        Delay _delay;
};

#endif // SMART_AQUARIUM_GUARDIAN_H