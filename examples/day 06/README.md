## Comparison Notes

# Day 6 – Arduino vs Raspberry Pi Pico: Addressable RGB LED Comparisons

This file compares how to use addressable RGB LEDs (like NeoPixel/WS2812) on the **Raspberry Pi Pico** (MicroPython) and the **Arduino MKR Zero** (C++/Arduino language). It covers wiring, libraries, colour control, and multi-LED effects.

---

## Hardware Setup

| Feature                  | Raspberry Pi Pico              | Arduino MKR Zero               |
|--------------------------|-------------------------------|--------------------------------|
| Language                 | MicroPython                   | Arduino C++ (Wiring)           |
| Addressable LED library  | neopixel (built-in)           | Adafruit_NeoPixel (install)    |
| Data pin (LED 1)         | GPIO2 (physical pin 4)        | Digital pin 2                  |
| Data pin (LED 2)         | GPIO5 (physical pin 7)        | Digital pin 5                  |
| Power                    | VBUS (5V, pin 40)             | 5V header                      |
| GND                      | Pin 3                         | GND header                     |
| IDE / Editor             | Thonny                        | Arduino IDE                    |

---

## Activity 1: Single Colour Test

### Raspberry Pi Pico (MicroPython)

```python
import time
from machine import Pin
from neopixel import NeoPixel

GRBled = NeoPixel(Pin(2), 1)
GRBled.fill((0,0,255)) # Blue (GRB)
GRBled.write()
```

### Arduino MKR Zero (C++)

```cpp
#include <Adafruit_NeoPixel.h>
#define PIN 2
Adafruit_NeoPixel strip(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setPixelColor(0, strip.Color(0,0,255)); // Blue (GRB)
  strip.show();
}

void loop() {}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Library                  | neopixel                        | Adafruit_NeoPixel                      |
| Init LED                 | NeoPixel(Pin(2), 1)             | Adafruit_NeoPixel(1, 2, NEO_GRB...)    |
| Set colour               | fill((G,R,B))                   | setPixelColor(0, Color(G,R,B))         |
| Show/update              | write()                         | show()                                 |

---

## Activity 2: Colour Variables

### MicroPython

```python
# ...existing code...
white = 240,140,255
red = 0,255,0
# ...other colours...
GRBled.fill((red))
GRBled.write()
```

### Arduino

```cpp
uint32_t white = strip.Color(240,140,255);
uint32_t red = strip.Color(0,255,0);
// ...other colours...
strip.setPixelColor(0, red);
strip.show();
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Colour variable          | Tuple (e.g. red = 0,255,0)      | uint32_t (e.g. red = Color(0,255,0))   |
| Use variable             | fill((red))                     | setPixelColor(0, red)                  |

---

## Activity 3: Colour Cycling

### MicroPython

```python
colours = [white, red, green, blue, yellow, orange, pink, purple, iceblue, unicorn, bogey]
while True:
    for colour in colours:
        GRBled.fill((colour))
        GRBled.write()
        time.sleep(0.1)
```

### Arduino

```cpp
uint32_t colours[] = {white, red, green, blue, yellow, orange, pink, purple, iceblue, unicorn, bogey};
void loop() {
  for (int i = 0; i < sizeof(colours)/sizeof(colours[0]); i++) {
    strip.setPixelColor(0, colours[i]);
    strip.show();
    delay(100);
  }
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| List of colours          | List of tuples                   | Array of uint32_t                      |
| Loop through colours     | for colour in colours:           | for (int i = 0; i < ...; i++)          |

---

## Activity 4: Fading (Value Range)

### MicroPython

```python
while True:
    for i in range(255):
        GRBled.fill((i,0,0))
        GRBled.write()
        time.sleep(0.005)
    for i in reversed(range(255)):
        GRBled.fill((0,i,0))
        GRBled.write()
        time.sleep(0.005)
