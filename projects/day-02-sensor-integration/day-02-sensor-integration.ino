#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 12
#define LIGHT_SENSOR_PIN A1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setStripColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(LIGHT_SENSOR_PIN);
  int brightness = map(sensorValue, 0, 1023, 255, 20);
  brightness = constrain(brightness, 20, 255);

  strip.setBrightness(brightness);

  if (sensorValue < 300) {
    setStripColor(255, 140, 0);  // Warm orange in the dark.
  } else if (sensorValue < 700) {
    setStripColor(0, 80, 255);   // Cool blue in medium light.
  } else {
    setStripColor(0, 255, 80);   // Green in bright light.
  }

  Serial.print("Light sensor: ");
  Serial.print(sensorValue);
  Serial.print(" -> Brightness: ");
  Serial.println(brightness);

  delay(150);
}
