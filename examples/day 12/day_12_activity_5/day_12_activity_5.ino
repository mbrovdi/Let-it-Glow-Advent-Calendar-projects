Activity #5: The random colour finder


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>


// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);


// NeoPixel setup
#define LED_PIN    2
#define LED_COUNT  15
Adafruit_NeoPixel strand(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  lcd.init();