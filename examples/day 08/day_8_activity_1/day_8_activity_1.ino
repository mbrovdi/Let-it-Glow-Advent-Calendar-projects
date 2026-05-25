// Activity 1: Single LED Control
//
// Light up the first LED in red.

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.show();
}

void loop() {
  ring.clear();
  ring.setPixelColor(0, ring.Color(10, 0, 0)); // Red, low intensity
  ring.show();
  delay(200);
}