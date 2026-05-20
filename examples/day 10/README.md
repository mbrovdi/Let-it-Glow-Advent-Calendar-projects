## Comparison Notes

# Day 10 - Arduino vs Raspberry Pi Pico: 15-LED RGB Dot Strand Comparisons

This file compares Day 10 activities using a 15-LED addressable RGB dot strand on the Raspberry Pi Pico (MicroPython) and Arduino MKR Zero (C++/Arduino language).

---

## Hardware Setup

| Feature | Raspberry Pi Pico | Arduino MKR Zero |
|---|---|---|
| LED type | 15x addressable RGB dot strand | 15x addressable RGB dot strand |
| Data pin | GPIO2 (physical pin 4) | D2 |
| 5V wire | Striped wire to VBUS (physical pin 40) | Striped wire to 5V |
| Ground wire | GND (physical pin 3) | GND |
| Potentiometer ADC pin | GPIO28 (physical pin 34) | A0 |
| Pot power | 3.3V (physical pin 36) | 3.3V |
| Pot ground | GND (physical pin 28 or other GND) | GND |

---

## Activity 1: Simple Strand Test

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
from neopixel import NeoPixel
import time

strand = NeoPixel(Pin(2), 15)

strand.fill((50, 0, 0))
strand.write()
time.sleep(10)

strand.fill((0, 0, 0))
strand.write()
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

#define LED_PIN   2
#define LED_COUNT 15

Adafruit_NeoPixel strand(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.clear();
	strand.fill(strand.Color(50, 0, 0), 0, LED_COUNT);
	strand.show();
	delay(10000);

	strand.clear();
	strand.show();
}

