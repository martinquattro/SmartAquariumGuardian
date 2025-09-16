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

static constexpr PinName TEMP_SENSOR_PIN = PinName::P32;

static constexpr PinName SERVO_FEEDER_PWM_PIN = PinName::P5; 

static constexpr PinName LCD_RS_PIN = PinName::P4;
static constexpr PinName LCD_EN_PIN = PinName::P23;
static constexpr PinName LCD_D4_PIN = PinName::P33;
static constexpr PinName LCD_D5_PIN = PinName::P25;
static constexpr PinName LCD_D6_PIN = PinName::P26;
static constexpr PinName LCD_D7_PIN = PinName::P27;

static constexpr PinName I2C_SDA_PIN = PinName::P21;
static constexpr PinName I2C_SCL_PIN = PinName::P22;

static constexpr uint8_t EEPROM_I2C_ADDRESS = 0x50;
static constexpr uint8_t RTC_I2C_ADDRESS = 0x68; // DS3231 / DS1307

// Pin for the built-in LED on the ESP32 DevKit board
// This pin is used to indicate the system status or for debugging purposes
static constexpr PinName BUILTIN_LED = PinName::P2;

} // namespace Config

#endif // CONFIG_H