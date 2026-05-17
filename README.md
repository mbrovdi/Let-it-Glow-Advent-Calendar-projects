# Let-it-Glow-Advent-Calendar-projects

A collection of daily Arduino MKR Zero projects inspired by the **Let it Glow Maker Advent Calendar**. Each day adds a focused hands-on activity with LEDs, sensors, keypads, and interactive effects.

## Repository Structure

```text
projects/
├── day-01-neopixel-patterns/
│   └── day-01-neopixel-patterns.ino
├── day-02-sensor-integration/
│   └── day-02-sensor-integration.ino
├── day-03-keypad-input/
│   └── day-03-keypad-input.ino
└── day-04-interactive-led-effects/
    └── day-04-interactive-led-effects.ino
```

## Setup Instructions

1. Install the latest [Arduino IDE](https://www.arduino.cc/en/software).
2. In **Tools > Board**, select your target board (for example, **Arduino MKR Zero**).
3. Install required libraries from **Library Manager**:
   - `Adafruit NeoPixel`
   - `Keypad`
4. Wire your hardware for the selected day project (NeoPixel strip/ring, sensors, keypad, button, potentiometer).
5. Open the `.ino` sketch for that day and adjust pin definitions if your wiring differs.
6. Upload the sketch and monitor behavior (Serial Monitor is used in Day 02).

## Project Highlights

- **Day 01 – NeoPixel Patterns**: color wipe, theater chase, and rainbow pattern examples.
- **Day 02 – Sensor Integration**: light sensor input drives brightness and color mood.
- **Day 03 – Keypad Input**: keypad keys control color selection and brightness levels.
- **Day 04 – Interactive LED Effects**: button-based mode switching with potentiometer speed control.

These examples are intentionally modular so you can mix effects and input methods into your own advent-calendar builds.
