// Activity 5: The random colour finder
//
// Generate a random RGB colour, display it on the LED strand and on the LCD.

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
  lcd.backlight();
  strand.begin();
  strand.show(); // Turn off all LEDs
  delay(1000);
}


void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("This colour is:");
  lcd.setCursor(0, 1);
  lcd.print("R:   G:   B:");


  // Generate random RGB values
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);


  // Set the LED strip to the random color
  strand.fill(strand.Color(r, g, b), 0, LED_COUNT);
  strand.show();


  // Display the RGB values on the LCD
  // R value
  lcd.setCursor(2, 1);
  lcd.print(r);
  // G value
  lcd.setCursor(7, 1);
  lcd.print(g);
  // B value
  lcd.setCursor(12, 1);
  lcd.print(b);

  delay(5000); // Wait 5 seconds before next color
}
