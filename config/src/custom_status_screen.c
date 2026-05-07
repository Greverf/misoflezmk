//nombre de archivo custom_status_screen.c carpeta src

#include "custom_status_screen.h"
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    // Este log es CRÍTICO - lo verás por Bluetooth
    LOG_ERR("=== CUSTOM SCREEN EJECUTANDOSE ===");
    LOG_ERR("=== SI VES ESTO, LA PANTALLA FUNCIONA ===");
    
    lv_obj_t *screen = lv_obj_create(NULL);
    
    // Fondo negro
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);
    
    // Texto grande y claro
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "HOLA");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_24, 0);  // Fuente más grande
    lv_obj_center(label);
    
    // Fuerza refresco
    lv_obj_invalidate(screen);
    
    return screen;
}