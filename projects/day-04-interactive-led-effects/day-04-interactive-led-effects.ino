#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 12
#define BUTTON_PIN 7
#define POT_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int currentMode = 0;
int lastButtonState = HIGH;

void pulseEffect(uint32_t color, int speedDelay) {
  for (int b = 10; b <= 180; b += 10) {
    strip.setBrightness(b);
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(speedDelay);
  }

  for (int b = 180; b >= 10; b -= 10) {
    strip.setBrightness(b);
    strip.show();
    delay(speedDelay);
  }
}

void sparkleEffect(uint32_t color, int speedDelay) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  int pixel = random(strip.numPixels());
  strip.setPixelColor(pixel, color);
  strip.show();
  delay(speedDelay);
}

void chaseEffect(uint32_t color, int speedDelay) {
  static int position = 0;
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.setPixelColor(position, color);
  strip.setPixelColor((position + 1) % strip.numPixels(), color);
  strip.show();
  position = (position + 1) % strip.numPixels();
  delay(speedDelay);
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin();
  strip.show();
  randomSeed(analogRead(A2));
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (lastButtonState == HIGH && buttonState == LOW) {
    currentMode = (currentMode + 1) % 3;
  }
  lastButtonState = buttonState;

  int potValue = analogRead(POT_PIN);
  int speedDelay = map(potValue, 0, 1023, 150, 20);

  switch (currentMode) {
    case 0: pulseEffect(strip.Color(255, 80, 20), speedDelay); break;
    case 1: sparkleEffect(strip.Color(40, 160, 255), speedDelay); break;
    case 2: chaseEffect(strip.Color(180, 30, 255), speedDelay); break;
  }
}
