## Comparison Notes

# Day 12 - Arduino vs Raspberry Pi Pico: 16x2 I2C LCD Comparisons

This file compares Day 12 LCD activities on Raspberry Pi Pico (MicroPython) and Arduino MKR Zero (C++/Arduino language), including shared I2C use with the DHT20/AHT20 sensor and RGB strand integration.

---

## Hardware Setup

| Feature | Raspberry Pi Pico | Arduino MKR Zero |
|---|---|---|
| LCD type | 16x2 LCD with I2C backpack | 16x2 LCD with I2C backpack |
| LCD SDA | GPIO14 (physical pin 19) | SDA pin |
| LCD SCL | GPIO15 (physical pin 20) | SCL pin |
| LCD address | 0x27 | 0x27 (common) |
| LCD power | VCC to 5V (VBUS physical pin 40) | VCC to 5V |
| DHT20 SDA/SCL | Same I2C bus on GPIO14/15 | Same I2C bus on SDA/SCL |
| DHT20 address | 0x38 | 0x38 (with common libraries) |
| Strand data pin | GPIO2 | D2 |
| Strand count | 15 | 15 |

---

## Libraries

### Raspberry Pi Pico (MicroPython)

1. `lcd_api.py` (saved to Pico)
2. `pico_i2c_lcd.py` (saved to Pico)
3. `dht20.py` (from Day 9)
4. `neopixel` (built-in)

### Arduino MKR Zero (C++)

1. `LiquidCrystal_I2C` (or equivalent HD44780 I2C library)
2. `Adafruit_AHTX0`
3. `Adafruit_NeoPixel`
4. `Wire`

---

## Activity 1: LCD Test Program

### Raspberry Pi Pico (MicroPython)

```python
from machine import I2C, Pin
from pico_i2c_lcd import I2cLcd

SDA = 14
SCL = 15
I2C_BUS = 1
LCD_ADDR = 0x27
LCD_NUM_ROWS = 2
LCD_NUM_COLS = 16

lcdi2c = I2C(I2C_BUS, sda=Pin(SDA), scl=Pin(SCL), freq=400000)
lcd = I2cLcd(lcdi2c, LCD_ADDR, LCD_NUM_ROWS, LCD_NUM_COLS)

lcd.putstr("Hello, World!")
print("Display is now showing characters")
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
	Wire.begin();
	Serial.begin(9600);
	lcd.init();
	lcd.backlight();

	lcd.setCursor(0, 0);
	lcd.print("Hello, World!");
	Serial.println("Display is now showing characters");
}

void loop() {
}
```

---

## Activity 2: "Everything" LCD Function Demo

### Raspberry Pi Pico (MicroPython)

```python
from machine import I2C, Pin
from pico_i2c_lcd import I2cLcd
import time

lcd = I2cLcd(I2C(1, sda=Pin(14), scl=Pin(15), freq=400000), 0x27, 2, 16)

mystring = "String variable"
myinteger = 44
myfloat = 9.445589

def clearLCD():
	time.sleep(3)
	lcd.clear()

lcd.putstr("I am a string")
time.sleep(3)
lcd.clear()

lcd.move_to(0, 1)
lcd.putstr("Second row!")
clearLCD()

lcd.putstr(str(mystring))
clearLCD()

lcd.putstr(str(myinteger))
clearLCD()

lcd.putstr(str(myfloat))
clearLCD()

lcd.backlight_off()
clearLCD()

lcd.backlight_on()
clearLCD()

lcd.show_cursor()
clearLCD()

lcd.hide_cursor()
clearLCD()

lcd.blink_cursor_on()
clearLCD()

lcd.blink_cursor_off()
clearLCD()
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String mystring = "String variable";
int myinteger = 44;
float myfloat = 9.445589;

void clearLCD() {
	delay(3000);
	lcd.clear();
}

void setup() {
	Wire.begin();
	lcd.init();
	lcd.backlight();

	lcd.print("I am a string");
	delay(3000);
	lcd.clear();

	lcd.setCursor(0, 1);
	lcd.print("Second row!");
	clearLCD();

	lcd.print(mystring);
	clearLCD();

	lcd.print(myinteger);
	clearLCD();

	lcd.print(myfloat, 6);
	clearLCD();

	lcd.noBacklight();
	clearLCD();

	lcd.backlight();
	clearLCD();

	lcd.cursor();
	clearLCD();

	lcd.noCursor();
	clearLCD();

	lcd.blink();
	clearLCD();

	lcd.noBlink();
	clearLCD();
}

void loop() {
}
```

