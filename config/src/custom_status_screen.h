#include "custom_status_screen.h"
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);
    
    // Limpieza FORZADA de la pantalla completa
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(screen, 0, 0);
    
    // Crear el texto
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "HOLA");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_center(label);
    
    // Forzar un refresco inmediato
    lv_obj_invalidate(screen);
    lv_refr_now(NULL);
    
    return screen;
}