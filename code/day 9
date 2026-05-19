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
  ring.show();
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  float t = temp.temperature;
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  // Map temperature (e.g., 14°C to 25°C) to LED index (0 to 11)
  int ledIndex = map((int)t, 14, 25, 0, 11);
  ledIndex = constrain(ledIndex, 0, 11);

  ring.clear();
  ring.setPixelColor(ledIndex, ring.Color(10, 0, 0)); // Red, low intensity
  ring.show();

  delay(2000);
}