### Key Function Mapping

| Purpose | MicroPython LCD library | Arduino LCD library |
|---|---|---|
| Print text | `lcd.putstr()` | `lcd.print()` |
| Clear display | `lcd.clear()` | `lcd.clear()` |
| Move cursor | `lcd.move_to(col,row)` | `lcd.setCursor(col,row)` |
| Backlight on/off | `backlight_on/off()` | `backlight()/noBacklight()` |
| Cursor on/off | `show_cursor()/hide_cursor()` | `cursor()/noCursor()` |
| Blink on/off | `blink_cursor_on/off()` | `blink()/noBlink()` |

---

## Activity 3: Simple Counter Display

### Raspberry Pi Pico (MicroPython)

```python
for i in range(500):
	lcd.putstr("Count: " + str(i))
	time.sleep(1)
	lcd.clear()
```

### Better MicroPython counter (less flicker)

```python
lcd.putstr("Count: ")

for i in range(500):
	lcd.move_to(7, 0)
	lcd.putstr(str(i))
	time.sleep(1)
```

### Arduino MKR Zero (C++)

```cpp
void loop() {
	for (int i = 0; i < 500; i++) {
		lcd.setCursor(0, 0);
		lcd.print("Count: ");
		lcd.setCursor(7, 0);
		lcd.print("    ");
		lcd.setCursor(7, 0);
		lcd.print(i);
		delay(1000);
	}
}
```

---

## Activity 4: Current Environment Data (LCD + DHT20)

### Raspberry Pi Pico (MicroPython)

```python
from machine import I2C, Pin
from pico_i2c_lcd import I2cLcd
from dht20 import DHT20
import time

SDA = 14
SCL = 15
I2C_BUS = 1
LCD_ADDR = 0x27
TEMP_ADDR = 0x38

lcd = I2cLcd(I2C(I2C_BUS, sda=Pin(SDA), scl=Pin(SCL), freq=400000), LCD_ADDR, 2, 16)
dht20 = DHT20(TEMP_ADDR, I2C(I2C_BUS, sda=Pin(SDA), scl=Pin(SCL)))

lcd.putstr("Temp:")
lcd.move_to(0, 1)
lcd.putstr("Humidity:")

while True:
	measurements = dht20.measurements

	lcd.move_to(12, 0)
	lcd.putstr(str(round(measurements['t'], 1)))

	lcd.move_to(12, 1)
	lcd.putstr(str(round(measurements['rh'], 1)))

	time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_AHTX0.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_AHTX0 aht;

void setup() {
	Wire.begin();
	lcd.init();
	lcd.backlight();
	aht.begin();

	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.setCursor(0, 1);
	lcd.print("Humidity:");
}

void loop() {
	sensors_event_t humidity, temp;
	aht.getEvent(&humidity, &temp);

	lcd.setCursor(12, 0);
	lcd.print("    ");
	lcd.setCursor(12, 0);
	lcd.print(temp.temperature, 1);

	lcd.setCursor(12, 1);
	lcd.print("    ");
	lcd.setCursor(12, 1);
	lcd.print(humidity.relative_humidity, 1);

	delay(5000);
}
```

Note: Both LCD and sensor can share SDA/SCL when addresses differ (`0x27` LCD and `0x38` sensor).

---

## Activity 5: Lowest/Highest Temperature Display

### Raspberry Pi Pico (MicroPython)

