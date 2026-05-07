//nombre de archivo custom_status_screen.c carpeta src

#include "custom_status_screen.h"
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);
    
    // Fondo: TODOS los píxeles APAGADOS (negro)
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);
    
    // Crear etiqueta
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "HOLA MUNDO!");
    
    // Texto: Píxeles ENCENDIDOS (blanco/azul)
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    
    // Asegurar que la fuente no sea transparente
    lv_obj_set_style_text_opa(label, LV_OPA_COVER, 0);
    
    // Centrar
    lv_obj_center(label);
    
    // REFRESCO FORZADO
    lv_obj_invalidate(screen);
    
    LOG_INF("Pantalla actualizada - deberia ver texto");
    
    return screen;
}