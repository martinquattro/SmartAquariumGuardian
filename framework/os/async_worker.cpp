/*!****************************************************************************
 * @file    async_worker.cpp
 * @brief   Implementation of AsyncWorker class to run C++ functions in FreeRTOS tasks.
 * @author  Quattrone Martin
 * @date    Dec 2025
 ******************************************************************************/

#include "framework/os/async_worker.h"

//-----------------------------------------------------------------------------
AsyncWorker::AsyncWorker(const char* name, uint32_t stackSize, UBaseType_t priority)
    : _name(name)
    , _stackSize(stackSize)
    , _priority(priority)
    , _taskHandle(nullptr) 
{}

//-----------------------------------------------------------------------------
bool AsyncWorker::Start(WorkerMethodCallback workFn)
{
    if (IsBusy())
    {
        CORE_WARNING("[%s] Worker is already busy.", _name);
        return false;
    }

    _workFn = workFn;

    BaseType_t res = xTaskCreate(
        StaticEntryStub,
        _name,
        _stackSize,
        this,
        _priority,
        &_taskHandle
    );

    if (res != pdPASS)
    {
        CORE_ERROR("[%s] Failed to create task: Out of memory?", _name);
        _taskHandle = nullptr;
        return false;
    }

    CORE_INFO("[%s] Worker started successfully.", _name);
    return true;
}

//-----------------------------------------------------------------------------
bool AsyncWorker::IsBusy() const 
{
    return _taskHandle != nullptr;
}

//-----------------------------------------------------------------------------
void AsyncWorker::StaticEntryStub(void* arg)
{
    AsyncWorker* self = static_cast<AsyncWorker*>(arg);

    CORE_INFO("[%s] Worker task started.", self->_name);

    if (self->_workFn)
    {
        self->_workFn();
    }

    CORE_INFO("[%s] Worker task finished. Cleaning up.", self->_name);

    self->_taskHandle = nullptr;
    vTaskDelete(NULL);
}