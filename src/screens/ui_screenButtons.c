// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: EdFuelspj

#include "../ui.h"

void ui_screenButtons_screen_init(void)
{
    ui_screenButtons = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screenButtons, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_screenButtons, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_screenButtons, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_bg_img_src(ui_screenButtons, &ui_img_1367923625, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui_screenButtons, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_screenButtons_Panel7 = lv_obj_create(ui_screenButtons);
    lv_obj_set_width(ui_screenButtons_Panel7, 232);
    lv_obj_set_height(ui_screenButtons_Panel7, 122);
    lv_obj_set_x(ui_screenButtons_Panel7, 11);
    lv_obj_set_y(ui_screenButtons_Panel7, -4);
    lv_obj_set_align(ui_screenButtons_Panel7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_screenButtons_Panel7, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_screenButtons_Panel7, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_screenButtons_Panel7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_screenButtons_btnsOnbtn = lv_btn_create(ui_screenButtons_Panel7);
    lv_obj_set_width(ui_screenButtons_btnsOnbtn, 200);
    lv_obj_set_height(ui_screenButtons_btnsOnbtn, 24);
    lv_obj_set_align(ui_screenButtons_btnsOnbtn, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_screenButtons_btnsOnbtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_screenButtons_btnsOnbtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_screenButtons_btnsOnbtn, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screenButtons_btnsOnbtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_screenButtons_Label4 = lv_label_create(ui_screenButtons_btnsOnbtn);
    lv_obj_set_width(ui_screenButtons_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_screenButtons_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_screenButtons_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_screenButtons_Label4, "Screen On Brightness");
    lv_obj_set_style_bg_color(ui_screenButtons_Label4, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screenButtons_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_screenButtons_arcBOn = lv_arc_create(ui_screenButtons_Panel7);
    lv_obj_set_width(ui_screenButtons_arcBOn, 88);
    lv_obj_set_height(ui_screenButtons_arcBOn, 80);
    lv_obj_set_align(ui_screenButtons_arcBOn, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_screenButtons_arcBOn, 0, 255);
    lv_arc_set_value(ui_screenButtons_arcBOn, 50);


    ui_screenButtons_Panel8 = lv_obj_create(ui_screenButtons);
    lv_obj_set_width(ui_screenButtons_Panel8, 232);
    lv_obj_set_height(ui_screenButtons_Panel8, 122);
    lv_obj_set_x(ui_screenButtons_Panel8, 11);
    lv_obj_set_y(ui_screenButtons_Panel8, -4);
    lv_obj_set_align(ui_screenButtons_Panel8, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_screenButtons_Panel8, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_screenButtons_Panel8, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_screenButtons_Panel8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_screenButtons_Button3 = lv_btn_create(ui_screenButtons_Panel8);
    lv_obj_set_width(ui_screenButtons_Button3, 202);
    lv_obj_set_height(ui_screenButtons_Button3, 22);
    lv_obj_set_align(ui_screenButtons_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_screenButtons_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_screenButtons_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_screenButtons_Button3, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screenButtons_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_screenButtons_Label6 = lv_label_create(ui_screenButtons_Button3);
    lv_obj_set_width(ui_screenButtons_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_screenButtons_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_screenButtons_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_screenButtons_Label6, "Screen Off Brightness");
    lv_obj_set_style_bg_color(ui_screenButtons_Label6, lv_color_hex(0x9E3E3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_screenButtons_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_screenButtons_arcBOff = lv_arc_create(ui_screenButtons_Panel8);
    lv_obj_set_width(ui_screenButtons_arcBOff, 88);
    lv_obj_set_height(ui_screenButtons_arcBOff, 80);
    lv_obj_set_align(ui_screenButtons_arcBOff, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_screenButtons_arcBOff, 0, 255);
    lv_arc_set_value(ui_screenButtons_arcBOff, 50);


    ui_screenButtons_btnSave = lv_btn_create(ui_screenButtons);
    lv_obj_set_width(ui_screenButtons_btnSave, 100);
    lv_obj_set_height(ui_screenButtons_btnSave, 50);
    lv_obj_set_align(ui_screenButtons_btnSave, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_screenButtons_btnSave, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_screenButtons_btnSave, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_screenButtons_Label7 = lv_label_create(ui_screenButtons_btnSave);
    lv_obj_set_width(ui_screenButtons_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_screenButtons_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_screenButtons_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_screenButtons_Label7, "Save Values");

    lv_obj_add_event_cb(ui_screenButtons_Label4, ui_event_screenButtons_Label4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_screenButtons_arcBOn, ui_event_screenButtons_arcBOn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_screenButtons_Label6, ui_event_screenButtons_Label6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_screenButtons_arcBOff, ui_event_screenButtons_arcBOff, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_screenButtons_btnSave, ui_event_screenButtons_btnSave, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_screenButtons, ui_event_screenButtons, LV_EVENT_ALL, NULL);

}
