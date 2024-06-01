SET(SOURCES components/ui_comp_textbutton.c
    components/ui_comp.c
    screens/ui_ScreenFuel.c
    screens/ui_screenWiFiConfig.c
    screens/ui_screenWaitingForData.c
    screens/ui_screenButtons.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_1367923625.c
    fonts/ui_font_Eurose16.c)

add_library(ui ${SOURCES})
