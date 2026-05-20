Activity 6: Strand Slider ( with potentiometer)

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15
#define POT_PIN    A1

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strand.begin();
  strand.clear();
  strand.show();
  delay(1000);
}

void loop() {
  int potValue = analogRead(POT_PIN); // 0-1023
  int ledCountOn = map(potValue, 0, 1023, 0, LED_COUNT);

  // Turn on LEDs up to ledCountOn
  for (int i = 0; i < LED_COUNT; i++) {
    if (i < ledCountOn) {
      strand.setPixelColor(i, strand.Color(0, 0, 255)); // Blue
    } else {
      strand.setPixelColor(i, strand.Color(0, 0, 0));   // Off
    }
  }
  strand.show();
  delay(100);
}

