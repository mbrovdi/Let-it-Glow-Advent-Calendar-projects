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
