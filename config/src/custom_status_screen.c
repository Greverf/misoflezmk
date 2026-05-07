#include "custom_status_screen.h"
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    // Crear la pantalla
    lv_obj_t *screen = lv_obj_create(NULL);
    
    // Poner fondo negro
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    
    // Crear una etiqueta (label) con texto
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "HOLA MUNDO!");
    
    // Poner el texto en blanco
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    
    // Centrar el texto en la pantalla
    lv_obj_center(label);
    
    // Devolver la pantalla
    return screen;
}