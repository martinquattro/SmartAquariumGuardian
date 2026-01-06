SET(SOURCES components/ui_comp_panel.c
    components/ui_comp.c
    screens/ui_Screen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_icn_tds_png.c
    images/ui_img_icn_range_arrow_png.c
    images/ui_img_icn_temp_png.c
    images/ui_img_icn_wifi_on_png.c
    images/ui_img_icn_wifi_off_png.c
    images/ui_img_icn_cloud_on_png.c
    images/ui_img_icn_cloud_off_png.c
    images/ui_img_icn_food_png.c
    fonts/ui_font_Bold_Font.c
    fonts/ui_font_OpenSansSemibold44.c)

add_library(ui ${SOURCES})
