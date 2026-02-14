/*!****************************************************************************
 * @file    singleton.h
 * @brief   Template base class providing Singleton pattern via CRTP.
 *          Provides GetInstance() for any derived class.
 * @author  Quattrone Martin
 * @date    Feb 2026
 ******************************************************************************/

#pragma once

namespace Base {

/**
 * @brief Template base class providing Singleton pattern via CRTP.
 * @tparam T The derived class (CRTP - must be passed as template parameter)
 *
 * @note The derived class automatically inherits GetInstance() without
 *       needing to define it. Just inherit from Singleton<YourClass>.
 *
 * @note Thread-safe in C++11 and later due to static local variable
 *       initialization guarantees.
 */
template <typename T>
class Singleton
{
    public:

        /**
         * @brief Get the singleton instance as a pointer.
         * Creates the instance on first call (Lazy Initialization).
         */
        static T* GetInstance()
        {
            // C++11 Magic Static: Thread-safe initialization
            static T instance;
            return &instance; 
        }

        /**
         * @brief Virtual destructor for derived classes.
         */
        virtual ~Singleton() = default;

    protected:

        /**
         * @brief Protected constructor to prevent direct instantiation.
         *
         * Only derived classes can instantiate Singleton (via CRTP).
         */
        Singleton() = default;

    private:

        // Prevent copying - ensures single instance
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        // Prevent moving - ensures single instance
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton&&) = delete;
};

} // namespace Base
