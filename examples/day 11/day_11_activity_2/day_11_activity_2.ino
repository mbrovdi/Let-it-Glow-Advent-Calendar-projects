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