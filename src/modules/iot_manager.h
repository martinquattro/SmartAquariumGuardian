/*!****************************************************************************
 * @file    iot_manager.h
 * @brief   IotManager class header file.
 * @author  Quattrone Martin
 * @date    Sep 2025
 ******************************************************************************/

#ifndef IOT_MANAGER_H
#define IOT_MANAGER_H

#include <sys/time.h>

namespace Modules {

    class IotManager
    {
        public:
        
            /*!
            * @brief Gets the singleton instance of the IotManager.
            * @return IotManager* Pointer to the IotManager instance.
            */
            static IotManager* GetInstance();

            /*!
            * @brief Initializes the IotManager.
            */
            static void Init();

            /*!
            * @brief Updates the IotManager state.
            */
            void Update();

        private:

            /*! @brief Callback function for time synchronization.
            * @param tv    Pointer to timeval structure with the synchronized time.
            */
            static void TimeSyncCallback(struct ::timeval *tv);

            IotManager() {}
            ~IotManager() = default;
            IotManager(const IotManager&) = delete;
            IotManager& operator=(const IotManager&) = delete;

            //---------------------------------------------

            static IotManager* _instance;
            bool _isTimeSynced;
    };

} // namespace Modules

#endif // IOT_MANAGER_H
