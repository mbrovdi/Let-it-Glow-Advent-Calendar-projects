# Day 4: Bar Graph Display with Arduino MKR Zero

This project controls a 5-segment LED bar graph using an Arduino MKR Zero and two pushbuttons. A resistor network is used to simplify wiring for the LED segments.

## Overview

The sketch includes:

- A segment test sequence to verify each LED segment
- Interactive button control for changing the display state

## Components

- Arduino MKR Zero
- Breadboard
- 5-segment LED bar graph display
- 5-pin resistor network (common GND pin marked with a dot)
- 2 pushbuttons
- Jumper wires

## Wiring

### LED Bar Graph

- Anodes (long legs): connect to Arduino pins `D13`, `D12`, `D11`, `D10`, `D9` (one segment per pin)
- Cathodes (short legs): connect each to a separate resistor-network pin (excluding the common dot pin)

### Resistor Network

- Common dot pin: connect to `GND` rail

### Pushbuttons

- Red button: one side to `3.3V`, the other side to `D2`
- Green button: one side to `3.3V`, the other side to `D3`

### Power Rails

- Arduino `3.3V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

## How to Run

1. Build the circuit as described above.
2. Open the Day 4 sketch in the Arduino IDE.
3. Select the correct board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Press the buttons to interact with the bar graph.

## Notes

- Confirm the bar graph pin orientation before wiring.
- Use the resistor network's marked common pin correctly to avoid short circuits.

## Images

![Day 4 Picture 1](../../image/Day%204,%20picture%201.png)
![Day 4 Picture 2](../../image/Day%204,%20picture%202.png)
