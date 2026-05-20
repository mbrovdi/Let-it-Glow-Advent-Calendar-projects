Activity #4. Strand colour display 

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>


// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);


// NeoPixel setup
#define LED_PIN    2      // Pin connected to NeoPixel data in
#define LED_COUNT  15     // Number of LEDs in the strand


Adafruit_NeoPixel strand(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


// Color dictionary (name and RGB values)