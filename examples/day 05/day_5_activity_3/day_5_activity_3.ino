// Activity 2: Two LEDs, Light Passing Effect
//
// Alternate red light between two LEDs to create a passing effect.

#include <Adafruit_NeoPixel.h>

#define LED1_PIN    2
#define LED2_PIN    5
#define NUM_LEDS    1

Adafruit_NeoPixel led1(NUM_LEDS, LED1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led2(NUM_LEDS, LED2_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  led1.begin();
  led2.begin();
  led1.show();
  led2.show();
}

void loop() {
  led1.setPixelColor(0, led1.Color(255, 0, 0));
  led2.setPixelColor(0, led2.Color(0, 0, 0));
  led1.show();
  led2.show();
  delay(300);

  led1.setPixelColor(0, led1.Color(0, 0, 0));
  led2.setPixelColor(0, led2.Color(255, 0, 0));
  led1.show();
  led2.show();
  delay(300);
}