## Comparison Notes

# Day 5 – Arduino vs Raspberry Pi Pico: DIP Switch Comparisons

This file compares how to use a 5-way DIP switch with a bar graph display on the **Raspberry Pi Pico** (MicroPython) and the **Arduino MKR Zero** (C++/Arduino language). It covers wiring, reading switch states, using if/else, and combining switch logic with LEDs and functions.

---

## Hardware Setup

| Feature                  | Raspberry Pi Pico              | Arduino MKR Zero               |
|--------------------------|-------------------------------|--------------------------------|
| Language                 | MicroPython                   | Arduino C++ (Wiring)           |
| DIP switch pins used     | GPIO 6, 5, 4, 3, 2            | Digital pins 6, 5, 4, 3, 2     |
| Bar graph pins           | GPIO 13, 12, 11, 10, 9        | Digital pins 13, 12, 11, 10, 9 |
| Pull-down resistors      | Software (`Pin.PULL_DOWN`)    | Software (`INPUT_PULLDOWN`)    |
| 3.3V connection          | Top DIP legs to 3.3V rail     | Top DIP legs to 3.3V rail      |
| IDE / Editor             | Thonny                        | Arduino IDE                    |

---

## Activity 1: DIP Switch 'ON' Test

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

dip1 = Pin(6, Pin.IN, Pin.PULL_DOWN)
dip2 = Pin(5, Pin.IN, Pin.PULL_DOWN)
dip3 = Pin(4, Pin.IN, Pin.PULL_DOWN)
dip4 = Pin(3, Pin.IN, Pin.PULL_DOWN)
dip5 = Pin(2, Pin.IN, Pin.PULL_DOWN)

while True:
    if dip1.value() == 1:
        print("Switch 1: ON")
    if dip2.value() == 1:
        print("Switch 2: ON")
    if dip3.value() == 1:
        print("Switch 3: ON")
    if dip4.value() == 1:
        print("Switch 4: ON")
    if dip5.value() == 1:
        print("Switch 5: ON")
    print("-------------")
    time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
const int dips[5] = {6, 5, 4, 3, 2};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(dips[i], INPUT_PULLDOWN);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(dips[i]) == HIGH) {
      Serial.print("Switch ");
      Serial.print(i+1);
      Serial.println(": ON");
    }
  }
  Serial.println("-------------");
  delay(5000);
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Pin setup                | Pin(n, Pin.IN, Pin.PULL_DOWN)   | pinMode(pin, INPUT_PULLDOWN)           |
| Read switch state        | dip1.value()                    | digitalRead(dips[i])                   |
| Print output             | print()                         | Serial.print()/Serial.println()        |
| Delay                    | time.sleep(5)                   | delay(5000)                            |

---

## Activity 2: DIP Switch 'ON or OFF' Test (if/else)

### MicroPython

```python
# ...existing code...
while True:
    if dip1.value() == 1:
        print("Switch 1: ON")
    else:
        print("Switch 1: OFF")
    # Repeat for dip2-dip5...
    print("-------------")
    time.sleep(5)
```

### Arduino

```cpp
// ...existing code...
void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(dips[i]) == HIGH) {
      Serial.print("Switch ");
      Serial.print(i+1);
      Serial.println(": ON");
    } else {
      Serial.print("Switch ");
      Serial.print(i+1);
      Serial.println(": OFF");
    }
  }
  Serial.println("-------------");
  delay(5000);
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| if/else syntax           | else:                           | else { ... }                           |
| Print ON/OFF             | print("Switch X: ON/OFF")        | Serial.print/Serial.println            |

---

## Activity 3: DIP Switch with LEDs

### MicroPython

```python
# ...existing code...
seg1 = Pin(13, Pin.OUT)
seg2 = Pin(12, Pin.OUT)
seg3 = Pin(11, Pin.OUT)
seg4 = Pin(10, Pin.OUT)
seg5 = Pin(9, Pin.OUT)

while True:
    if dip1.value() == 1:
        seg1.value(1)
    else:
        seg1.value(0)
    # Repeat for dip2/seg2 ... dip5/seg5
    time.sleep(0.5)
```

### Arduino

```cpp
const int segs[5] = {13, 12, 11, 10, 9};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(dips[i], INPUT_PULLDOWN);
    pinMode(segs[i], OUTPUT);
    digitalWrite(segs[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(dips[i]) == HIGH) {
      digitalWrite(segs[i], HIGH);
    } else {
      digitalWrite(segs[i], LOW);
    }
  }
  delay(500);
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Set LED state            | seg1.value(1/0)                 | digitalWrite(segs[i], HIGH/LOW)        |
| Loop for all switches    | Manual or for loop              | for (int i = 0; i < 5; i++)            |

---

## Activity 4: Program Selection with Functions

### MicroPython

```python
def program1():
    for led in segments:
        led.value(1)
        time.sleep(0.1)
        led.value(0)

def program2():
    for led in reversed(segments):
        led.value(1)
        time.sleep(0.1)
        led.value(0)

while True:
    if dip1.value() == 1:
        print("Program #1 running...")
        program1()
    elif dip2.value() == 1:
        print("Program #2 running...")
        program2()
```

