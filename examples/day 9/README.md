## Comparison Notes

# Day 9 - Arduino vs Raspberry Pi Pico: DHT20/AHT20 Sensor and LED Ring

This file compares Day 9 activities using an I2C temperature/humidity sensor with an RGB ring on Raspberry Pi Pico (MicroPython) and Arduino MKR Zero (C++/Arduino language).

---

## Hardware Setup

| Feature | Raspberry Pi Pico | Arduino MKR Zero |
|---|---|---|
| Sensor type | DHT20/AHT20 (I2C) | DHT20/AHT20 (I2C) |
| I2C SDA | GPIO14 (physical pin 19) | SDA pin |
| I2C SCL | GPIO15 (physical pin 20) | SCL pin |
| Sensor power | 3.3V | 3.3V |
| Sensor ground | GND | GND |
| Ring data pin | GPIO2 | D2 |
| Ring power | 5V (VBUS) | 5V |
| Ring LEDs | 12 | 12 |

---

## Library Setup

### Pico (MicroPython)

1. Save the external library as `dht20.py` on the Pico.
2. Import it with `from dht20 import DHT20`.

### Arduino (C++)

Install libraries in Arduino IDE:

1. `Adafruit NeoPixel`
2. `Adafruit AHTX0` (works with AHT20/DHT20 class devices on many breakout boards)

---

## Activity 1: Simple Sensor Reading Test

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin, I2C
import time
from dht20 import DHT20

i2c1_sda = Pin(14)
i2c1_scl = Pin(15)
i2c1 = I2C(1, sda=i2c1_sda, scl=i2c1_scl)

dht20 = DHT20(0x38, i2c1)

