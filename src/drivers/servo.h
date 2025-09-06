/*!****************************************************************************
 * @file    servo.h
 * @brief   Driver class for hobby servo motors using PWM (LEDC).
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef SERVO_H
#define SERVO_H

#include "framework/common_defs.h"

namespace Drivers {

    class Servo
    {
        public:
            /**
             * @brief Get the singleton instance of Servo.
             * @return Servo* Pointer to the Servo instance.
             */
            static Servo* GetInstance();

            /**
             * @brief Initialize the servo driver.
             */
            static void Init();

            /**
             * @brief Update servo state (call regularly from main loop).
             */
            void Update();

            /**
             * @brief Smoothly move servo to target angle in given time.
             * 
             * @param angle Target angle [0–180°].
             * @param timeMs Transition duration in milliseconds.
             */
            void FadeToAngle(float angle, uint32_t timeMs);

        private:

            Servo(PinName pin, uint32_t freq = 50);
            ~Servo() = default;
            Servo(const Servo&) = delete;
            Servo& operator=(const Servo&) = delete;

            //---------------------------------------------

            static constexpr float PWM_FREQUENCY    = 50;
            
            static constexpr float LOWER_DUTY       = 0.025f;
            static constexpr float HIGHER_DUTY      = 0.130f;

            static constexpr float MIN_SAFE_DUTY      = LOWER_DUTY + 0.01f;
            static constexpr float MAX_SAFE_DUTY      = HIGHER_DUTY + 0.01f;
            
            //---------------------------------------------

            static Servo* _instance;
            PwmOut _pwmOut;
    };

} // namespace Drivers

#endif // SERVO_H
