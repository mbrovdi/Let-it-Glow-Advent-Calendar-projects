# Day 8: Rainbow Ring

This activity uses a 12-LED addressable RGB ring to create colorful lighting effects with Arduino MKR Zero.

## Overview

The project includes:

- Single and multi-LED color control
- Pattern effects such as spinning and bouncing
- Randomized color animations

## Components

- Arduino MKR Zero
- 1 x 12-LED addressable RGB ring
- Breadboard
- Jumper wires

## Wiring

Ring pin mapping:

- `Data IN` -> `D2`
- `5V` -> `5V`
- `GND` -> `GND`
- `Data OUT` -> not used (unless chaining to another LED device)

## Library Installation

Install **Adafruit NeoPixel** using Arduino IDE Library Manager.

## How to Run

1. Build the circuit.
2. Open the Day 8 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Observe ring patterns and effects.

## Notes

- Verify ring direction and `Data IN` label before wiring.
- Keep wiring short and stable for reliable data signals.

## Images

![Day 8 Picture 1](../../image/Day%208,%20picture%201.png)
![Day 8 Picture 2](../../image/Day%208,%20picture%202.png)
