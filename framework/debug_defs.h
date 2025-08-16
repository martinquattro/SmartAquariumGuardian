/*!****************************************************************************
 * @file    debug_defs.h
 * @brief   Debug and assert macros for runtime checks in ESP32 projects.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include <cassert>
#include <cstdio>

// Debug macros for logging
#define CORE_TRACE(format, ...)     printf(format "\n", ##__VA_ARGS__)   
#define CORE_ERROR(format, ...)     printf("ERROR: " format "\n", ##__VA_ARGS__)
#define CORE_WARNING(format, ...)   printf("WARNING: " format "\n", ##__VA_ARGS__)
#define CORE_INFO(format, ...)      printf("INFO: " format "\n", ##__VA_ARGS__)

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
