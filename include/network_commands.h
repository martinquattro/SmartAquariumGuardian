/*!****************************************************************************
 * @file    network_commands.h
 * @brief   Definition of RPC command and parameter names for IoT communication.
 * @author  Quattrone Martin
 * @date    Nov 2025
 *******************************************************************************/

#pragma once

#include <string>

namespace NetworkCommands
{
    namespace Rpc
    {
        inline constexpr const char* FEED_NOW = "feedNow";
    }

    namespace Params
    {
        inline constexpr const char* DOSE = "dose";
        inline constexpr const char* TEMP_LIMIT = "temp_limit";
        inline constexpr const char* TDS_LIMIT  = "tds_limit";
    }
}
