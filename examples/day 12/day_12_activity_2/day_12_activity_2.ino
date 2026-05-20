The Activity #2: The everything script!

For the second activity, the same parts were used, but the code was updated to make the letters shift to the left side every second. After that, all letters disappear, wait for 2 seconds, and then the original text reappears in the middle and repeats the animation. 


Code:

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {

  // Show text in the middle