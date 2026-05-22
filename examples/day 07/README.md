## Comparison Notes

# Day 7 - Arduino vs Raspberry Pi Pico: Potentiometer and Analogue Comparisons

This file compares Day 7 activities using a slide potentiometer with RGB LEDs on the Raspberry Pi Pico (MicroPython) and Arduino MKR Zero (C++/Arduino language).

---

## Hardware Setup

| Feature | Raspberry Pi Pico | Arduino MKR Zero |
|---|---|---|
| Input component | 10K slide potentiometer | 10K slide potentiometer |
| Analogue input pin | GPIO28 (ADC) | A0 (analog input) |
| RGB LED data pin 1 | GPIO2 | D2 |
| RGB LED data pin 2 | GPIO5 | D5 |
| Supply for addressable LED | VBUS (5V) | 5V |
| Ground | GND | GND |
| Language | MicroPython | Arduino C++ |

---

## Activity 1: Print Potentiometer Value

### Raspberry Pi Pico (MicroPython)

```python
from machine import ADC, Pin
import time

potentiometer = ADC(Pin(28))

while True:
		print(potentiometer.read_u16())
		time.sleep(0.3)
```

### Arduino MKR Zero (C++)

```cpp
const int potPin = A0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int reading = analogRead(potPin);
	Serial.println(reading);
	delay(300);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Enable analog input | ADC(Pin(28)) | analogRead(A0) |
| Read value range | 0 to 65535 (`read_u16`) | 0 to 1023 (`analogRead`) |
| Print to console | `print()` | `Serial.println()` |

---

## Activity 2: Slider Colour Changer (if/elif ranges)

### Raspberry Pi Pico (MicroPython)

```python
import time
from machine import Pin, ADC
from neopixel import NeoPixel

potentiometer = ADC(Pin(28))
GRBled = NeoPixel(Pin(2), 1)

red = 0, 255, 0
amber = 255, 175, 150
green = 255, 0, 0

while True:
		reading = potentiometer.read_u16()

		if reading <= 20000:
				GRBled.fill((red))
		elif 20000 < reading < 40000:
				GRBled.fill((amber))
		elif reading >= 40000:
				GRBled.fill((green))

		GRBled.write()
		time.sleep(0.1)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int potPin = A0;
const int ledPin = 2;
Adafruit_NeoPixel strip(1, ledPin, NEO_GRB + NEO_KHZ800);

uint32_t red = strip.Color(0, 255, 0);
uint32_t amber = strip.Color(255, 175, 150);
uint32_t green = strip.Color(255, 0, 0);

void setup() {
	Serial.begin(9600);
	strip.begin();
	strip.show();
}

