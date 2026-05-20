Code:

#include <Adafruit_AHTX0.h>         // Use for DHT20/AHT20
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 2
#define NUM_LEDS     12

Adafruit_AHTX0 aht;
Adafruit_NeoPixel ring(NUM_LEDS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!aht.begin()) {
    Serial.println("Could not find AHT20/DHT20 sensor!");
    while (1) delay(10);
  }
  ring.begin();