
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