#pragma once

namespace Base {

template<typename T>
class Singleton
{
    protected:
        Singleton() = default;

    public:
        virtual ~Singleton() = default;
};

class Driver
{
    public:
        virtual ~Driver() = default;

        bool Init() { return OnInit(); }
        void Update() { OnUpdate(); }

    protected:
        virtual const char* GetModuleName() const = 0;
        virtual bool OnInit() = 0;
        virtual void OnUpdate() {}
};

} // namespace Base
