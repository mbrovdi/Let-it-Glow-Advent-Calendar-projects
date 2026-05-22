Activity 4: Spinning lights (loop)

Spin a single blue LED around the ring 

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
  int myleds[] = {0, 3, 6, 9};