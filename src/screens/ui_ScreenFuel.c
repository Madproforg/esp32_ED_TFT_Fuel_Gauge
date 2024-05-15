// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: EdFuelspj

#include "../ui.h"

void ui_ScreenFuel_screen_init(void)
{
    ui_ScreenFuel = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFuel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenFuel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFuel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ScreenFuel, &ui_img_1367923625, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_ScreenFuel, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container1 = lv_obj_create(ui_ScreenFuel);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, 240);
    lv_obj_set_height(ui_Container1, 296);
    lv_obj_set_align(ui_Container1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel6 = lv_obj_create(ui_Container1);
    lv_obj_set_width(ui_Panel6, 240);
    lv_obj_set_height(ui_Panel6, 41);
    lv_obj_set_x(ui_Panel6, -1);
    lv_obj_set_y(ui_Panel6, 0);
    lv_obj_set_align(ui_Panel6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Panel6, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel6, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_Panel6, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblShipName = lv_label_create(ui_Panel6);
    lv_obj_set_width(ui_lblShipName, lv_pct(95));
    lv_obj_set_height(ui_lblShipName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lblShipName, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblShipName, "");
    lv_obj_add_flag(ui_lblShipName, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_lblShipName, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_font(ui_lblShipName, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container4 = lv_obj_create(ui_Container1);
    lv_obj_remove_style_all(ui_Container4);
    lv_obj_set_width(ui_Container4, 200);
    lv_obj_set_height(ui_Container4, 20);
    lv_obj_set_x(ui_Container4, -142);
    lv_obj_set_y(ui_Container4, 73);
    lv_obj_set_flex_flow(ui_Container4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -20);
    lv_obj_set_y(ui_Label1, -35);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Main");
    lv_obj_set_style_text_font(ui_Label1, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container5 = lv_obj_create(ui_Container4);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, 19);
    lv_obj_set_height(ui_Container5, 50);
    lv_obj_set_x(ui_Container5, -104);
    lv_obj_set_y(ui_Container5, 39);
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblMainFuel = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_lblMainFuel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblMainFuel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lblMainFuel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblMainFuel, "0.00");
    lv_obj_clear_flag(ui_lblMainFuel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_font(ui_lblMainFuel, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_brMain = lv_bar_create(ui_Container1);
    lv_bar_set_mode(ui_brMain, LV_BAR_MODE_RANGE);
    lv_bar_set_value(ui_brMain, 25, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_brMain, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_brMain, 240);
    lv_obj_set_height(ui_brMain, 20);
    lv_obj_set_x(ui_brMain, -1);
    lv_obj_set_y(ui_brMain, 5);
    lv_obj_set_align(ui_brMain, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_brMain, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);     /// Flags

    ui_Container6 = lv_obj_create(ui_Container1);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_width(ui_Container6, 320);
    lv_obj_set_height(ui_Container6, 23);
    lv_obj_set_x(ui_Container6, -67);
    lv_obj_set_y(ui_Container6, 75);
    lv_obj_set_align(ui_Container6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container6, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -17);
    lv_obj_set_y(ui_Label2, 56);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Reservoir");
    lv_obj_set_style_text_font(ui_Label2, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container7 = lv_obj_create(ui_Container6);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, 19);
    lv_obj_set_height(ui_Container7, 50);
    lv_obj_set_x(ui_Container7, -104);
    lv_obj_set_y(ui_Container7, 39);
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_lblResFuel = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_lblResFuel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lblResFuel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_lblResFuel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblResFuel, "0.000");
    lv_obj_clear_flag(ui_lblResFuel, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_text_font(ui_lblResFuel, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_brRes = lv_bar_create(ui_Container1);
    lv_bar_set_mode(ui_brRes, LV_BAR_MODE_RANGE);
    lv_bar_set_value(ui_brRes, 25, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_brRes, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_brRes, 240);
    lv_obj_set_height(ui_brRes, 10);
    lv_obj_set_x(ui_brRes, 24);
    lv_obj_set_y(ui_brRes, 92);
    lv_obj_set_align(ui_brRes, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_brRes, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE);     /// Flags

    ui_Container3 = lv_obj_create(ui_Container1);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_width(ui_Container3, 100);
    lv_obj_set_height(ui_Container3, 15);
    lv_obj_set_x(ui_Container3, -97);
    lv_obj_set_y(ui_Container3, 109);
    lv_obj_set_align(ui_Container3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel4 = lv_obj_create(ui_Container1);
    lv_obj_set_width(ui_Panel4, 240);
    lv_obj_set_height(ui_Panel4, 119);
    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_spinCharging = lv_arc_create(ui_Panel4);
    lv_obj_set_width(ui_spinCharging, 64);
    lv_obj_set_height(ui_spinCharging, 64);
    lv_obj_set_align(ui_spinCharging, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_spinCharging, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_spinCharging, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_arc_set_value(ui_spinCharging, 0);
    lv_arc_set_bg_angles(ui_spinCharging, 120, 100);
    lv_arc_set_rotation(ui_spinCharging, 10);


    ui_spinLowFuel = lv_spinner_create(ui_Panel4, 1000, 90);
    lv_obj_set_width(ui_spinLowFuel, 105);
    lv_obj_set_height(ui_spinLowFuel, 105);
    lv_obj_set_align(ui_spinLowFuel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_spinLowFuel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_spinLowFuel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags

    lv_obj_set_style_arc_color(ui_spinLowFuel, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_spinLowFuel, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_spinLowFuel, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_cntDimmer = lv_obj_create(ui_ScreenFuel);
    lv_obj_remove_style_all(ui_cntDimmer);
    lv_obj_set_width(ui_cntDimmer, 240);
    lv_obj_set_height(ui_cntDimmer, 320);
    lv_obj_set_align(ui_cntDimmer, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_cntDimmer, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_cntDimmer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_cntDimmer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cntDimmer, 128, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_lblShipName, ui_event_lblShipName, LV_EVENT_ALL, NULL);

}
