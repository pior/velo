#include "FastLED.h"

#include "light.h"

CRGB rear_leds[REAR_LED_COUNT];
// CRGB side_leds[SIDE_LED_COUNT];

void init_light() {
  FastLED.addLeds<WS2812, REAR_LED_PIN, GRB>(rear_leds, REAR_LED_COUNT);
  // FastLED.addLeds<WS2812, SIDE_LED_PIN, GRB>(side_leds, SIDE_LED_COUNT);

  fill_solid(rear_leds, REAR_LED_COUNT, CRGB::Red);
  // fill_solid(side_leds, SIDE_LED_COUNT, 0xFF4000);

  FastLED.show(0);  // scale = 0 to keep it off
}
