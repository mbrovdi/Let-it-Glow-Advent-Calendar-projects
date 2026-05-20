## Comparison Notes

# Day 4 – Arduino vs Raspberry Pi Pico: Project Comparisons

This file compares how the same Day 4 bar graph display activities are implemented on the **Raspberry Pi Pico** (MicroPython) and the **Arduino MKR Zero** (C++/Arduino language), covering arrays/lists, for loops, random numbers, nested if statements, and the else/pass keywords.

---

## Hardware Differences

| Feature                  | Raspberry Pi Pico              | Arduino MKR Zero               |
|--------------------------|-------------------------------|--------------------------------|
| Language                 | MicroPython                   | Arduino C++ (Wiring)           |
| Segment pins used        | GPIO 13, 12, 11, 10, 9        | Digital pins 13, 12, 11, 10, 9 |
| Red button pin           | GPIO2                         | Digital pin 2                  |
| Green button pin         | GPIO3                         | Digital pin 3                  |
| GND pin                  | Physical pin 18               | GND header                     |
| Pull-down resistors      | Software (`Pin.PULL_DOWN`)    | Software (`INPUT_PULLDOWN`)    |
| IDE / Editor             | Thonny                        | Arduino IDE                    |

---

## Activity 1: Segment Test

### Raspberry Pi Pico (MicroPython)

from machine import Pin
import time

seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

seg1.value(1)
time.sleep(1)
seg2.value(1)
time.sleep(1)
seg3.value(1)
time.sleep(1)
seg4.value(1)
time.sleep(1)
seg5.value(1)
time.sleep(1)

seg1.value(0)
seg2.value(0)
seg3.value(0)
seg4.value(0)
seg5.value(0)

### Arduino MKR Zero (C++)

const int segments[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], HIGH);
    delay(500);
    digitalWrite(segments[i], LOW);
    delay(200);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], LOW);
  }
  delay(1000);
}

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Storing multiple pins    | Individual Pin() objects        | Integer array: const int segments[5]   |
| Pin setup                | Pin(n, Pin.OUT) per pin         | pinMode() inside a for loop            |
| Turn segment on          | seg1.value(1)                   | digitalWrite(segments[i], HIGH)        |
| Turn segment off         | seg1.value(0)                   | digitalWrite(segments[i], LOW)         |
| Delay                    | time.sleep(1) — seconds         | delay(1000) — milliseconds             |

---

## Activity 2: Easier Segment Control with Lists / Arrays

### Raspberry Pi Pico (MicroPython)

from machine import Pin
import time

seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

segments = [seg1, seg2, seg3, seg4, seg5]

for led in segments:
    led.value(1)
    time.sleep(1)

for led in segments:
    led.value(0)

### Arduino MKR Zero (C++)

const int segments[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], HIGH);
    delay(1000);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], LOW);
  }
}

### Key Differences

| Concept                  | MicroPython (Pico)                   | Arduino (C++)                              |
|--------------------------|--------------------------------------|--------------------------------------------|
| Collection of pins       | List of Pin objects: [seg1, ...]     | Integer array of pin numbers: {13, ...}    |
| For loop over collection | for led in segments:                 | for (int i = 0; i < 5; i++)               |
| Loop variable            | led — the actual Pin object          | i — an index number                        |
| Access item in loop      | led.value(1) directly                | segments[i] to get pin, then digitalWrite()|
| Loop syntax              | No brackets, uses indentation        | Brackets and braces required               |

---

## Activity 3: LED Scanner

### Raspberry Pi Pico (MicroPython)

from machine import Pin
import time

seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

segments = [seg1, seg2, seg3, seg4, seg5]

while True:
    for led in segments:
        led.value(1)
        time.sleep(0.08)
        led.value(0)
    for led in reversed(segments):
        led.value(1)
        time.sleep(0.08)
        led.value(0)

### Arduino MKR Zero (C++)

const int segments[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(segments[i], HIGH);
    delay(80);
    digitalWrite(segments[i], LOW);
  }
  for (int i = 4; i >= 0; i--) {
    digitalWrite(segments[i], HIGH);
    delay(80);
    digitalWrite(segments[i], LOW);
  }
}

### Key Differences

| Concept                  | MicroPython (Pico)               | Arduino (C++)                          |
|--------------------------|----------------------------------|----------------------------------------|
| Reverse loop             | for led in reversed(segments):   | for (int i = 4; i >= 0; i--)          |
| Reverse syntax           | Built-in reversed() function     | Manual: start at 4, count down with i--|
| Infinite loop            | while True:                      | void loop() — automatic                |

---

## Activity 4: Random LEDs

### Raspberry Pi Pico (MicroPython)

from machine import Pin
import time
import random

seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

segments = [seg1, seg2, seg3, seg4, seg5]

while True:
    r = random.randint(0, 4)
    segments[r].value(1)
    time.sleep(0.1)
    segments[r].value(0)

### Arduino MKR Zero (C++)

const int segments[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
  randomSeed(analogRead(0));
}

void loop() {
  int r = random(0, 5);
  digitalWrite(segments[r], HIGH);
  delay(100);
  digitalWrite(segments[r], LOW);
}

### Key Differences

