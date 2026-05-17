#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 12

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t color, int waitMs) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(waitMs);
  }
}

void theaterChase(uint32_t color, int waitMs) {
  for (int cycle = 0; cycle < 10; cycle++) {
    for (int phase = 0; phase < 3; phase++) {
      for (int i = 0; i < strip.numPixels(); i++) {
        if ((i + phase) % 3 == 0) {
          strip.setPixelColor(i, color);
        } else {
          strip.setPixelColor(i, 0);
        }
      }
      strip.show();
      delay(waitMs);
    }
  }
}

void rainbow(int waitMs) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(waitMs);
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  colorWipe(strip.Color(255, 0, 0), 50);
  colorWipe(strip.Color(0, 255, 0), 50);
  colorWipe(strip.Color(0, 0, 255), 50);
  theaterChase(strip.Color(255, 255, 255), 80);
  rainbow(10);
}
