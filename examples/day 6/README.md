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
