// Activity 5: Bouncing Lights
//
// Bounce a purple LED back and forth.

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
    ring.setPixelColor(i, ring.Color(10, 0, 10)); // Purple
    ring.show();
    delay(70);
  }

  for (int i = NUM_LEDS - 2; i > 0; i--) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(10, 0, 10));
    ring.show();
    delay(70);
  }
}