void loop() {
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Initialize LEDs | `NeoPixel(Pin(2), 15)` | `Adafruit_NeoPixel(15, 2, ...)` |
| Fill strand | `fill((r,g,b))` | `fill(Color(r,g,b), 0, LED_COUNT)` |
| Write data | `write()` | `show()` |

---

## Activity 2: Re-using Ring Programs with Variables

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
from neopixel import NeoPixel
import time

GPIOnumber = 2
LEDcount = 15
mycolour = (255, 0, 0)

strand = NeoPixel(Pin(GPIOnumber), LEDcount)

strand.fill((0, 0, 0))
strand.write()
time.sleep(1)

while True:
	for i in range(LEDcount):
		strand[i] = mycolour
		strand.write()
		time.sleep(0.09)
		strand.fill((0, 0, 0))
		strand.write()

	for i in reversed(range(LEDcount)):
		strand[i] = mycolour
		strand.write()
		time.sleep(0.09)
		strand.fill((0, 0, 0))
		strand.write()
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int gpioNumber = 2;
const int ledCount = 15;
uint8_t red = 255, green = 0, blue = 0;

Adafruit_NeoPixel strand(ledCount, gpioNumber, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.clear();
	strand.show();
	delay(1000);
}

void loop() {
	for (int i = 0; i < ledCount; i++) {
		strand.setPixelColor(i, strand.Color(red, green, blue));
		strand.show();
		delay(90);
		strand.clear();
		strand.show();
	}

	for (int i = ledCount - 1; i >= 0; i--) {
		strand.setPixelColor(i, strand.Color(red, green, blue));
		strand.show();
		delay(90);
		strand.clear();
		strand.show();
	}
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Reusable settings | Variables (`GPIOnumber`, `LEDcount`, `mycolour`) | Constants/variables (`gpioNumber`, `ledCount`, RGB bytes) |
| Reverse loop | `reversed(range(LEDcount))` | `for (int i = ledCount - 1; i >= 0; i--)` |

---

## Activity 3: range(start, stop, step) Pulsing Effect

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
from neopixel import NeoPixel
import time

GPIOnumber = 2
LEDcount = 15

strand = NeoPixel(Pin(GPIOnumber), LEDcount)
ledindex = list(range(LEDcount))

strand.fill((10, 0, 0))
strand.write()
time.sleep(1)

while True:
	for led in ledindex:
		for i in range(255, 10, -1):
			strand[led] = (i, 0, 0)
			strand.write()
			time.sleep(0.001)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int ledCount = 15;
Adafruit_NeoPixel strand(ledCount, 2, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.fill(strand.Color(10, 0, 0), 0, ledCount);
	strand.show();
	delay(1000);
}

void loop() {
	for (int led = 0; led < ledCount; led++) {
		for (int i = 255; i > 10; i--) {
			strand.setPixelColor(led, strand.Color(i, 0, 0));
			strand.show();
			delay(1);
		}
	}
}
```

### Alternate pulse color idea

Use `(i,i,i)` for white pulse and then reset each LED back to `(10,0,0)` after inner loop.

---

## Activity 4: Static Odds and Evens (Modulo)

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
from neopixel import NeoPixel
import time

strand = NeoPixel(Pin(2), 15)
red = (255, 0, 0)
green = (0, 255, 0)

strand.fill((0, 0, 0))
strand.write()
time.sleep(1)

for led in range(15):
	if (led % 2) == 0:
		strand[led] = red
	else:
		strand[led] = green
	strand.write()
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strand(15, 2, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.clear();
	strand.show();
	delay(1000);

	for (int led = 0; led < 15; led++) {
		if ((led % 2) == 0) {
			strand.setPixelColor(led, strand.Color(255, 0, 0));
		} else {
			strand.setPixelColor(led, strand.Color(0, 255, 0));
		}
	}
	strand.show();
}

void loop() {
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Modulo test | `(led % 2) == 0` | `(led % 2) == 0` |
| Static display | One pass in script | One pass in `setup()` |

---

## Activity 5: Flashing Odds and Evens

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
from neopixel import NeoPixel
import time

strand = NeoPixel(Pin(2), 15)
red = (255, 0, 0)
green = (0, 255, 0)

while True:
	for led in range(15):
		if (led % 2) == 0:
			strand[led] = red
		else:
			strand[led] = green
	strand.write()
	time.sleep(0.5)

	for led in range(15):
		if (led % 2) == 0:
			strand[led] = green
		else:
			strand[led] = red
	strand.write()
	time.sleep(0.5)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strand(15, 2, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.clear();
	strand.show();
}

void loop() {
	for (int led = 0; led < 15; led++) {
		if ((led % 2) == 0) {
			strand.setPixelColor(led, strand.Color(255, 0, 0));
		} else {
			strand.setPixelColor(led, strand.Color(0, 255, 0));
		}
	}
	strand.show();
	delay(500);

	for (int led = 0; led < 15; led++) {
		if ((led % 2) == 0) {
			strand.setPixelColor(led, strand.Color(0, 255, 0));
		} else {
			strand.setPixelColor(led, strand.Color(255, 0, 0));
		}
	}
	strand.show();
	delay(500);
}
```

---

## Activity 6: Strand Slider (Potentiometer Controls Lit Length)

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin, ADC
from neopixel import NeoPixel
import time

GPIOnumber = 2
LEDcount = 15

ring = NeoPixel(Pin(GPIOnumber), LEDcount)
potentiometer = ADC(Pin(28))

ring.fill((0, 0, 0))
ring.write()
time.sleep(1)

LEDdivision = (65535 / LEDcount)

while True:
	reading = round((potentiometer.read_u16()) / LEDdivision)

	for ledon in range(reading):
		ring[ledon] = (0, 0, 255)

	for ledoff in range(reading, LEDcount, 1):
		ring[ledoff] = (0, 0, 0)

	ring.write()
	time.sleep(0.1)
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>

const int gpioNumber = 2;
const int ledCount = 15;
const int potPin = A0;

Adafruit_NeoPixel strand(ledCount, gpioNumber, NEO_RGB + NEO_KHZ800);

void setup() {
	strand.begin();
	strand.clear();
	strand.show();
	delay(1000);
}

void loop() {
	int analogReading = analogRead(potPin);      // 0 to 1023
	int reading = map(analogReading, 0, 1023, 0, ledCount);

	for (int ledon = 0; ledon < reading; ledon++) {
		strand.setPixelColor(ledon, strand.Color(0, 0, 255));
	}

	for (int ledoff = reading; ledoff < ledCount; ledoff++) {
		strand.setPixelColor(ledoff, strand.Color(0, 0, 0));
	}

	strand.show();
	delay(100);
}
```

### Random color variant

Pico version can add `random.randint(0,255)` for `r`, `g`, `b` and use `(r,g,b)` for lit LEDs. Arduino version uses `random(0, 256)` similarly.

---

## General Language Comparison: Day 10 Concepts

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Addressable strand setup | `NeoPixel(Pin(pin), count)` | `Adafruit_NeoPixel(count, pin, mode)` |
| Update LEDs | `write()` | `show()` |
| Fill all LEDs | `fill((r,g,b))` | `fill(Color(r,g,b), ...)` |
| Start/stop/step range | `range(start, stop, step)` | `for (init; test; step)` |
| Reverse looping | `reversed(range(count))` | decrementing `for` loop |
| Odd/even test | `%` modulo | `%` modulo |
| ADC read scale | `read_u16()` => 0..65535 | `analogRead()` => 0..1023 |
| Mapping ADC to LED count | divide and round | `map()` |
| Delay unit | seconds (`time.sleep`) | milliseconds (`delay`) |

---

This comparison gives a direct translation path for Day 10 dot-strand projects between Pico MicroPython and Arduino C++.

# Day 10: ULTRA Blinky

This activity controls a 15-LED addressable RGB dot strand with Arduino MKR Zero and a slide potentiometer for interactive effect changes.

## Overview

In this project, you will:

- Wire and control a 15-LED NeoPixel dot strand
- Read potentiometer values on an analog input
- Adjust animation behavior based on slider position

## Components

- Arduino MKR Zero
- 1 x 15-LED addressable RGB dot strand
- 1 x 10k slide potentiometer
- Breadboard
- Jumper wires

## Wiring

### Dot Strand

- `5V` wire -> `5V`
- `Data` wire -> `D2`
- `GND` wire -> `GND`

### Slide Potentiometer

- Left pin (top view) -> `3.3V`
- Right pin (top view) -> `A1`
- Center pin (bottom) -> `GND`

## Libraries

Install **Adafruit NeoPixel** in Arduino IDE Library Manager.

## How to Run

1. Build the circuit.
2. Open the Day 10 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Move the potentiometer and observe pattern changes.

## Notes

- Verify strand wire labeling before connecting power.
- Keep ground common between strand and Arduino.

## Images

![Day 10 Picture 2](../../image/Day%2010,%20picture%202.png)
![Day 10 Picture 3](../../image/Day%2010,%20picture%203.png)
![Day 10 Picture 4](../../image/Day%2010,%20picture%204.png)