void loop() {
	int reading = analogRead(potPin); // 0-1023
	Serial.println(reading);

	if (reading <= 312) {
		strip.setPixelColor(0, red);
	} else if (reading > 312 && reading < 625) {
		strip.setPixelColor(0, amber);
	} else {
		strip.setPixelColor(0, green);
	}

	strip.show();
	delay(100);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Threshold ranges | 0-65535 scale | 0-1023 scale |
| Between check | `20000 < reading < 40000` | `reading > 312 && reading < 625` |
| LED update | `fill()` then `write()` | `setPixelColor()` then `show()` |

---

## Activity 3: Slider Fader (Convert Analog to GRB 0-255)

### Raspberry Pi Pico (MicroPython)

```python
import time
from machine import Pin, ADC
from neopixel import NeoPixel

potentiometer = ADC(Pin(28))
GRBled = NeoPixel(Pin(2), 1)

while True:
		analoguereading = potentiometer.read_u16()
		GRBvalue = round(analoguereading * (255 / 65535))

		print("Analogue:", analoguereading)
		print("GRB:", GRBvalue)

		GRBled.fill((0, 0, GRBvalue))
		GRBled.write()
		time.sleep(0.1)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int potPin = A0;
const int ledPin = 2;
Adafruit_NeoPixel strip(1, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
	Serial.begin(9600);
	strip.begin();
	strip.show();
}

void loop() {
	int analogReading = analogRead(potPin);   // 0-1023
	int grbValue = map(analogReading, 0, 1023, 0, 255);

	Serial.print("Analogue: ");
	Serial.println(analogReading);
	Serial.print("GRB: ");
	Serial.println(grbValue);

	strip.setPixelColor(0, strip.Color(0, 0, grbValue));
	strip.show();
	delay(100);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Input range | 0-65535 | 0-1023 |
| Conversion style | `round(reading * (255 / 65535))` | `map(reading, 0, 1023, 0, 255)` |
| Numeric type handling | Int/float mixed automatically | Explicit `int` from `map()` |

---

## Activity 4: Slider Controls Flash Speed + Random Colour

### Raspberry Pi Pico (MicroPython)

```python
import time
import random
from machine import Pin, ADC
from neopixel import NeoPixel

potentiometer = ADC(Pin(28))
GRBled = NeoPixel(Pin(2), 1)

while True:
		flash = potentiometer.read_u16() / 65000

		g = random.randint(0, 255)
		r = random.randint(0, 255)
		b = random.randint(0, 255)

		GRBled.fill((g, r, b))
		GRBled.write()
		time.sleep(flash)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int potPin = A0;
const int ledPin = 2;
Adafruit_NeoPixel strip(1, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
	strip.begin();
	strip.show();
	randomSeed(analogRead(A1));
}

void loop() {
	int reading = analogRead(potPin);              // 0-1023
	float flash = reading / 1023.0;                // 0.0-1.0 seconds

	int g = random(0, 256);
	int r = random(0, 256);
	int b = random(0, 256);

	strip.setPixelColor(0, strip.Color(g, r, b));
	strip.show();
	delay((int)(flash * 1000));
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Delay variable | `flash` in seconds | Delay converted to milliseconds |
| Random values | `random.randint(0, 255)` | `random(0, 256)` |
| Speed scaling | divide by 65000/65535 | divide by 1023.0 |

---

## Challenge Extension: Light Both LEDs

### Pico Idea

```python
GRBled1 = NeoPixel(Pin(2), 1)
GRBled2 = NeoPixel(Pin(5), 1)

# Example inside your if/elif blocks:
GRBled1.fill((green))
GRBled2.fill((green))
GRBled1.write()
GRBled2.write()
```

### Arduino Idea

```cpp
Adafruit_NeoPixel led1(1, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led2(1, 5, NEO_GRB + NEO_KHZ800);

// Example inside your logic blocks:
led1.setPixelColor(0, green);
led2.setPixelColor(0, green);
led1.show();
led2.show();
```

---

## General Language Comparison: Day 7 Concepts

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| ADC setup | `ADC(Pin(28))` | `analogRead(A0)` |
| ADC output range | 0-65535 | 0-1023 |
| Threshold operators | `<=`, `< x <`, `>=` | `<=`, `&&`, `>=` |
| RGB library call | `NeoPixel(...).fill()/write()` | `Adafruit_NeoPixel.setPixelColor()/show()` |
| Convert analog to 0-255 | multiply and round | `map()` |
| Variable delay from slider | `time.sleep(flash)` | `delay((int)(flash * 1000))` |
| Random color | `random.randint()` | `random()` |

---

This comparison gives you a direct translation path for Day 7 potentiometer and analogue LED control between Pico MicroPython and Arduino C++.

# Day 7: Time to Slide

This activity introduces analog input using a slide potentiometer with Arduino MKR Zero. The potentiometer value can be used to control the color or behavior of addressable RGB LEDs.

## Overview

In this project, you will:

- Read potentiometer position using an analog pin
- Map analog values to LED effects in code
- Explore interactive light control

## Components

- Arduino MKR Zero
- 1 x 45 mm slide potentiometer
- 1 x potentiometer cap
- 2 x 10 mm addressable RGB LEDs
- Breadboard
- Jumper wires

## Wiring

### Slide Potentiometer

- Left pin -> `3.3V`
- Right pin -> `A1`
- Center pin -> `GND`

### RGB LEDs

- Keep RGB LED wiring the same as Day 6

## How to Run

1. Build the circuit.
2. Open the Day 7 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Move the slider and observe LED behavior changes.

## Notes

- If values move in reverse, swap the two outer potentiometer pins.
- Confirm shared ground between Arduino and LEDs.

## Images

![Day 7 Picture 1](../../image/Day%207,%20picture%201.png)
![Day 7 Picture 2](../../image/Day%207,%20picture%202.png)
