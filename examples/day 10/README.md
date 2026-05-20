# Day 10: ULTRA Blinky

This activity controls a 15-LED addressable RGB dot strand with Arduino MKR Zero and a slide potentiometer for interactive effect changes.

## Overview

In this project, you will:

- Wire and control a 15-LED NeoPixel dot strand
- Read potentiometer values on an analog input
- Adjust animation behavior based on slider position

## Components

- Arduino MKR Zero
- 1 x 15-LED addressable RGB dot strand
- 1 x 10k slide potentiometer
- Breadboard
- Jumper wires

## Wiring

### Dot Strand

- `5V` wire -> `5V`
- `Data` wire -> `D2`
- `GND` wire -> `GND`

### Slide Potentiometer

- Left pin (top view) -> `3.3V`
- Right pin (top view) -> `A1`
- Center pin (bottom) -> `GND`

## Libraries

Install **Adafruit NeoPixel** in Arduino IDE Library Manager.

## How to Run

1. Build the circuit.
2. Open the Day 10 sketch in Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Move the potentiometer and observe pattern changes.

## Notes

- Verify strand wire labeling before connecting power.
- Keep ground common between strand and Arduino.

## Images

![Day 10 Picture 2](../../image/Day%2010,%20picture%202.png)
![Day 10 Picture 3](../../image/Day%2010,%20picture%203.png)
![Day 10 Picture 4](../../image/Day%2010,%20picture%204.png)
