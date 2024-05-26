// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: EdFuelspj

#include "../ui.h"

void ui_screenWaitingForData_screen_init(void)
{
    ui_screenWaitingForData = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screenWaitingForData, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_screenWaitingForData, &ui_img_1367923625, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_screenWaitingForData, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container8 = lv_obj_create(ui_screenWaitingForData);
    lv_obj_remove_style_all(ui_Container8);
    lv_obj_set_width(ui_Container8, 240);
    lv_obj_set_height(ui_Container8, 315);
    lv_obj_set_align(ui_Container8, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_Container8, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container8, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container8, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Panel2 = lv_obj_create(ui_Container8);
    lv_obj_set_width(ui_Panel2, 240);
    lv_obj_set_height(ui_Panel2, 47);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel2, lv_color_hex(0x9F4747), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Panel2);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Waiting");
    lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel5 = lv_obj_create(ui_Container8);
    lv_obj_set_width(ui_Panel5, 240);
    lv_obj_set_height(ui_Panel5, 232);
    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Panel5, LV_FLEX_FLOW_COLUMN_WRAP);
    lv_obj_set_flex_align(ui_Panel5, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel5, 60, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_lblWaiting = lv_label_create(ui_Panel5);
    lv_obj_set_width(ui_lblWaiting, 210);
    lv_obj_set_height(ui_lblWaiting, lv_pct(76));
    lv_obj_set_x(ui_lblWaiting, 2);
    lv_obj_set_y(ui_lblWaiting, -143);
    lv_obj_set_align(ui_lblWaiting, LV_ALIGN_CENTER);
    lv_label_set_text(ui_lblWaiting, "Waiting  for data  from EDMC\nplugin at address\n#0000ff *IP*#");
    lv_label_set_recolor(ui_lblWaiting, "true");
    lv_obj_clear_flag(ui_lblWaiting, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_scrollbar_mode(ui_lblWaiting, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_text_align(ui_lblWaiting, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_lblWaiting, &ui_font_Eurose16, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Panel2, ui_event_Panel2, LV_EVENT_ALL, NULL);

}