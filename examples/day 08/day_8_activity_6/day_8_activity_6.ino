// Activity 6: Double Random ring
//
// Choose random LEDs and random colours rapidly.

#include <Adafruit_NeoPixel.h>

#define RING_PIN   2
#define NUM_LEDS   12

Adafruit_NeoPixel ring(NUM_LEDS, RING_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  ring.begin();
  ring.clear();
  ring.show();
  randomSeed(analogRead(0));
}

void loop() {
  int ledA = random(0, NUM_LEDS);
  int ledB = random(0, NUM_LEDS);

  uint8_t r = random(0, 256);
  uint8_t g = random(0, 256);
  uint8_t b = random(0, 256);

  uint8_t r2 = random(0, 256);
  uint8_t g2 = random(0, 256);
  uint8_t b2 = random(0, 256);

  ring.clear();
  ring.setPixelColor(ledA, ring.Color(r, g, b));
  ring.setPixelColor(ledB, ring.Color(r2, g2, b2));
  ring.show();

  delay(90);
}
