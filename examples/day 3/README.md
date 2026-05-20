## Comparison Notes

# Day 3 – Arduino vs Raspberry Pi Pico: Project Comparisons

This file compares how the same Day 3 button activities are implemented on the **Raspberry Pi Pico** (MicroPython) and the **Arduino MKR Zero** (C++/Arduino language), covering pin setup, input handling, if statements, loops, variables, and code structure.

---

## Hardware Differences

| Feature                  | Raspberry Pi Pico              | Arduino MKR Zero               |
|--------------------------|-------------------------------|--------------------------------|
| Language                 | MicroPython                   | Arduino C++ (Wiring)           |
| Red button pin           | GPIO2 (physical pin 4)        | Digital pin 2                  |
| Green button pin         | GPIO3 (physical pin 5)        | Digital pin 3                  |
| LED pin                  | GPIO14                        | Digital pin 14                 |
| 3.3V source              | 3V3 OUT (physical pin 36)     | 3.3V header                    |
| Pull-down resistors      | Software (`Pin.PULL_DOWN`)    | Software (`INPUT_PULLDOWN`)    |
| IDE / Editor             | Thonny                        | Arduino IDE                    |

---

## Activity 1: Basic Button Usage

### Raspberry Pi Pico (MicroPython)

```python
# Imports
from machine import Pin
import time

# Set up button pin as input with pull down
redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)

while True:  # Loop forever

    time.sleep(0.2)  # Short delay (debounce)

    if redbutton.value() == 1:  # If the red button is pressed
        print("Red button pressed")
```

### Arduino MKR Zero (C++)

```cpp
const int redButtonPin = 2;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  Serial.begin(9600);
}

void loop() {
  delay(200);  // Short delay (debounce)

  if (digitalRead(redButtonPin) == HIGH) {
    Serial.println("Red button pressed");
  }
}
```

### Key Differences

| Concept              | MicroPython (Pico)                    | Arduino (C++)                          |
|----------------------|---------------------------------------|----------------------------------------|
| Pin setup as input   | `Pin(2, Pin.IN, Pin.PULL_DOWN)`       | `pinMode(2, INPUT_PULLDOWN)`           |
| Read button state    | `redbutton.value()`                   | `digitalRead(redButtonPin)`            |
| Check if pressed     | `== 1`                                | `== HIGH`                              |
| Debounce delay       | `time.sleep(0.2)` (seconds)           | `delay(200)` (milliseconds)            |
| Print output         | `print("...")`                        | `Serial.println("...")`                |
| Loop structure       | `while True:`                         | `void loop()` — automatic              |

---

## Activity 2: Multiple Button Inputs

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
greenbutton = Pin(3, Pin.IN, Pin.PULL_DOWN)

while True:

    time.sleep(0.2)

    if redbutton.value() == 1:
        print("Red button pressed")

    if greenbutton.value() == 1:
        print("Green button pressed")
```

### Arduino MKR Zero (C++)

```cpp
const int redButtonPin = 2;
const int greenButtonPin = 3;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  Serial.begin(9600);
}

void loop() {
  delay(200);

  if (digitalRead(redButtonPin) == HIGH) {
    Serial.println("Red button pressed");
  }
  if (digitalRead(greenButtonPin) == HIGH) {
    Serial.println("Green button pressed");
  }
}
```

### Key Differences

| Concept               | MicroPython (Pico)              | Arduino (C++)                        |
|-----------------------|---------------------------------|--------------------------------------|
| Adding a second input | New `Pin()` object              | New `pinMode()` call in `setup()`    |
| Checking both buttons | Two separate `if` statements    | Two separate `if` statements         |
| Code block boundary   | Indentation                     | Curly braces `{}`                    |

---

## Activity 3: LED Control with Buttons

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

# Input pins
redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
greenbutton = Pin(3, Pin.IN, Pin.PULL_DOWN)

# Output pins
redled = Pin(14, Pin.OUT)

while True:

    time.sleep(0.2)

    if redbutton.value() == 1:
        print("Light OFF")
        redled.value(0)  # LED off

    if greenbutton.value() == 1:
        print("Light ON")
        redled.value(1)  # LED on
```