```python
measurements = dht20.measurements
lowtemp = round(measurements['t'], 1)
hightemp = round(measurements['t'], 1)

lcd.putstr("Current:")
lcd.move_to(0, 1)
lcd.putstr("L:       H:")

lcd.move_to(3, 1)
lcd.putstr(str(lowtemp))
lcd.move_to(12, 1)
lcd.putstr(str(hightemp))

while True:
	measurements = dht20.measurements
	tempnow = round(measurements['t'], 1)

	lcd.move_to(12, 0)
	lcd.putstr(str(tempnow))

	if tempnow < lowtemp:
		lowtemp = tempnow
		lcd.move_to(3, 1)
		lcd.putstr(str(lowtemp))

	if tempnow > hightemp:
		hightemp = tempnow
		lcd.move_to(12, 1)
		lcd.putstr(str(hightemp))

	time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
float lowtemp, hightemp;

void setup() {
	// ... LCD + AHT setup ...
	sensors_event_t humidity, temp;
	aht.getEvent(&humidity, &temp);
	lowtemp = temp.temperature;
	hightemp = temp.temperature;

	lcd.setCursor(0, 0);
	lcd.print("Current:");
	lcd.setCursor(0, 1);
	lcd.print("L:       H:");
}

void loop() {
	sensors_event_t humidity, temp;
	aht.getEvent(&humidity, &temp);
	float tempnow = temp.temperature;

	lcd.setCursor(12, 0);
	lcd.print("    ");
	lcd.setCursor(12, 0);
	lcd.print(tempnow, 1);

	if (tempnow < lowtemp) {
		lowtemp = tempnow;
		lcd.setCursor(3, 1);
		lcd.print("    ");
		lcd.setCursor(3, 1);
		lcd.print(lowtemp, 1);
	}

	if (tempnow > hightemp) {
		hightemp = tempnow;
		lcd.setCursor(12, 1);
		lcd.print("    ");
		lcd.setCursor(12, 1);
		lcd.print(hightemp, 1);
	}

	delay(5000);
}
```

---

## Activity 6: Strand Colour Display (Dictionary/Map)

### Raspberry Pi Pico (MicroPython)

```python
from neopixel import NeoPixel

strand = NeoPixel(Pin(2), 15)

mycolours = {
	"Red": (255, 0, 0),
	"Green": (0, 255, 0),
	"Blue": (0, 0, 255),
	"White": (255, 255, 255),
}

strand.fill((0, 0, 0))
strand.write()
time.sleep(1)

while True:
	for i in mycolours:
		lcd.clear()
		strand.fill(mycolours[i])
		strand.write()

		lcd.putstr("Strand colour:")
		lcd.move_to(0, 1)
		lcd.putstr(str(i))

		time.sleep(2)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strand(15, 2, NEO_RGB + NEO_KHZ800);

struct NamedColor {
	const char* name;
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

NamedColor mycolours[] = {
	{"Red", 255, 0, 0},
	{"Green", 0, 255, 0},
	{"Blue", 0, 0, 255},
	{"White", 255, 255, 255}
};

void loop() {
	for (int i = 0; i < 4; i++) {
		lcd.clear();

		strand.fill(strand.Color(mycolours[i].r, mycolours[i].g, mycolours[i].b), 0, 15);
		strand.show();

		lcd.setCursor(0, 0);
		lcd.print("Strand colour:");
		lcd.setCursor(0, 1);
		lcd.print(mycolours[i].name);

		delay(2000);
	}
}
```

---

## Activity 7: Random Colour Finder

### Raspberry Pi Pico (MicroPython)

