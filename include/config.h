/*!****************************************************************************
 * @file    config.h
 * @brief   Configuration and pin definitions for the ESP32 Smart Aquarium Guardian project.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#include "framework/pin_names.h"

namespace Config {

// Definition of time increment used for system delays and updates
// This value is used to control the frequency of updates in the system
static constexpr int SYSTEM_TIME_INCREMENT_MS = 1000;

// Pin definitions for the Smart Aquarium Guardian
// These pins are used for various sensors and controls in the aquarium system
static constexpr PinName TDS_SENSOR_ADC_PIN = PinName::A6;
static constexpr PinName TEMP_SENSOR_PIN = PinName::P14;

// Pin for the built-in LED on the ESP32 DevKit board
// This pin is used to indicate the system status or for debugging purposes
static constexpr PinName BUILTIN_LED = PinName::P2;

} // namespace Config

#endif // CONFIG_H