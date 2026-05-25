// Activity 1: Simple strand Test
#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strand.begin();
  strand.show();
  strand.fill(strand.Color(50, 0, 0)); // Red, low brightness
  strand.show();
  delay(10000); // Show for 10 seconds
  strand.clear();
  strand.show();
}

void loop() {}