// Day 9: Temperature Indication Ring
//
// Reads temperature from an AHT20/DHT20 sensor and lights a corresponding
// LED on a 12-LED ring to indicate the temperature (14-25 degrees C).

#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 2
#define NUM_LEDS     12

Adafruit_AHTX0 aht;
Adafruit_NeoPixel ring(NUM_LEDS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800);

const int minTemp = 14;
const int maxTemp = 25;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  ring.begin();
  ring.clear();
  ring.show();

  if (!aht.begin()) {
    Serial.println("Sensor not found");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  int temperature = (int)round(temp.temperature);

  if (temperature < minTemp || temperature > maxTemp) {
    Serial.println("*** Out of temperature range ***");
  } else {
    int LEDindex = temperature - minTemp;

    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("LED index:   ");
    Serial.println(LEDindex);
    Serial.println("----------------");

    ring.clear();
    ring.setPixelColor(LEDindex, ring.Color(10, 0, 0));
    ring.show();
  }

  delay(2000);
}
