Activity 6: Double Random ring 
Random LED, random color, fast:

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.show();
  delay(1000);
  randomSeed(analogRead(0));
}

void loop() {
  int randomled = random(0, NUM_LEDS);