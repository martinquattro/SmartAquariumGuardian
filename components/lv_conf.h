#pragma once

#define LV_CONF_INCLUDE_SIMPLE 1

/*====================
 * COLOR SETTINGS
 *====================*/
#define LV_COLOR_DEPTH 16
#define LV_COLOR_16_SWAP 0
#define LV_DITHER_GRADIENT 1

/*====================
 * MEMORY SETTINGS
 *====================*/
#define LV_MEM_CUSTOM 0
#define LV_MEM_SIZE (64 * 1024)

/*====================
 * HAL SETTINGS
 *====================*/
#define LV_TICK_CUSTOM 1
#define LV_TICK_CUSTOM_INCLUDE "esp_timer.h"
#define LV_TICK_CUSTOM_SYS_TIME_EXPR ((uint32_t)(esp_timer_get_time() / 1000))

/*====================
 * OS
 *====================*/
#define LV_USE_OS LV_OS_FREERTOS
#define LV_USE_FREERTOS_TASK_NOTIFY 1

/*====================
 * DRAW
 *====================*/
#define LV_USE_DRAW_SW 1
#define LV_DRAW_SW_COMPLEX 1

/*====================
 * FONTS
 *====================*/
#define LV_FONT_MONTSERRAT_12 1
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_DEFAULT &lv_font_montserrat_14

/*====================
 * WIDGETS (mínimo)
 *====================*/
#define LV_USE_LABEL 1
#define LV_USE_IMAGE 1
#define LV_USE_BUTTON 1