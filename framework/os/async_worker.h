/*!****************************************************************************
 * @file    async_worker.h
 * @brief   Helper class to run C++ functions in FreeRTOS tasks.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#pragma once

#include "framework/common_defs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <functional>
#include <string>

class AsyncWorker 
{
    public:

        using WorkerMethodCallback = std::function<void()>;

        /**
         * @brief Configures the worker. Does not start the task yet.
         * @param name Name for debug purposes.
         * @param stackSize Stack size in words.
         * @param priority FreeRTOS priority.
         */
        AsyncWorker(const char* name, uint32_t stackSize = 2048, UBaseType_t priority = 5);

        AsyncWorker(const AsyncWorker&) = delete;
        AsyncWorker& operator=(const AsyncWorker&) = delete;

        /**
         * @brief Starts the background task.
         * @param workFn A C++ callable containing the logic to execute.
         * @return true if started successfully, false if already running or out of memory.
         */
        bool Start(WorkerMethodCallback workFn);

        /**
         * @brief Checks if the background task is currently running.
         */
        bool IsBusy() const;

    private:

        /**
         * @brief The static C-compatible function that FreeRTOS calls.
         * It acts as a "trampoline" back into the C++ object world.
         */
        static void StaticEntryStub(void* arg);

        // ---------------------------------------------

        const char* _name;
        uint32_t _stackSize;
        UBaseType_t _priority;
        TaskHandle_t _taskHandle; 
        WorkerMethodCallback _workFn;
};