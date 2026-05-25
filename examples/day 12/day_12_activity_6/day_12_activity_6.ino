// Activity 6: Scrolling text!
//
// Continuously scroll a message across a 16x2 I2C LCD.

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
  scrollLeft(scrollText);
}


void scrollLeft(String text) {
  // Add 16 spaces to the end of the text
  text += "                ";


  while (true) {
    // Always start at position 0,0
    lcd.setCursor(0, 0);


    // Show the first 16 characters of the string
    lcd.print(text.substring(0, 16));


    delay(scrollDelay);


    // Update 'text' for the next loop:
    // Remove the first character and add it to the end
    text = text.substring(1) + text[0];


    // (Optional) Print to Serial for debugging
    // Serial.println(text);
  }
}
