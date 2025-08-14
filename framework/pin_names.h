/*!****************************************************************************
 * @file    pin_names.h
 * @brief   Logical names for GPIO pins on ESP32 DevKit boards.
 * @author  Quattrone Martin
 * @date    Aug 2025
 *******************************************************************************/

#pragma once

#include "driver/gpio.h"

enum PinName 
{
    // GPIO base
    P0  = GPIO_NUM_0,
    P1  = GPIO_NUM_1,
    P2  = GPIO_NUM_2,
    P3  = GPIO_NUM_3,
    P4  = GPIO_NUM_4,
    P5  = GPIO_NUM_5,
    P12 = GPIO_NUM_12,
    P13 = GPIO_NUM_13,
    P14 = GPIO_NUM_14,
    P15 = GPIO_NUM_15,
    P16 = GPIO_NUM_16,
    P17 = GPIO_NUM_17,
    P18 = GPIO_NUM_18,
    P19 = GPIO_NUM_19,
    P21 = GPIO_NUM_21,
    P22 = GPIO_NUM_22,
    P23 = GPIO_NUM_23,
    P25 = GPIO_NUM_25,
    P26 = GPIO_NUM_26,
    P27 = GPIO_NUM_27,
    P32 = GPIO_NUM_32,
    P33 = GPIO_NUM_33,
    P34 = GPIO_NUM_34, // input only
    P35 = GPIO_NUM_35, // input only
    P36 = GPIO_NUM_36, // input only
    P39 = GPIO_NUM_39, // input only

    // ADC aliases
    A0 = GPIO_NUM_36, // VP
    A3 = GPIO_NUM_39,
    A4 = GPIO_NUM_32,
    A5 = GPIO_NUM_33,
    A6 = GPIO_NUM_34,
    A7 = GPIO_NUM_35,
    A10 = GPIO_NUM_4,
    A11 = GPIO_NUM_0,
    A12 = GPIO_NUM_2,
    A13 = GPIO_NUM_15,
    A14 = GPIO_NUM_13,
    A15 = GPIO_NUM_12,
    A16 = GPIO_NUM_14,
    A17 = GPIO_NUM_27,
    A18 = GPIO_NUM_25,
    A19 = GPIO_NUM_26,

    // DAC outputs
    DAC1 = GPIO_NUM_25,
    DAC2 = GPIO_NUM_26,

    // Touch inputs
    T0 = GPIO_NUM_4,
    T1 = GPIO_NUM_0,
    T2 = GPIO_NUM_2,
    T3 = GPIO_NUM_15,
    T4 = GPIO_NUM_13,
    T5 = GPIO_NUM_12,
    T6 = GPIO_NUM_14,
    T7 = GPIO_NUM_27,
    T8 = GPIO_NUM_33,
    T9 = GPIO_NUM_32,

    // I2C
    SDA = GPIO_NUM_21,
    SCL = GPIO_NUM_22,

    // SPI (default HSPI)
    SCK = GPIO_NUM_18,
    MISO = GPIO_NUM_19,
    MOSI = GPIO_NUM_23,
    CS   = GPIO_NUM_5,

    // UART
    TX0 = GPIO_NUM_1,
    RX0 = GPIO_NUM_3,
    TX2 = GPIO_NUM_17,
    RX2 = GPIO_NUM_16,

    // Control pins
    EN  = GPIO_NUM_15 // careful: not always used as GPIO
};