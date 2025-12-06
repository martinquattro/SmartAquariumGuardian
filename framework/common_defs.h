
/*!****************************************************************************
 * @file    common.h
 * @brief   Common definitions and macros for the Smart Aquarium Guardian project.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#include "esp_rom_sys.h"
#include "framework/debug_defs.h"
#include "framework/drivers/analog_in.h"
#include "framework/drivers/digital_in_out.h"
#include "framework/drivers/i2c.h"
#include "framework/drivers/one_wire.h"
#include "framework/drivers/pwm_out.h"
#include "framework/os/async_worker.h"
#include "framework/pin_names.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <optional>
#include <string>

// Functional states
#ifndef OFF
    #define OFF    0
#endif

#ifndef ON
    #define ON     (!OFF)
#endif

// Electrical states
#ifndef LOW
    #define LOW    0
#endif

#ifndef HIGH
    #define HIGH   (!LOW)
#endif

#define TaskDelayMs(ms)                vTaskDelay(pdMS_TO_TICKS(ms))        // Delay
#define TaskDelayUs(us)                esp_rom_delay_us(us)                 // Delay us

struct Result
{
    bool success;
    std::optional<std::string> responseMessage;

    static Result Success(const std::optional<std::string>& message = std::nullopt)
    {
        return { true, message };
    }

    static Result Error(const std::string& message)
    {
        return { false, message };
    }
};

#endif // COMMON_DEFS_H