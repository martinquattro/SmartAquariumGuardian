/*!****************************************************************************
 * @file    servo.h
 * @brief   Driver class for hobby servo motors using PWM (LEDC).
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef SERVO_H
#define SERVO_H

#include "src/core/base/driver.h"
#include "framework/common_defs.h"

namespace Drivers {

class Servo : public Base::Singleton<Servo>,
              public Base::Driver
{
    public:

        /**
         * @brief Smoothly move servo to target angle in given time.
         * 
         * @param angle Target angle [0–180°].
         * @param timeMs Transition duration in milliseconds.
         */
        void FadeToAngle(float angle, uint32_t timeMs);

    private:

        friend class Base::Singleton<Servo>;

        /*!
        * @brief Get the module name.
        * @return const char* Module name.
        */
        const char* GetModuleName() const override { return "Servo"; }

        /*!
        * @brief Initializes the Module.
        *        This method should be called once at the start of the application.
        *       * @return bool True if initialization successful, false otherwise.
        */
        bool OnInit() override;

        /*!
        * @brief Updates the Module state.
        *        This method should be called periodically to update the system state.
        */
        void OnUpdate() override;

        //---------------------------------------------

        Servo();
        ~Servo() = default;
        Servo(const Servo&) = delete;
        Servo& operator=(const Servo&) = delete;

        //---------------------------------------------

        static constexpr float PWM_FREQUENCY    = 50;
        
        static constexpr float LOWER_DUTY       = 0.025f;
        static constexpr float HIGHER_DUTY      = 0.125f;

        static constexpr float MIN_SAFE_DUTY      = LOWER_DUTY + 0.01f;
        static constexpr float MAX_SAFE_DUTY      = HIGHER_DUTY - 0.01f;

        //---------------------------------------------

        PwmOut _pwmOut;
};

} // namespace Drivers

#endif // SERVO_H
