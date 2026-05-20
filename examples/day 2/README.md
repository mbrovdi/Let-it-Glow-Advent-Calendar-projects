## Comparison Notes

# Day 2 – Arduino vs Raspberry Pi Pico: Project Comparisons

This file compares how the same Day 2 LED activities are implemented on the **Raspberry Pi Pico** (MicroPython) and the **Arduino MKR Zero** (C++/Arduino language), covering pin setup, commands, loops, and code structure.

---

## Hardware Differences

| Feature              | Raspberry Pi Pico              | Arduino MKR Zero               |
|----------------------|-------------------------------|--------------------------------|
| Language             | MicroPython                   | Arduino C++ (Wiring)           |
| LED pin used         | GPIO14 (physical pin 19)      | Digital pin 6                  |
| Onboard LED pin      | GPIO25                        | LED_BUILTIN                    |
| GND pin used         | Physical pin 18               | GND header                     |
| IDE / Editor         | Thonny                        | Arduino IDE                    |

---

## Activity 1: Light the LED

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin

blockLED = Pin(14, Pin.OUT)

blockLED.value(1)

print("Block LED on!")
```

### Arduino MKR Zero (C++)

```cpp
int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
  Serial.println("Block LED on!");
}

void loop() {
  // Nothing needed here to just hold the LED on
}
```

### Key Differences

| Concept           | MicroPython (Pico)             | Arduino (C++)                       |
|-------------------|-------------------------------|-------------------------------------|
| Import/include    | `from machine import Pin`     | No import needed for basic I/O      |
| Pin setup         | `Pin(14, Pin.OUT)`            | `pinMode(ledPin, OUTPUT)`           |
| Turn LED on       | `blockLED.value(1)`           | `digitalWrite(ledPin, HIGH)`        |
| Turn LED off      | `blockLED.value(0)`           | `digitalWrite(ledPin, LOW)`         |
| Print to console  | `print("...")`                | `Serial.println("...")`             |
| Serial init       | Not required                  | `Serial.begin(9600)` in `setup()`   |

---

## Activity 2: Light Both LEDs

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin

green = Pin(25, Pin.OUT)   # Onboard LED
red = Pin(14, Pin.OUT)     # Blocky LED

green.value(1)
red.value(1)

print("Both LEDs ON!")
```

### Arduino MKR Zero (C++)

```cpp
int greenPin = LED_BUILTIN;
int redPin = 6;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, HIGH);
  Serial.begin(9600);
  Serial.println("Both LEDs ON!");
}

void loop() {}
```

### Key Differences

| Concept              | MicroPython (Pico)        | Arduino (C++)                    |
|----------------------|--------------------------|----------------------------------|
| Multiple pins        | One `Pin()` object each  | One `pinMode()` call each        |
| Naming pins          | Variable assigned to `Pin()` | Integer variable for pin number |
| Onboard LED          | GPIO25                   | `LED_BUILTIN` constant           |

---

## Activity 3: Flashing LED (Basic)

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

red = Pin(14, Pin.OUT)

red.value(1)
time.sleep(1)

red.value(0)
time.sleep(1)

red.value(1)
time.sleep(1)

red.value(0)
time.sleep(1)
```

### Arduino MKR Zero (C++)

```cpp
int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);

  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

### Key Differences

| Concept         | MicroPython (Pico)    | Arduino (C++)       |
|-----------------|-----------------------|---------------------|
| Delay/sleep     | `time.sleep(1)`       | `delay(1000)`       |
| Delay units     | Seconds               | Milliseconds        |
| Time module     | `import time`         | Built-in, no import |

> **Note:** On the Pico, `time.sleep(1)` waits 1 second. On Arduino, `delay(1000)` also waits 1 second — but the unit is milliseconds, so 1000ms = 1s.

---

## Activity 4: Flashing LED (Using Loops)

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

# Pin setup
red = Pin(14, Pin.OUT)

# Loop forever
while True:
    red.value(1)   # LED on
    time.sleep(1)

    red.value(0)   # LED off
    time.sleep(1)
```

### Arduino MKR Zero (C++)

```cpp
// Pin setup
int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);
}

// loop() runs forever automatically
void loop() {
  digitalWrite(ledPin, HIGH);  // LED on
  delay(1000);

  digitalWrite(ledPin, LOW);   // LED off
  delay(1000);
}
```

### Key Differences

| Concept               | MicroPython (Pico)              | Arduino (C++)                         |
|-----------------------|---------------------------------|---------------------------------------|
| Infinite loop         | `while True:`                   | `void loop()` — runs forever by design |
| Loop structure        | Explicit, written by you        | Implicit — `loop()` is called automatically |
| Code indentation      | Required — defines code blocks  | Not required — braces `{}` define blocks |
| Comments              | `# comment`                     | `// comment`                          |
| Entry point           | Script runs top-to-bottom       | `setup()` once, then `loop()` forever  |

---

## General Language Comparison

| Concept              | MicroPython (Pico)               | Arduino C++                          |
|----------------------|----------------------------------|--------------------------------------|
| Code structure       | Script-style, runs top-to-bottom | Must have `setup()` and `loop()`     |
| Variable types       | Dynamic (no type declaration)    | Static — must declare type e.g. `int`|
| Indentation          | Mandatory (defines blocks)       | Optional (blocks use `{}`)           |
| Comments             | `# comment`                      | `// comment` or `/* block */`        |
| Printing output      | `print("text")`                  | `Serial.println("text")`             |
| Delay                | `time.sleep(seconds)`            | `delay(milliseconds)`                |
| Pin as output        | `Pin(14, Pin.OUT)`               | `pinMode(14, OUTPUT)`                |
| Set pin HIGH         | `pin.value(1)` or `pin.on()`     | `digitalWrite(14, HIGH)`             |
| Set pin LOW          | `pin.value(0)` or `pin.off()`    | `digitalWrite(14, LOW)`              |
| Import libraries     | `import` / `from x import y`     | `#include <Library.h>`               |

# Day 2: Lighting LEDs

This activity introduces basic LED control with an Arduino MKR Zero. The sketch turns an LED on and off in a repeating loop so you can observe how digital output and delay timing affect behavior.

## Overview

In this project, you will:

- Build a simple LED circuit with a current-limiting resistor
- Upload a blinking sketch to the Arduino MKR Zero
- Experiment with delay values to change blink speed

## Components

- Arduino MKR Zero
- Breadboard
- 1 LED
- 220 ohm resistor
- Jumper wires
- USB cable

## Wiring

- LED anode (long leg) to digital pin `D6` through the 220 ohm resistor
- LED cathode (short leg) to `GND`

## How to Run

1. Build the circuit on your breadboard.
2. Open the Day 2 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Observe the LED blink pattern.

## Observations

- Larger delay values produce slower blinking
- Smaller delay values produce faster blinking

## Learning Outcome

This activity demonstrates core Arduino concepts: digital output, timing with `delay()`, and safe LED wiring with a resistor.

## Images

![Day 2 Setup](../../image/Day%202.png)
