// Activity 4: Static Odds nEvens

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strand.begin();
  strand.clear();
  strand.show();
  delay(1000);

  for (int led = 0; led < LED_COUNT; led++) {
    if (led % 2 == 0) {
      strand.setPixelColor(led, strand.Color(255, 0, 0)); // Red for even
    } else {
      strand.setPixelColor(led, strand.Color(0, 255, 0)); // Green for odd
    }
  }
  strand.show();
}

void loop() {}