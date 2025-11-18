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
    namespace Rpc
    {
        inline constexpr const char* FEED_NOW           = "feedNow";
        inline constexpr const char* SET_TEMP_LIMITS    = "setTempLimits";
        inline constexpr const char* SET_TDS_LIMITS     = "setTdsLimits";
    }

    namespace SharedAttributes
    {
        inline constexpr const char* TEMP_LIMIT_MAX    = "temp_limit_max";
        inline constexpr const char* TEMP_LIMIT_MIN    = "temp_limit_min";
        inline constexpr const char* TDS_LIMIT_MAX     = "tds_limit_max";
        inline constexpr const char* TDS_LIMIT_MIN     = "tds_limit_min";
    }
}
