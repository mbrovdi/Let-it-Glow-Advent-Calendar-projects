# Day 2: Lighting LEDs

This activity introduces basic LED control with an Arduino MKR Zero. The sketch turns an LED on and off in a repeating loop so you can observe how digital output and delay timing affect behavior.

## Overview

In this project, you will:

- Build a simple LED circuit with a current-limiting resistor
- Upload a blinking sketch to the Arduino MKR Zero
- Experiment with delay values to change blink speed

## Components

- Arduino MKR Zero
- Breadboard
- 1 LED
- 220 ohm resistor
- Jumper wires
- USB cable

## Wiring

- LED anode (long leg) to digital pin `D6` through the 220 ohm resistor
- LED cathode (short leg) to `GND`

## How to Run

1. Build the circuit on your breadboard.
2. Open the Day 2 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Observe the LED blink pattern.

## Observations

- Larger delay values produce slower blinking
- Smaller delay values produce faster blinking

## Learning Outcome

This activity demonstrates core Arduino concepts: digital output, timing with `delay()`, and safe LED wiring with a resistor.

## Images

![Day 2 Setup](../../image/Day%202.png)
