# Day 5: Switch the DIP

This project uses a 5-position DIP switch as digital input for the Arduino MKR Zero and maps each switch to one segment of a 5-segment LED bar graph.

## Overview

The goal is simple:

- Read five DIP switch inputs
- Turn on the matching LED bar graph segment for each active switch

## Components

- Arduino MKR Zero
- Breadboard
- 5-position DIP switch
- 5-segment LED bar graph display
- 5-pin resistor network (common GND pin marked with a dot)
- Jumper wires

## Wiring

### Power Rails

- Arduino `3.3V` to breadboard positive rail
- Arduino `GND` to breadboard ground rail

### DIP Switch Connections

For each DIP switch position:

- One side to `3.3V` rail
- Other side to an Arduino input pin

Pin mapping:

- Switch 1 -> `D6`
- Switch 2 -> `D5`
- Switch 3 -> `D4`
- Switch 4 -> `D3`
- Switch 5 -> `D2`

### Bar Graph Connections

- Segment 1 anode -> `D13`
- Segment 2 anode -> `D12`
- Segment 3 anode -> `D11`
- Segment 4 anode -> `D10`
- Segment 5 anode -> `D9`

Each segment cathode connects to one resistor-network pin (non-dot pins).
Resistor-network common dot pin connects to `GND`.

## How to Run

1. Build the circuit using the mapping above.
2. Open the Day 5 sketch in the Arduino IDE.
3. Select board: **Arduino MKR Zero**.
4. Select the correct COM port.
5. Upload the sketch.
6. Toggle each DIP switch and verify the matching bar graph segment lights up.

## Notes

- Confirm bar graph and DIP switch orientation before wiring.
- Keep grounds common between all components.

