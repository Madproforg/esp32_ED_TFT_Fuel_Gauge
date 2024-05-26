// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: EdFuelspj

#include "../ui.h"


// COMPONENT TextButton

lv_obj_t * ui_TextButton_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_TextButton;
    cui_TextButton = lv_btn_create(comp_parent);
    lv_obj_set_width(cui_TextButton, 100);
    lv_obj_set_height(cui_TextButton, 50);
    lv_obj_set_align(cui_TextButton, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_TextButton, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_TextButton, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_add_flag(cui_TextButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_TextButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_lblText;
    cui_lblText = lv_label_create(cui_TextButton);
    lv_obj_set_width(cui_lblText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_lblText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_lblText, -961);
    lv_obj_set_y(cui_lblText, -360);
    lv_obj_set_align(cui_lblText, LV_ALIGN_CENTER);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TEXTBUTTON_NUM);
    children[UI_COMP_TEXTBUTTON_TEXTBUTTON] = cui_TextButton;
    children[UI_COMP_TEXTBUTTON_LBLTEXT] = cui_lblText;
    lv_obj_add_event_cb(cui_TextButton, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_TextButton, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_TextButton_create_hook(cui_TextButton);
    return cui_TextButton;
}

