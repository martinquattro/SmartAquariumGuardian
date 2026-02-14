/*!****************************************************************************
 * @file    servo.cpp
 * @brief   Implementation of Servo class for PWM control of servo motors.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#include "src/drivers/servo.h"

#include "include/config.h"
#include <algorithm>

namespace Drivers {

//----private------------------------------------------------------------------
bool Servo::OnInit()
{
    _pwmOut.SetDuty(MIN_SAFE_DUTY);
    return true;
}

//----private------------------------------------------------------------------
void Servo::OnUpdate()
{
    // For now, no periodic logic.
    // In the future, could track Fade completion or add timed sequences.
}

//-----------------------------------------------------------------------------
void Servo::FadeToAngle(float angle, uint32_t timeMs)
{
    angle = std::clamp(angle, 0.0f, 180.0f);

    float duty = MIN_SAFE_DUTY + (angle / 180.0f) * (MAX_SAFE_DUTY - MIN_SAFE_DUTY);

    _pwmOut.FadeToDuty(duty, timeMs);
}

//----private------------------------------------------------------------------
Servo::Servo()
    : _pwmOut(Config::SERVO_FEEDER_PWM_PIN, PWM_FREQUENCY)
{}

} // namespace Drivers