### Arduino

```cpp
void program1() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(segs[i], HIGH);
    delay(100);
    digitalWrite(segs[i], LOW);
  }
}

void program2() {
  for (int i = 4; i >= 0; i--) {
    digitalWrite(segs[i], HIGH);
    delay(100);
    digitalWrite(segs[i], LOW);
  }
}

void loop() {
  if (digitalRead(dips[0]) == HIGH) {
    Serial.println("Program #1 running...");
    program1();
  } else if (digitalRead(dips[1]) == HIGH) {
    Serial.println("Program #2 running...");
    program2();
  }
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Define function          | def program1():                 | void program1()                        |
| Call function            | program1()                       | program1()                             |
| elif                     | elif                            | else if                                |

---

## Activity 5: Multiple Switches (and/or)

### MicroPython (using 'and')

```python
if dip1.value() == 1 and dip2.value() == 1:
    program1()
elif dip3.value() == 1 and dip4.value() == 1:
    program2()
```

### Arduino (using '&&')

```cpp
if (digitalRead(dips[0]) == HIGH && digitalRead(dips[1]) == HIGH) {
  program1();
} else if (digitalRead(dips[2]) == HIGH && digitalRead(dips[3]) == HIGH) {
  program2();
}
```

### MicroPython (using 'or')

```python
if dip1.value() == 1 or dip2.value() == 1:
    program1()
elif dip3.value() == 1 or dip4.value() == 1:
    program2()
```

### Arduino (using '||')

```cpp
if (digitalRead(dips[0]) == HIGH || digitalRead(dips[1]) == HIGH) {
  program1();
} else if (digitalRead(dips[2]) == HIGH || digitalRead(dips[3]) == HIGH) {
  program2();
}
```

### Key Differences

| Concept                  | MicroPython (Pico)              | Arduino (C++)                          |
|--------------------------|---------------------------------|----------------------------------------|
| Logical AND              | and                             | &&                                     |
| Logical OR               | or                              | ||                                     |

---

## General Language Comparison: Day 5 Concepts

| Concept                    | MicroPython (Pico)                        | Arduino (C++)                                   |
|----------------------------|-------------------------------------------|-------------------------------------------------|
| DIP switch input           | Pin(n, Pin.IN, Pin.PULL_DOWN)             | pinMode(pin, INPUT_PULLDOWN)                    |
| Read input                 | dip1.value()                              | digitalRead(dips[i])                            |
| LED output                 | seg1.value(1/0)                           | digitalWrite(segs[i], HIGH/LOW)                 |
| if/else/elif               | if ... else ... elif                      | if (...) { ... } else if (...) { ... }          |
| Function definition        | def program1():                           | void program1()                                 |
| Logical AND/OR             | and / or                                  | && / ||                                         |
| Delay                      | time.sleep(seconds)                       | delay(milliseconds)                             |
| Print output               | print()                                   | Serial.print()/Serial.println()                 |

---

This comparison should help you translate DIP switch and bar graph activities between MicroPython and Arduino C++ for Day 5. Adjust pin numbers as needed for your hardware.

# Day 5: Switch the DIP

This project uses a 5-position DIP switch as digital input for the Arduino MKR Zero and maps each switch to one segment of a 5-segment LED bar graph.

## Overview

The goal is simple:

- Read five DIP switch inputs
- Turn on the matching LED bar graph segment for each active switch

## Components

- Arduino MKR Zero
- Breadboard
- 5-position DIP switch
- 5-segment LED bar graph display
- 5-pin resistor network (common GND pin marked with a dot)
- Jumper wires

## Wiring

### Power Rails

- Arduino `3.3V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

### DIP Switch Connections

For each DIP switch position:

- One side to `3.3V` rail
- Other side to an Arduino input pin

Pin mapping:

- Switch 1 -> `D6`
- Switch 2 -> `D5`
- Switch 3 -> `D4`
- Switch 4 -> `D3`
- Switch 5 -> `D2`

### Bar Graph Connections

- Segment 1 anode -> `D13`
- Segment 2 anode -> `D12`
- Segment 3 anode -> `D11`
- Segment 4 anode -> `D10`
- Segment 5 anode -> `D9`

Each segment cathode connects to one resistor-network pin (non-dot pins).
Resistor-network common dot pin connects to `GND`.

## How to Run

1. Build the circuit using the mapping above.
2. Open the Day 5 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Toggle each DIP switch and verify the matching bar graph segment lights up.

## Notes

- Confirm bar graph and DIP switch orientation before wiring.
- Keep grounds common between all components.

## Images

![Day 5 Picture 1](../../image/Day%205,%20picture%201.png)
![Day 5 Picture 2](../../image/Day%205,%20picture%202.png)
![Day 5 Picture 3](../../image/Day%205,%20picture%203.png)

