#include <Adafruit_NeoPixel.h>
#include <Keypad.h>

#define LED_PIN 6
#define LED_COUNT 12

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void fillColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

void setup() {
  strip.begin();
  strip.setBrightness(80);
  strip.show();
}

void loop() {
  char key = keypad.getKey();
  if (!key) {
    return;
  }

  switch (key) {
    case '1': fillColor(255, 0, 0); break;
    case '2': fillColor(0, 255, 0); break;
    case '3': fillColor(0, 0, 255); break;
    case '4': fillColor(255, 255, 0); break;
    case '5': fillColor(255, 0, 255); break;
    case '6': fillColor(0, 255, 255); break;
    case '0': fillColor(0, 0, 0); break;
    case 'A': strip.setBrightness(40); strip.show(); break;
    case 'B': strip.setBrightness(80); strip.show(); break;
    case 'C': strip.setBrightness(150); strip.show(); break;
    default: break;
  }
}