### Arduino MKR Zero (C++)

```cpp
const int redButtonPin = 2;
const int greenButtonPin = 3;
const int ledPin = 14;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(200);

  if (digitalRead(redButtonPin) == HIGH) {
    Serial.println("Light OFF");
    digitalWrite(ledPin, LOW);
  }
  if (digitalRead(greenButtonPin) == HIGH) {
    Serial.println("Light ON");
    digitalWrite(ledPin, HIGH);
  }
}
```

### Key Differences

| Concept             | MicroPython (Pico)       | Arduino (C++)                 |
|---------------------|--------------------------|-------------------------------|
| Turn LED off        | `redled.value(0)`        | `digitalWrite(ledPin, LOW)`   |
| Turn LED on         | `redled.value(1)`        | `digitalWrite(ledPin, HIGH)`  |
| Multiple actions in `if` | Add lines below, indented | Add lines inside `{}`     |

---

## Activity 4: Toggling LED with a Button

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
redled = Pin(14, Pin.OUT)

while True:

    time.sleep(0.2)

    if redbutton.value() == 1:
        redled.toggle()  # Flip between on and off
```

### Arduino MKR Zero (C++)

MicroPython has a built-in `.toggle()` method. Arduino has no direct equivalent, so we track the LED state manually with a variable:

```cpp
const int redButtonPin = 2;
const int ledPin = 14;
bool ledState = false;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(200);

  if (digitalRead(redButtonPin) == HIGH) {
    ledState = !ledState;          // Flip the state
    digitalWrite(ledPin, ledState ? HIGH : LOW);
  }
}
```

### Key Differences

| Concept              | MicroPython (Pico)        | Arduino (C++)                              |
|----------------------|---------------------------|--------------------------------------------|
| Toggle pin state     | `pin.toggle()`            | No built-in — manually flip a `bool`       |
| State tracking       | Handled internally        | Requires a `bool` variable                 |
| Conditional value    | Not needed                | Ternary: `ledState ? HIGH : LOW`           |

> **Note:** The Pico's `.toggle()` method is a MicroPython convenience not present in Arduino. Arduino requires you to track the LED state yourself using a boolean variable and flip it with `!ledState`.

---

## Activity 5: Counting with Buttons

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
greenbutton = Pin(3, Pin.IN, Pin.PULL_DOWN)

count = 0  # Integer variable, starts at zero

while True:

    time.sleep(0.2)

    if redbutton.value() == 1:
        count = count - 1  # Decrease
        print(count)

    if greenbutton.value() == 1:
        count = count + 1  # Increase
        print(count)
```

### Arduino MKR Zero (C++)

```cpp
const int redButtonPin = 2;
const int greenButtonPin = 3;
int count = 0;  // Integer variable, starts at zero

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  Serial.begin(9600);
}

void loop() {
  delay(200);

  if (digitalRead(redButtonPin) == HIGH) {
    count = count - 1;  // Decrease
    Serial.println(count);
  }
  if (digitalRead(greenButtonPin) == HIGH) {
    count = count + 1;  // Increase
    Serial.println(count);
  }
}
```

### Key Differences

| Concept               | MicroPython (Pico)     | Arduino (C++)               |
|-----------------------|------------------------|-----------------------------|
| Declare variable      | `count = 0`            | `int count = 0;`            |
| Type declaration      | Not required (dynamic) | Required — must specify `int` |
| Decrease by 1         | `count = count - 1`    | `count = count - 1;` or `count--` |
| Increase by 1         | `count = count + 1`    | `count = count + 1;` or `count++` |
| Print variable        | `print(count)`         | `Serial.println(count)`     |
| Line endings          | None required          | Semicolon `;` required      |

---

## Activity 6: Counting with LED Flash Feedback

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin
import time

redbutton = Pin(2, Pin.IN, Pin.PULL_DOWN)
greenbutton = Pin(3, Pin.IN, Pin.PULL_DOWN)
redled = Pin(14, Pin.OUT)

