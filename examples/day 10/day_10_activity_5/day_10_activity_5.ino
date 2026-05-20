Activity 5: Flashing Odds n’ Evens 

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strand.begin();
  strand.clear();
  strand.show();
  delay(1000);
}

void loop() {
  // Red evens, green odds
  for (int led = 0; led < LED_COUNT; led++) {
    if (led % 2 == 0) {