while True:
    measurements = dht20.measurements

    print(measurements['t'])
    print(measurements['t_adc'])
    print(measurements['rh'])
    print(measurements['rh_adc'])
    print(measurements['crc_ok'])

    time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!aht.begin()) {
    Serial.println("Sensor not found");
    while (1) {
    }
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.println(temp.temperature);      // t
  Serial.println(humidity.relative_humidity); // rh
  Serial.println("----");

  delay(5000);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| I2C setup | `I2C(1, sda=Pin(14), scl=Pin(15))` | `Wire.begin()` |
| Sensor data structure | Dictionary keys (`'t'`, `'rh'`, etc.) | Event structs (`temp.temperature`, `humidity.relative_humidity`) |
| Extra raw/CRC fields | Available in provided library | Depends on chosen Arduino library |

---

## Activity 2: Readable Readings (Formatted Output)

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin, I2C
import time
from dht20 import DHT20

i2c1 = I2C(1, sda=Pin(14), scl=Pin(15))
dht20 = DHT20(0x38, i2c1)

while True:
    measurements = dht20.measurements

    print("-- Environment ---------")
    print(f"Temperature:      {round(measurements['t'], 1)}C")
    print(f"Humidity:         {round(measurements['rh'], 1)}%")
    print("------------------------")
    print(" ")

    time.sleep(5)
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!aht.begin()) {
    Serial.println("Sensor not found");
    while (1) {
    }
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.println("-- Environment ---------");
  Serial.print("Temperature:      ");
  Serial.print(temp.temperature, 1);
  Serial.println("C");
  Serial.print("Humidity:         ");
  Serial.print(humidity.relative_humidity, 1);
  Serial.println("%");
  Serial.println("------------------------");
  Serial.println();

  delay(5000);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| String formatting | f-strings | `Serial.print` chain |
| Rounding/precision | `round(value, 1)` | `Serial.print(value, 1)` |

---

## Activity 3: Temperature Indication Ring

### Raspberry Pi Pico (MicroPython)

```python
from machine import Pin, I2C
import time
from dht20 import DHT20
from neopixel import NeoPixel

i2c1 = I2C(1, sda=Pin(14), scl=Pin(15))
dht20 = DHT20(0x38, i2c1)
ring = NeoPixel(Pin(2), 12)

LEDdict = {
  14: 0,
  15: 1,
  16: 2,
  17: 3,
  18: 4,
  19: 5,
  20: 6,
  21: 7,
  22: 8,
  23: 9,
  24: 10,
  25: 11,
}

while True:
    measurements = dht20.measurements
    temperature = round(measurements['t'])

    if temperature not in LEDdict:
        print("*** Out of temperature range ***")
    else:
        LEDindex = LEDdict[temperature]
        print("Temperature:", temperature)
        print("LED index:  ", LEDindex)
        print("----------------")

        ring.fill((0, 0, 0))
        ring.write()
        ring[LEDindex] = (10, 0, 0)
        ring.write()

    time.sleep(2)
```

### Arduino MKR Zero (C++)

```cpp
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_NeoPixel.h>

Adafruit_AHTX0 aht;
Adafruit_NeoPixel ring(12, 2, NEO_RGB + NEO_KHZ800);

const int minTemp = 14;
const int maxTemp = 25;
const int ledIndexForTemp[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  ring.begin();
  ring.clear();
  ring.show();

  if (!aht.begin()) {
    Serial.println("Sensor not found");
    while (1) {
    }
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  int temperature = (int)round(temp.temperature);

  if (temperature < minTemp || temperature > maxTemp) {
    Serial.println("*** Out of temperature range ***");
  } else {
    int LEDindex = ledIndexForTemp[temperature - minTemp];

    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("LED index:   ");
    Serial.println(LEDindex);
    Serial.println("----------------");

    ring.clear();
    ring.setPixelColor(LEDindex, ring.Color(10, 0, 0));
    ring.show();
  }

  delay(2000);
}
```

### Key Differences

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| Temperature-to-LED mapping | Dictionary lookup by key | Array lookup with offset (`temperature - minTemp`) |
| Out-of-range check | `if temperature not in LEDdict` | `if (temperature < minTemp || temperature > maxTemp)` |
| Ring clear | `fill((0,0,0))` | `clear()` |

---

## Dictionary vs Array Mapping (Day 9 Core Idea)

| Mapping style | MicroPython | Arduino |
|---|---|---|
| Named lookup | `LEDdict[temperature]` | Usually array index math |
| Best use here | Direct and readable for exact temperature keys | Fast and compact with fixed ranges |

---

## General Language Comparison: Day 9 Concepts

| Concept | MicroPython (Pico) | Arduino (C++) |
|---|---|---|
| I2C import/setup | `from machine import I2C` | `#include <Wire.h>` |
| Sensor library | `dht20.py` external file on Pico | Installed Arduino library |
| Data access pattern | Dictionary keys | Struct fields / arrays |
| Formatted output | f-strings | `Serial.print` formatting |
| Ring control | `NeoPixel(...), ring[i], write()` | `Adafruit_NeoPixel, setPixelColor(), show()` |
| Delay | `time.sleep(seconds)` | `delay(milliseconds)` |

---

This comparison gives a direct translation path for Day 9 sensor + LED ring projects between Pico MicroPython and Arduino C++.

# Day 9: Temperature Ring

This activity reads temperature data from a sensor and displays feedback on a NeoPixel ring.

## Overview

The project combines:

- Temperature sensing with I2C communication
- LED ring visualization using NeoPixel effects
- Sensor-to-display mapping in Arduino code

## Components

- Arduino MKR Zero
- DHT20 sensor
- NeoPixel ring
- Jumper wires

## Wiring

### DHT20 Sensor

- Leg 1 -> `3.3V`
- Leg 2 -> `SDA`
- Leg 3 -> `GND`
- Leg 4 -> `SCL`

### NeoPixel Ring

- `Data IN` -> `D2`
- `VCC` -> `3.3V`
- `GND` -> `GND`

## Libraries

Install these libraries in Arduino IDE:

- Adafruit NeoPixel
- DHT20 (or SHT31-compatible library, depending on your code)

## How to Run

1. Build the circuit.
2. Open the Day 9 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Observe LED ring changes as temperature readings update.

## Notes

- Confirm your sensor library matches the sensor used in your sketch.
- Ensure `SDA` and `SCL` are connected to the MKR Zero I2C pins.

## Images

![Day 9 Picture 1](../../image/Day%209,%20picture%201.png)
![Day 9 Picture 2](../../image/Day%209,%20picture%202.png)
![Day 9 Picture 3](../../image/Day%209,%20picture%203.png)
![Day 9 Picture 4](../../image/Day%209,%20picture%204.png)
