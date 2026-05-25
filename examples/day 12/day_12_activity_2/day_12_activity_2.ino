// Activity 2: The everything script!
//
// Scroll text left across the LCD, then clear and repeat.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {

  // Show text in the middle
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Hello, World!");

  delay(1000);

  // Shift left every 1 second
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(1000);
  }

  // Wait 2 seconds after disappearing
  lcd.clear();
  delay(2000);
}
