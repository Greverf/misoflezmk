#include "custom_status_screen.h"
#include <zephyr/logging/log.h>
#include <zmk/display.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static lv_obj_t *status_screen;

lv_obj_t *zmk_display_status_screen() {
    LOG_ERR("=== PANTALLA INICIANDO ===");

    status_screen = lv_obj_create(NULL);
    if (!status_screen) {
        LOG_ERR("ERROR: status_screen null");
        return NULL;
    }

    lv_obj_set_size(status_screen, 128, 64);
    lv_obj_set_style_bg_color(status_screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(status_screen, LV_OPA_COVER, 0);

    lv_obj_t *label = lv_label_create(status_screen);
    if (label) {
        lv_label_set_text(label, "TEST");
        lv_obj_set_style_text_color(label, lv_color_white(), 0);
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
        LOG_ERR("Label creado OK");
    } else {
        LOG_ERR("ERROR: label null");
    }

    lv_obj_invalidate(status_screen);
    LOG_ERR("=== PANTALLA LISTA ===");

    return status_screen;
}

ZMK_DISPLAY_STATUS_SCREEN(zmk_display_status_screen);