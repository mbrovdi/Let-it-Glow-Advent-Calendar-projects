# Day 7: Time to Slide

This activity introduces analog input using a slide potentiometer with Arduino MKR Zero. The potentiometer value can be used to control the color or behavior of addressable RGB LEDs.

## Overview

In this project, you will:

- Read potentiometer position using an analog pin
- Map analog values to LED effects in code
- Explore interactive light control

## Components

- Arduino MKR Zero
- 1 x 45 mm slide potentiometer
- 1 x potentiometer cap
- 2 x 10 mm addressable RGB LEDs
- Breadboard
- Jumper wires

## Wiring

### Slide Potentiometer

- Left pin -> `3.3V`
- Right pin -> `A1`
- Center pin -> `GND`

### RGB LEDs

- Keep RGB LED wiring the same as Day 6

## How to Run

1. Build the circuit.
2. Open the Day 7 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Move the slider and observe LED behavior changes.

## Notes

- If values move in reverse, swap the two outer potentiometer pins.
- Confirm shared ground between Arduino and LEDs.
