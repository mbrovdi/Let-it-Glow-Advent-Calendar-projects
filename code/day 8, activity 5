Activity 5: Bouncing Lights 

Bounce a purple LED back and forth 

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.show();
  delay(1000);
}

void loop() {
  // Forward
  for (int i = 0; i < NUM_LEDS; i++) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(5, 0, 5));
    ring.show();
    delay(90);
  }
  // Backward
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    ring.clear();
    ring.setPixelColor(i, ring.Color(5, 0, 5));
    ring.show();
    delay(90);
  }
}

