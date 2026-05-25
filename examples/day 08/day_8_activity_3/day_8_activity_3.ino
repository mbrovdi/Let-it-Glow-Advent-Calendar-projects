// Activity 3: Sequential Lighting with delay
//
// Light 0, 3, 6, 9 one after another.

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
  int myleds[] = {0, 3, 6, 9};
  ring.clear();

  for (int i = 0; i < 4; i++) {
    ring.setPixelColor(myleds[i], ring.Color(0, 0, 10)); // Blue
    ring.show();
    delay(250);
  }

  delay(400);
}
