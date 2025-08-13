
/*!****************************************************************************
 * @file    common.h
 * @brief   Common definitions and macros for the Smart Aquarium Guardian project.
 * @author  Quattrone Martin
 * @date    Aug 2025
 ******************************************************************************/

#ifndef COMMONDEFS_H
#define COMMONDEFS_H

#include "drivers/AnalogIn.h"
#include "drivers/DigitalOut.h"
#include "drivers/PinNames.h"
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
#define CORE_TRACE(format, ...)    printf(format, ##__VA_ARGS__)        // Debugging macro
#define CORE_TRACELN(format, ...)  printf(format "\n", ##__VA_ARGS__)   // Debugging macro with newline

#endif // COMMONDEFS_H