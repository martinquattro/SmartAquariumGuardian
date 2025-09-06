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

Servo* Servo::_instance = nullptr;

//----static-------------------------------------------------------------------
Servo* Servo::GetInstance()
{
    return _instance;
}

//----static-------------------------------------------------------------------
void Servo::Init()
{
    CORE_INFO("Initializing Servo...");

    if (_instance != nullptr)
    {
        CORE_ERROR("Servo already initialized!");
        return;
    }

    _instance = new Servo(Config::SERVO_FEEDER_PWM_PIN, PWM_FREQUENCY);
    _instance->_pwmOut.SetDuty(MIN_SAFE_DUTY);
}

//-----------------------------------------------------------------------------
void Servo::Update()
{
    // For now, no periodic logic.
    // In the future, could track Fade completion or add timed sequences.
    static int angle = angle + 30; // Center position
    while (true)
    {
        // _pwmOut.SetDuty(MIN_SAFE_DUTY);
        // TaskDelayMs(500);
        // _pwmOut.SetDuty(MAX_SAFE_DUTY);
        // TaskDelayMs(500);

        FadeToAngle(90, 500);
    }
}

//-----------------------------------------------------------------------------
void Servo::FadeToAngle(float angle, uint32_t timeMs)
{
    angle = std::clamp(angle, 0.0f, 180.0f);

    float duty = MIN_SAFE_DUTY + (angle / 180.0f) * (MAX_SAFE_DUTY - MIN_SAFE_DUTY);

    _pwmOut.FadeToDuty(duty, timeMs);
}

//----private------------------------------------------------------------------
Servo::Servo(PinName pin, uint32_t freq)
    : _pwmOut(pin, freq)
{}

} // namespace Drivers
