Activity 2: Two LEDs, Light passing effect 

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
  // Fade in LED1 (red)
  for (int i = 0; i < 255; i++) {
    led1.setPixelColor(0, led1.Color(i, 0, 0));
    led1.show();
    delay(5);
  }
  // Turn off LED1
  led1.setPixelColor(0, led1.Color(0, 0, 0));
  led1.show();

  // Fade out LED2 (red)
  for (int i = 255; i >= 0; i--) {
    led2.setPixelColor(0, led2.Color(i, 0, 0));
    led2.show();
    delay(5);
  }
}