```

### Arduino

```cpp
void loop() {
  for (int i = 0; i < 255; i++) {
    strip.setPixelColor(0, strip.Color(i,0,0));
    strip.show();
    delay(5);
  }
  for (int i = 254; i >= 0; i--) {
    strip.setPixelColor(0, strip.Color(0,i,0));
    strip.show();
    delay(5);
  }
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Fade up/down             | for i in range(255) / reversed  | for (int i = 0; i < 255) / i--         |
| Set colour               | fill((i,0,0))                   | setPixelColor(0, Color(i,0,0))         |

---

## Activity 5: Two LEDs, Light Passing

### MicroPython

```python
GRBled1 = NeoPixel(Pin(2), 1)
GRBled2 = NeoPixel(Pin(5), 1)
while True:
    for i in range(255):
        GRBled1.fill((i,0,0))
        GRBled1.write()
        time.sleep(0.005)
    GRBled1.fill((0,0,0))
    GRBled1.write()
    for i in reversed(range(255)):
        GRBled2.fill((i,0,0))
        GRBled2.write()
        time.sleep(0.005)
```

### Arduino

```cpp
Adafruit_NeoPixel strip1(1, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(1, 5, NEO_GRB + NEO_KHZ800);
void setup() {
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
}
void loop() {
  for (int i = 0; i < 255; i++) {
    strip1.setPixelColor(0, strip1.Color(i,0,0));
    strip1.show();
    delay(5);
  }
  strip1.setPixelColor(0, strip1.Color(0,0,0));
  strip1.show();
  for (int i = 254; i >= 0; i--) {
    strip2.setPixelColor(0, strip2.Color(i,0,0));
    strip2.show();
    delay(5);
  }
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Multiple LEDs            | Multiple NeoPixel objects        | Multiple Adafruit_NeoPixel objects     |
| Data pins                | Pin(2), Pin(5)                  | Pin 2, Pin 5                           |
| Turn off LED             | fill((0,0,0))                   | setPixelColor(0, Color(0,0,0))         |

---

## General Language Comparison: Day 6 Concepts

| Concept                    | MicroPython (Pico)                        | Arduino (C++)                                   |
|----------------------------|-------------------------------------------|-------------------------------------------------|
| Addressable LED library    | from neopixel import NeoPixel             | #include <Adafruit_NeoPixel.h>                  |
| Init LED(s)                | NeoPixel(Pin(n), count)                   | Adafruit_NeoPixel(count, pin, NEO_GRB...)       |
| Set colour                 | fill((G,R,B))                             | setPixelColor(n, Color(G,R,B))                  |
| Show/update                | write()                                   | show()                                          |
| Colour variable            | Tuple (e.g. red = 0,255,0)                | uint32_t (e.g. red = Color(0,255,0))            |
| List of colours            | [red, green, ...]                         | uint32_t colours[] = {...}                      |
| Loop through colours       | for colour in colours:                    | for (int i = 0; i < ...; i++)                   |
| Fade effect                | for i in range(255):                      | for (int i = 0; i < 255; i++)                   |
| Multiple LEDs              | Multiple NeoPixel objects                 | Multiple Adafruit_NeoPixel objects              |
| Delay                      | time.sleep(seconds)                       | delay(milliseconds)                             |

---

This comparison should help you translate addressable RGB LED activities between MicroPython and Arduino C++ for Day 6. Adjust pin numbers and library setup as needed for your hardware.

# Day 6: See the RGB

This activity introduces addressable RGB LEDs with Arduino MKR Zero using the Adafruit NeoPixel library. You will wire one or two LEDs and control their colors in code.

## Overview

The project covers:

- Basic wiring for addressable RGB LEDs
- Single-LED and dual-LED control
- Color and effect testing with NeoPixel code

## Components

- Arduino MKR Zero
- 2 x 10 mm addressable RGB LEDs
- Breadboard
- Jumper wires

## Wiring

### Power Rails

- Arduino `5V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

### RGB LED 1 Pin Mapping

- Leg 1: `5V` -> positive rail
- Leg 2: `Data OUT` -> not used (unless chaining)
- Leg 3: `GND` -> ground rail
- Leg 4: `Data IN` -> `D2`

### RGB LED 2

- `Data IN` -> `D5` (as used in this activity)

## Library Installation

1. Open Arduino IDE.
2. Go to **Library Manager**.
3. Search for **Adafruit NeoPixel**.
4. Install the latest stable version.

## How to Run

1. Build the circuit.
2. Open the Day 6 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Observe LED color output and effects.

## Notes

- Addressable LEDs have directional data flow; verify `Data IN` and `Data OUT` orientation.
- Always share ground between Arduino and LEDs.

## Images

![Day 6 Picture 1](../../image/Day%206,%20picture%201.png)
![Day 6 Picture 2](../../image/Day%206,%20picture%202.png)
