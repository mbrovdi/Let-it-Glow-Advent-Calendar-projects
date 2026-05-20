Activity 3: Fading Pulse Effect 

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strand.begin();
  strand.fill(strand.Color(10, 0, 0));
  strand.show();
  delay(1000);
}

void loop() {
  for (int led = 0; led < LED_COUNT; led++) {
    for (int i = 255; i > 10; i--) {
      strand.setPixelColor(led, strand.Color(i, i, i)); // White pulse