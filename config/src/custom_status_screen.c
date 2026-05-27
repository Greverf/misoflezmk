#include "custom_status_screen.h"
#include <zephyr/logging/log.h>
#include <zmk/display.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static lv_obj_t *status_screen;

lv_obj_t *zmk_display_status_screen() {
    LOG_ERR("=== PANTALLA PERSONALIZADA INICIANDO ===");

    status_screen = lv_obj_create(NULL);
    if (!status_screen) {
        LOG_ERR("ERROR: No se pudo crear status_screen");
        return NULL;
    }

    lv_obj_set_size(status_screen, 128, 64);
    lv_obj_set_style_bg_color(status_screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(status_screen, LV_OPA_COVER, 0);

    lv_obj_t *label = lv_label_create(status_screen);
    if (!label) {
        LOG_ERR("ERROR: No se pudo crear label");
        return status_screen;
    }

    lv_label_set_text(label, "ZMKTEST");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_20, 0);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -10);

    lv_obj_t *label2 = lv_label_create(status_screen);
    if (label2) {
        lv_label_set_text(label2, "OK");
        lv_obj_set_style_text_color(label2, lv_color_white(), 0);
        lv_obj_set_style_text_font(label2, &lv_font_montserrat_16, 0);
        lv_obj_align(label2, LV_ALIGN_CENTER, 0, 15);
    }

    lv_obj_invalidate(status_screen);
    LOG_ERR("=== PANTALLA PERSONALIZADA LISTA ===");

    return status_screen;
}

ZMK_DISPLAY_STATUS_SCREEN(zmk_display_status_screen);