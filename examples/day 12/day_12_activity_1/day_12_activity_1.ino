// Activity 1: Test program & tweaks
//
// Display "Hello, World!" on an I2C LCD screen.
// LCD wiring: VCC -> 5V, GND -> GND, SDA -> A4, SCL -> A5

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the backlight

  lcd.setCursor(0, 0); // Column 0, Row 0
  lcd.print("Hello, World!");
}

void loop() {
  // Nothing needed here
}
