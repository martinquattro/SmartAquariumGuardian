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

        //! Returns the singleton instance of SmartAquariumGuardian.
        static SmartAquariumGuardian* GetInstance();

        //! Initializes the SmartAquariumGuardian system.
        static void Init();

        //! Updates the system by calling the update methods of all subsystems.
        void Update();

    private:

        SmartAquariumGuardian();
        ~SmartAquariumGuardian() = default;
        SmartAquariumGuardian(const SmartAquariumGuardian&) = delete;
        SmartAquariumGuardian& operator=(const SmartAquariumGuardian&) = delete;

        static SmartAquariumGuardian* _instance;
        Delay _delay;
};

#endif // SMART_AQUARIUM_GUARDIAN_H