// Slider Fader
//
// Fade the LED in and out by mapping the potentiometer value to brightness.

#include <Adafruit_NeoPixel.h>

#define LED_PIN    2
#define NUM_LEDS   1

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  int potValue = analogRead(A1); // 0-1023
  int brightness = map(potValue, 0, 1023, 0, 255);
  strip.setPixelColor(0, strip.Color(0, 0, brightness)); // Blue fades
  strip.show();
  delay(100);
}
