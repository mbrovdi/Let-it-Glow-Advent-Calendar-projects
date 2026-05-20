Activity #6: Scrolling text!

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns, 2 rows


String scrollText = "We have scrolling text! ";
int scrollDelay = 500; // milliseconds


void setup() {
  lcd.init();
  lcd.backlight();
}


void loop() {