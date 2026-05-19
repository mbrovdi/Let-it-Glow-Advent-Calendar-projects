Activity 2: Multiple LEDs

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.show();
  delay(1000);

  int myleds[] = {0, 3, 6, 9};
  for (int i = 0; i < 4; i++) {
    ring.setPixelColor(myleds[i], ring.Color(0, 0, 10));
  }
  ring.show();
}

void loop() {}
