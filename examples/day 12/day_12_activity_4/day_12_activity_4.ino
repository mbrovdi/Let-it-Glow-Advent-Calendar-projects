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
const char* colorNames[] = {"Red", "Green", "Blue", "White"};
uint32_t colorValues[] = {
  strand.Color(255, 0, 0),
  strand.Color(0, 255, 0),
  strand.Color(0, 0, 255),
  strand.Color(255, 255, 255)
};
const int numColors = sizeof(colorNames) / sizeof(colorNames[0]);


void setup() {
  lcd.init();
  lcd.backlight();
  strand.begin();
  strand.show(); // Initialize all pixels to 'off'
  delay(1000);
}


void loop() {
  for (int i = 0; i < numColors; i++) {
    // Set all LEDs to the current color
    strand.fill(colorValues[i], 0, LED_COUNT);
    strand.show();


    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Strand colour:");
    lcd.setCursor(0, 1);
    lcd.print(colorNames[i]);


    delay(2000);
  }
}


