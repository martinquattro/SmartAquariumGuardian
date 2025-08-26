/*!****************************************************************************
 * @file    smart_aquarium_guardian.h
 * @brief   SmartAquariumGuardian class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef SMART_AQUARIUM_GUARDIAN_H
#define SMART_AQUARIUM_GUARDIAN_H

#include "framework/util/delay.h"

class SmartAquariumGuardian
{
    public:

        /*!
         * @brief Gets the singleton instance of the SmartAquariumGuardian.
         * @return SmartAquariumGuardian* Pointer to the SmartAquariumGuardian instance.
         */
        static SmartAquariumGuardian* GetInstance();

        /*!
         * @brief Initializes the SmartAquariumGuardian.
         *        This method should be called once at the start of the application.
         */
        static void Init();

        /*!
         * @brief Updates the SmartAquariumGuardian state.
         *        This method should be called periodically to update the system state.
         */
        void Update();

    private:

        SmartAquariumGuardian() {}
        ~SmartAquariumGuardian() = default;
        SmartAquariumGuardian(const SmartAquariumGuardian&) = delete;
        SmartAquariumGuardian& operator=(const SmartAquariumGuardian&) = delete;

        static SmartAquariumGuardian* _instance;
        Delay _delay;
};

#endif // SMART_AQUARIUM_GUARDIAN_H