count = 0

while True:

    time.sleep(0.2)

    redled.value(0)  # LED off at start of each loop cycle

    if redbutton.value() == 1:
        count = count - 1
        redled.value(1)  # LED flash on button press
        print(count)

    if greenbutton.value() == 1:
        count = count + 1
        redled.value(1)  # LED flash on button press
        print(count)
```

### Arduino MKR Zero (C++)

```cpp
const int redButtonPin = 2;
const int greenButtonPin = 3;
const int ledPin = 14;
int count = 0;

void setup() {
  pinMode(redButtonPin, INPUT_PULLDOWN);
  pinMode(greenButtonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(200);

  digitalWrite(ledPin, LOW);  // LED off at start of each loop cycle

  if (digitalRead(redButtonPin) == HIGH) {
    count = count - 1;
    digitalWrite(ledPin, HIGH);  // LED flash on button press
    Serial.println(count);
  }
  if (digitalRead(greenButtonPin) == HIGH) {
    count = count + 1;
    digitalWrite(ledPin, HIGH);  // LED flash on button press
    Serial.println(count);
  }
}
```

### Key Differences

| Concept              | MicroPython (Pico)         | Arduino (C++)                    |
|----------------------|----------------------------|----------------------------------|
| LED off each cycle   | `redled.value(0)`          | `digitalWrite(ledPin, LOW)`      |
| LED on at press      | `redled.value(1)`          | `digitalWrite(ledPin, HIGH)`     |
| Flash mechanism      | Off at loop top, on in `if`| Same pattern — off then on in `if`|

---

## General Language Comparison: Day 3 Concepts

| Concept                  | MicroPython (Pico)                      | Arduino (C++)                             |
|--------------------------|-----------------------------------------|-------------------------------------------|
| Set pin as input         | `Pin(n, Pin.IN, Pin.PULL_DOWN)`         | `pinMode(n, INPUT_PULLDOWN)`              |
| Read digital input       | `pin.value()`                           | `digitalRead(pin)`                        |
| Check if HIGH            | `== 1`                                  | `== HIGH`                                 |
| If statement             | `if condition:`                         | `if (condition) {}`                       |
| Toggle output pin        | `pin.toggle()`                          | Manual: `state = !state; digitalWrite()`  |
| Integer variable         | `count = 0`                             | `int count = 0;`                          |
| Increment/decrement      | `count = count + 1`                     | `count++` or `count = count + 1`          |
| Debounce delay           | `time.sleep(0.2)` (seconds)             | `delay(200)` (milliseconds)               |
| Infinite loop            | `while True:`                           | `void loop()` — automatic                 |
| Code blocks              | Indentation                             | Curly braces `{}`                         |
| Comments                 | `# comment`                             | `// comment`                              |
| Print to console         | `print(value)`                          | `Serial.println(value)`                   |
| Variable types           | Dynamic — no type needed                | Static — must declare type e.g. `int`     |

# Day 3: Incredible Inputs

This activity uses two pushbuttons and one LED with an Arduino MKR Zero. Button presses are used as digital inputs to control LED behavior and display messages through the serial monitor.

## Overview

The project demonstrates:

- Reading digital input from pushbuttons
- Controlling an LED based on button state
- Printing input feedback in code (when implemented in the sketch)

## Components

- Arduino MKR Zero
- Breadboard
- 2 pushbuttons (for example: red and green)
- 1 LED
- 1 resistor (220 ohm to 330 ohm)
- Jumper wires

## Wiring

### Power Rails

- Arduino `3.3V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

### LED

- Anode (long leg) to `D14`
- Cathode (short leg) to `GND` through a resistor

### Pushbuttons

- Both buttons: one side to `3.3V`
- Right button output side to `D2`
- Left button output side to `D3`

## How to Run

1. Build the circuit as listed above.
2. Open the Day 3 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Open Serial Monitor (if your sketch prints messages) and test the buttons.

## Notes

- Verify button orientation before wiring.
- Use proper resistor values to protect the LED.

## Images

![Day 3 Setup](../../image/Day%203.png)
