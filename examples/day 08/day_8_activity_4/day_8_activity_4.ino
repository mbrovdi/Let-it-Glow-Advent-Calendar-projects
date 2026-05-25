// Activity 4: Spinning lights (loop)
//
// Spin a single blue LED around the ring.

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
  for (int i = 0; i < NUM_LEDS; i++) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(0, 0, 20)); // Blue
    ring.show();
    delay(100);
  }
}
