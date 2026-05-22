Activity #1: Test program&tweaks

The first Arduino activity was similar to the original Raspberry Pi task and was used to verify that all wires and connections are working properly. A simple program was uploaded to display text on the LCD screen. The LCD successfully showed the message “Hello, World!”, on the first row of LCD whilst printing text in the shell window. 

Setting the contrast: 

For this activity a potentiometer was used to control the LCD contrast, the first pin of the potentiometer was connected to Arduino 5V, the middle pin was connected to the LCD J3 pin, and the last pin was connected to Arduino GND. 
LCD display connected to the Arduino: 

VCC connected to 5V
GND connected to GND 
SDA connected to A4
SCL connected to A5

Code: 


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
