#include "custom_status_screen.h"
#include <zephyr/logging/log.h>
#include <zmk/display.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    LOG_ERR("SCREEN_INIT");

    lv_obj_t *scr = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr, lv_color_black(), 0);

    lv_obj_t *lbl = lv_label_create(scr);
    lv_label_set_text(lbl, "OK");
    lv_obj_set_style_text_color(lbl, lv_color_white(), 0);
    lv_obj_center(lbl);

    LOG_ERR("SCREEN_DONE");
    return scr;
}

ZMK_DISPLAY_STATUS_SCREEN(zmk_display_status_screen);