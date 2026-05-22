
Activity #3: Highest/Lowest Temperature Display Using Arduino MKR Zero 

  
The code for Arduino MKR Zero:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT20.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT20 dht20;

float highestTemp = -100;
float lowestTemp = 100;

void setup() {

  Wire.begin();


  lcd.init();
  lcd.backlight();

  dht20.begin();
}

void loop() {

  dht20.read();

  float temperature = dht20.getTemperature();

  // Update highest temperature
  if (temperature > highestTemp) {
    highestTemp = temperature;
  }

  // Update lowest temperature
  if (temperature < lowestTemp) {
    lowestTemp = temperature;
  }

  lcd.clear();

  // First row
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(highestTemp, 1);
  lcd.print((char)223);
  lcd.print("C");

  // Second row
  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lowestTemp, 1);
  lcd.print((char)223);
  lcd.print("C");


  delay(2000);
}
