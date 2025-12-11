/*!****************************************************************************
 * @file    debug_defs.h
 * @brief   Debug and assert macros for runtime checks in ESP32 projects.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include <cassert>
#include <cstring>
#include <cstdio>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define CORE_TAG (strrchr("/" __FILE__, '/') + 1)

static inline const char* get_current_task_name()
{
    if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
    {
        return pcTaskGetName(NULL);
    }
    else
    {
        return "boot";
    }
}

#define CORE_INFO(format, ...) \
    ESP_LOGI(CORE_TAG, "[%s] " format, get_current_task_name(), ##__VA_ARGS__)

#define CORE_WARNING(format, ...) \
    ESP_LOGW(CORE_TAG, "[%s] " format, get_current_task_name(), ##__VA_ARGS__)

#define CORE_ERROR(format, ...) \
    ESP_LOGE(CORE_TAG, "[%s] " format, get_current_task_name(), ##__VA_ARGS__)

// Asserts macros for runtime checks
#define ASSERT(cond)                assert(cond)
#define ASSERT_FAIL()               assert(false)
#define ASSERT_MSG(cond, msg)       do                                                                                                  \
                                    {                                                                                                   \
                                        if (!(cond))                                                                                    \
                                        {                                                                                               \
                                            printf("ASSERT FAILED: %s | File: %s, Line: %d\n", msg, __FILE__, __LINE__);                \
                                            assert(cond);                                                                               \
                                        }                                                                                               \
                                    }                                                                                                   \
                                    while (0)
