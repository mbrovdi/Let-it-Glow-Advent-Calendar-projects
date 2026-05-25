// Activity 2: LED Strand Colour Selector
//
// Use keypad buttons to choose color patterns on the LED strand.

#include <Adafruit_NeoPixel.h>

#define STRAND_PIN 2
#define LED_COUNT  15
#define KEY1_PIN 11
#define KEY2_PIN 10
#define KEY3_PIN 13
#define KEY4_PIN 12

Adafruit_NeoPixel strand(LED_COUNT, STRAND_PIN, NEO_RGB + NEO_KHZ800);

uint32_t aqua  = strand.Color(0, 255, 255);
uint32_t green = strand.Color(0, 255, 0);
uint32_t white = strand.Color(255, 255, 255);
uint32_t blue  = strand.Color(0, 0, 255);
uint32_t yellow = strand.Color(255, 255, 0);

void fillOddEven(uint32_t evenColor, uint32_t oddColor) {
	for (int i = 0; i < LED_COUNT; i++) {
		if ((i % 2) == 0) {
			strand.setPixelColor(i, evenColor);
		} else {
			strand.setPixelColor(i, oddColor);
		}
	}
	strand.show();
}

void setup() {
	pinMode(KEY1_PIN, INPUT_PULLDOWN);
	pinMode(KEY2_PIN, INPUT_PULLDOWN);
	pinMode(KEY3_PIN, INPUT_PULLDOWN);
	pinMode(KEY4_PIN, INPUT_PULLDOWN);

	strand.begin();
	strand.clear();
	strand.show();
}

void loop() {
	if (digitalRead(KEY1_PIN) == HIGH) {
		fillOddEven(green, aqua);
	} else if (digitalRead(KEY2_PIN) == HIGH) {
		fillOddEven(white, blue);
	} else if (digitalRead(KEY3_PIN) == HIGH) {
		fillOddEven(yellow, green);
	} else if (digitalRead(KEY4_PIN) == HIGH) {
		strand.clear();
		strand.show();
	}

	delay(120);
}