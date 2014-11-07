#include <pebble.h>
static Window *s_main_window;
static TextLayer *s_time_layer;
TextLayer *text_layer;

static void main_window_load(Window *window) {
  // Create TextLayer
  text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlack);
 
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));

  // Improve the layout to be more like a watchface
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text(text_layer, "Welcome to the Guardian App!");
}

static void main_window_unload(Window *window) {
// Destroy TextLayer
    text_layer_destroy(text_layer);
}

static void init() {
    // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

}
static void deinit() {
    // Destroy Window
    window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}