| Concept                  | MicroPython (Pico)                       | Arduino (C++)                               |
|--------------------------|------------------------------------------|---------------------------------------------|
| Import random module     | import random                            | Built-in, no import needed                  |
| Generate random integer  | random.randint(0, 4) — both ends inclusive| random(0, 5) — upper end exclusive         |
| Seed the RNG             | Not required                              | randomSeed(analogRead(0)) in setup()        |
| Access list by index     | segments[r].value(1)                     | digitalWrite(segments[r], HIGH)             |

---

## Activity 5: Button Press Counter with LEDs

### Raspberry Pi Pico (MicroPython)

from machine import Pin
import time

redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
greenbutton = Pin(3, Pin.IN, Pin.PULL_DOWN)

seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

segments = [seg1, seg2, seg3, seg4, seg5]
count = -1

for led in segments:
    led.value(0)

while True:
    time.sleep(0.01)
    if redbutton.value() == 1:
        if count == 4:
            pass
        else:
            count = count + 1
            segments[count].value(1)
            time.sleep(0.2)
    if greenbutton.value() == 1:
        if count == -1:
            pass
        else:
            segments[count].value(0)
            time.sleep(0.2)
            count = count - 1

### Arduino MKR Zero (C++)

const int redButtonPin = 2;
const int greenButtonPin = 3;
const int segments[5] = {13, 12, 11, 10, 9};
int count = -1;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  for (int i = 0; i < 5; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
}

void loop() {
  delay(10);
  if (digitalRead(redButtonPin) == HIGH) {
    if (count < 4) {
      count++;
      digitalWrite(segments[count], HIGH);
      delay(200);
    }
  }
  if (digitalRead(greenButtonPin) == HIGH) {
    if (count >= 0) {
      digitalWrite(segments[count], LOW);
      delay(200);
      count--;
    }
  }
}

### Key Differences

| Concept                     | MicroPython (Pico)                   | Arduino (C++)                          |
|-----------------------------|--------------------------------------|----------------------------------------|
| Nested if statement         | Indented if inside outer if          | if inside if {} braces                 |
| Do nothing in a branch      | pass                                 | Invert condition — no placeholder needed|
| Boundary check (upper)      | if count == 4: pass                  | if (count < 4) — only act if not at max|
| Boundary check (lower)      | if count == -1: pass                 | if (count >= 0) — only act if not at min|
| Increment shorthand         | count = count + 1                    | count++                                |
| Decrement shorthand         | count = count - 1                    | count--                                |
| Access list/array by index  | segments[count].value(1)             | digitalWrite(segments[count], HIGH)    |

---

## General Language Comparison: Day 4 Concepts

| Concept                    | MicroPython (Pico)                        | Arduino (C++)                                   |
|----------------------------|-------------------------------------------|-------------------------------------------------|
| List / array of pins       | segments = [seg1, seg2, ...]              | const int segments[5] = {13, 12, ...}           |
| For loop over collection   | for led in segments:                      | for (int i = 0; i < 5; i++)                     |
| Reverse a loop             | for led in reversed(segments):            | for (int i = 4; i >= 0; i--)                    |
| Access item by index       | segments[r] — returns the Pin object      | segments[r] — returns the pin number            |
| Random number              | random.randint(0, 4) — both inclusive     | random(0, 5) — upper exclusive                  |
| Seed random number gen     | Not required                              | randomSeed(analogRead(0)) in setup()            |
| Nested if                  | Indented if inside an if                  | if inside if {} braces                          |
| Do nothing in a branch     | pass                                      | Invert condition — no placeholder needed        |
| Increment variable         | count = count + 1                         | count++                                         |
| Decrement variable         | count = count - 1                         | count--                                         |
| Delay                      | time.sleep(seconds)                       | delay(milliseconds)                             |

# Day 4: Bar Graph Display with Arduino MKR Zero

This project controls a 5-segment LED bar graph using an Arduino MKR Zero and two pushbuttons. A resistor network is used to simplify wiring for the LED segments.

## Overview

The sketch includes:

- A segment test sequence to verify each LED segment
- Interactive button control for changing the display state

## Components

- Arduino MKR Zero
- Breadboard
- 5-segment LED bar graph display
- 5-pin resistor network (common GND pin marked with a dot)
- 2 pushbuttons
- Jumper wires

## Wiring

### LED Bar Graph

- Anodes (long legs): connect to Arduino pins `D13`, `D12`, `D11`, `D10`, `D9` (one segment per pin)
- Cathodes (short legs): connect each to a separate resistor-network pin (excluding the common dot pin)

### Resistor Network

- Common dot pin: connect to `GND` rail

### Pushbuttons

- Red button: one side to `3.3V`, the other side to `D2`
- Green button: one side to `3.3V`, the other side to `D3`

### Power Rails

- Arduino `3.3V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

## How to Run

1. Build the circuit as described above.
2. Open the Day 4 sketch in the Arduino IDE.
3. Select the correct board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Press the buttons to interact with the bar graph.

## Notes

- Confirm the bar graph pin orientation before wiring.
- Use the resistor network's marked common pin correctly to avoid short circuits.

## Images

![Day 4 Picture 1](../../image/Day%204,%20picture%201.png)
![Day 4 Picture 2](../../image/Day%204,%20picture%202.png)
