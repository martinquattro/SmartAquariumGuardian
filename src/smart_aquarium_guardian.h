/*!****************************************************************************
 * @file    smart_aquarium_guardian.h
 * @brief   SmartAquariumGuardian class header file.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef SMART_AQUARIUM_GUARDIAN_H
#define SMART_AQUARIUM_GUARDIAN_H

#define SYSTEM_TIME_INCREMENT_MS   1000

class SmartAquariumGuardian
{
    public:

        //! Initializes the SmartAquariumGuardian system.
        static void Init();

        //! Returns the singleton instance of SmartAquariumGuardian.
        static SmartAquariumGuardian* GetInstance();

        //! Updates the system by calling the update methods of all subsystems.
        void Update();

    private:

        SmartAquariumGuardian();
        ~SmartAquariumGuardian() = default;
        SmartAquariumGuardian(const SmartAquariumGuardian&) = delete;
        SmartAquariumGuardian& operator=(const SmartAquariumGuardian&) = delete;

        static SmartAquariumGuardian* mInstance;
};

#endif // SMART_AQUARIUM_GUARDIAN_H