```python
import random

while True:
	lcd.clear()
	lcd.putstr("This colour is:")
	lcd.move_to(0, 1)
	lcd.putstr("R:   G:   B:")

	r = random.randint(0, 255)
	g = random.randint(0, 255)
	b = random.randint(0, 255)

	strand.fill((r, g, b))
	strand.write()

	lcd.move_to(2, 1)
	lcd.putstr(str(r))
	lcd.move_to(7, 1)
	lcd.putstr(str(g))
	lcd.move_to(12, 1)
	lcd.putstr(str(b))

	time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
void loop() {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("This colour is:");
	lcd.setCursor(0, 1);
	lcd.print("R:   G:   B:");

	int r = random(0, 256);
	int g = random(0, 256);
	int b = random(0, 256);

	strand.fill(strand.Color(r, g, b), 0, 15);
	strand.show();

	lcd.setCursor(2, 1);
	lcd.print(r);
	lcd.setCursor(7, 1);
	lcd.print(g);
	lcd.setCursor(12, 1);
	lcd.print(b);

	delay(5000);
}
```

---

## Activity 8: Scrolling Text

### Raspberry Pi Pico (MicroPython)

```python
def ScrollLeft(text):
	text = text + (16 * " ")

	while True:
		lcd.move_to(0, 0)
		lcd.putstr(text[:16])
		time.sleep(0.5)
		text = text[1:] + text[0]

ScrollLeft("We have scrolling text!")
```

### Arduino MKR Zero (C++)

```cpp
void scrollLeftText(String text) {
	text += "                "; // 16 spaces

	while (true) {
		lcd.setCursor(0, 0);
		lcd.print(text.substring(0, 16));
		delay(500);
		text = text.substring(1) + text.substring(0, 1);
	}
}

void setup() {
	// ... LCD init ...
	scrollLeftText("We have scrolling text!");
}

void loop() {
}
```

---

## General Language Comparison: Day 12 Concepts

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| I2C init | `I2C(bus, sda=Pin(), scl=Pin(), freq=...)` | `Wire.begin()` |
| LCD object | `I2cLcd(...)` | `LiquidCrystal_I2C lcd(...)` |
| Display text | `lcd.putstr()` | `lcd.print()` |
| Cursor position | `lcd.move_to(x, y)` | `lcd.setCursor(x, y)` |
| Shared I2C devices | LCD + DHT20 on same bus | LCD + AHT20 on same bus |
| Dictionary-based colors | Native dict | Struct array/map-style pattern |
| NeoPixel write | `strand.write()` | `strand.show()` |
| Random values | `random.randint(0,255)` | `random(0,256)` |
| Scroll logic | Slice/concatenate string | `substring()` + concatenate |

---

This comparison gives a direct translation path for Day 12 LCD projects between Pico MicroPython and Arduino C++.

# Day 12: Dazzling Displays

This final activity builds a simple sensor display project using an LCD and temperature sensor with Arduino hardware.

## Overview

The project focuses on:

- Reading temperature data from a sensor
- Displaying live values on an I2C LCD
- Integrating sensor and display output in one sketch

## Components

- Arduino MKR Zero (or Arduino Uno variant, based on your setup)
- I2C LCD display
- Potentiometer (for contrast adjustment, if required by your LCD module)
- Temperature sensor
- Male-to-female jumper wires

## Libraries

Install these libraries from Arduino IDE Library Manager:

- `LiquidCrystal_I2C`
- `DHT20`

## How to Run

1. Build the LCD and sensor circuit according to your module pinout.
2. Open the Day 12 sketch in Arduino IDE.
3. Select your board (**Arduino MKR Zero** or **Arduino Uno**, whichever matches your hardware).
4. Select the correct COM port.
5. Upload the sketch.
6. Verify temperature readings appear on the LCD.

## Notes

- I2C LCD modules can use different addresses (for example `0x27` or `0x3F`).
- If text is not visible, adjust LCD contrast.
- Confirm the selected board matches your physical board before uploading.

## Images

![Day 12 Picture 1](../../image/Day%2012,%20picture%201.png)
![Day 12 Picture 2](../../image/Day%2012,%20picture%202.png)
![Day 12 Picture 3](../../image/Day%2012,%20picture%203.png)
![Day 12 Picture 4](../../image/Day%2012,%20picture%204.png)
![Day 12 Picture 5](../../image/Day%2012,%20picture%205.png)