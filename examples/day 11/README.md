# Day 11: Merry Membrane

This activity uses a 4-key membrane keypad to control patterns and colors on a 15-LED RGB strand. A block LED is used as an additional indicator for status or passcode feedback.

## Overview

The project demonstrates:

- Keypad-based interaction
- Pattern and color selection on a NeoPixel strand
- Optional passcode logic with LED indicator feedback

## Components

- Arduino MKR Zero
- 1 x 4-key membrane keypad
- 1 x 15-LED addressable RGB dot strand
- 1 x block LED
- Breadboard
- Jumper wires

## Wiring

### Membrane Keypad

- Pin 1 (left) -> `3.3V`
- Pin 2 -> `D10`
- Pin 3 -> `D11`
- Pin 4 -> `D12`
- Pin 5 (right) -> `D13`

### RGB Dot Strand

- `5V` wire -> `VBUS (5V)`
- `Data` wire -> `D2`
- `GND` wire -> `GND`

### Block LED

- Anode (+) -> `D6`
- Cathode (-) -> `GND`

## Libraries

Install **Adafruit NeoPixel** in Arduino IDE Library Manager.

## How to Run

1. Build the circuit.
2. Open the Day 11 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Use keypad buttons to test mode, pattern, or passcode behavior.

## Notes

- Verify keypad pin order before powering on.
- If the strand flickers, recheck ground and data connections.

## Images

![Day 11 Picture 1](../../image/Day%2011,%20picture%201.png)
![Day 11 Picture 2](../../image/Day%2011,%20picture%202.png)
![Day 11 Picture 3](../../image/Day%2011,%20picture%203.png)
![Day 11 Picture 4](../../image/Day%2011,%20picture%204.png)