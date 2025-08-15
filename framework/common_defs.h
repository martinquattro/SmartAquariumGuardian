
/*!****************************************************************************
 * @file    common.h
 * @brief   Common definitions and macros for the Smart Aquarium Guardian project.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#include "framework/debug_defs.h"
#include "framework/drivers/analog_in.h"
#include "framework/drivers/digital_in_out.h"
#include "framework/pin_names.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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

#define delay(ms)                  vTaskDelay(pdMS_TO_TICKS(ms))        // Delay

#endif // COMMON_DEFS_H