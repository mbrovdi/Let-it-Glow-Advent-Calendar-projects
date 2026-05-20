Activity 2: Bouncing Light 

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);
uint32_t myColour = strand.Color(255, 0, 0);

void setup() {
  strand.begin();
  strand.clear();
  strand.show();
  delay(1000);
}

void loop() {
  // Forward
  for (int i = 0; i < LED_COUNT; i++) {