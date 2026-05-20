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
