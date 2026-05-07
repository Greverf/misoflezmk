#include "custom_status_screen.h"
#include <zephyr/logging/log.h>
#include <zmk/display.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static lv_obj_t *status_screen;

lv_obj_t *zmk_display_status_screen() {
    LOG_ERR("=== CUSTOM SCREEN EJECUTANDOSE ===");
    
    status_screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(status_screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(status_screen, LV_OPA_COVER, 0);
    
    lv_obj_t *label = lv_label_create(status_screen);
    lv_label_set_text(label, "HOLA");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_24, 0);
    lv_obj_center(label);
    
    lv_obj_invalidate(status_screen);
    
    return status_screen;
}

// Registrar la pantalla en el sistema de ZMK
ZMK_DISPLAY_STATUS_SCREEN(zmk_display_status_screen);