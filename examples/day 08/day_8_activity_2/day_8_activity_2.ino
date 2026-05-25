// Activity 2: Multiple LEDs
//
// Light multiple LEDs on the ring at once.

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();

  int myleds[] = {0, 3, 6, 9};
  for (int i = 0; i < 4; i++) {
    ring.setPixelColor(myleds[i], ring.Color(0, 0, 10)); // Blue
  }
  ring.show();
}

void loop() {
  // Static pattern
}