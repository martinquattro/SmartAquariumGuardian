/*!****************************************************************************
 * @file    network_config.h
 * @brief   Network configuration constants. They should match the ones defined
 *          in the cloud platform.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include <string>

namespace NetworkConfig
{
    namespace Key
    {
        inline constexpr const char* METHOD         = "method";
        inline constexpr const char* PARAMS         = "params";
        inline constexpr const char* RESULT         = "result";
        inline constexpr const char* RESPONSE_MSG   = "message";
        inline constexpr const char* RESPONSE_DATA  = "data";
    }

    namespace Value
    {
        inline constexpr const char* RESULT_SUCCESS = "success";
        inline constexpr const char* RESULT_ERROR   = "error";
    }

    //! Keys for telemetry (time-series sensor data) - published to v1/devices/me/telemetry
    namespace TelemetryKeys
    {
        inline constexpr const char* TEMPERATURE = "temperature";
        inline constexpr const char* TDS        = "tds";
    }

    //! Keys for client attributes (device config) - published to v1/devices/me/attributes
    //! Dashboard reads CLIENT_SCOPE. Same names used in RPC params for consistency.
    namespace ClientAttributes
    {
        inline constexpr const char* TIMEZONE                = "system_timezone";
        inline constexpr const char* TEMP_LIMIT_MIN          = "temp_limit_min";
        inline constexpr const char* TEMP_LIMIT_MIN_ENABLED  = "temp_limit_min_enabled";
        inline constexpr const char* TEMP_LIMIT_MAX          = "temp_limit_max";
        inline constexpr const char* TEMP_LIMIT_MAX_ENABLED  = "temp_limit_max_enabled";
        inline constexpr const char* FEEDING_SCHEDULE        = "feeding_schedule";
        inline constexpr const char* FEED_DOSE               = "dose";
        inline constexpr const char* FEED_TIME               = "time_min";
        inline constexpr const char* FEED_SLOT_ID            = "slot_index";
        inline constexpr const char* FEED_ENABLED            = "enabled";
        inline constexpr const char* WIFI_SSID               = "wifi_ssid";
        inline constexpr const char* WIFI_RSSI               = "wifi_rssi";
        inline constexpr const char* DEVICE_TIME             = "device_time";
    }
}
