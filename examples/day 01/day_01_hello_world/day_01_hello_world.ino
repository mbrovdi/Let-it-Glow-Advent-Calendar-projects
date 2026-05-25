// Change the RGB LED color based on the potentiometer position
#include <Adafruit_NeoPixel.h>

#define LED_PIN    2
#define NUM_LEDS   1

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  int potValue = analogRead(A1); // 0-1023 on Arduino
  if (potValue <= 340) {
    strip.setPixelColor(0, strip.Color(255, 0, 0)); // Red
  } else if (potValue > 340 && potValue < 680) {
    strip.setPixelColor(0, strip.Color(255, 150, 0)); // Amber
  } else {
    strip.setPixelColor(0, strip.Color(0, 255, 0)); // Green
  }
  strip.show();
  delay(100);
}
