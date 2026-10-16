#pragma once

#include <cstdint>

enum class PinName : uint8_t
{
    P32,
    A6
};

class OneWire
{
    public:

        explicit OneWire(PinName) {}
        bool Reset() { return false; }
        void WriteByte(uint8_t) {}
        uint8_t ReadByte() { return 0; }
};

class AnalogIn
{
    public:

        explicit AnalogIn(PinName) {}
        float ReadVoltage(int) { return 0.0f; }
};

#define CORE_ERROR(...) ((void)0)
#define CORE_INFO(...) ((void)0)
#define CORE_WARNING(...) ((void)0)
#define TaskDelayMs(ms) ((void)0)
