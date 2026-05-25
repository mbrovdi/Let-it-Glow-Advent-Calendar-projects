// Slider Flash Speed Control
//
// Use the potentiometer to control the speed of a flashing, randomly colored LED.

#include <Adafruit_NeoPixel.h>

#define LED_PIN    2
#define NUM_LEDS   1

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  randomSeed(analogRead(0));
}

void loop() {
  int potValue = analogRead(A1); // 0-1023
  int flashDelay = map(potValue, 0, 1023, 10, 1000); // 10ms to 1s

  int g = random(0, 256);
  int r = random(0, 256);
  int b = random(0, 256);

  strip.setPixelColor(0, strip.Color(r, g, b));
  strip.show();
  delay(flashDelay);

  strip.setPixelColor(0, strip.Color(0, 0, 0));
  strip.show();
  delay(flashDelay);
}
