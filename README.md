# Let it Glow Maker Advent Calendar (Arduino MKR Zero)

[![Compile Arduino Sketches](https://github.com/mbrovdi/Let-it-Glow-Advent-Calendar-projects/actions/workflows/compile-sketches.yml/badge.svg)](https://github.com/mbrovdi/Let-it-Glow-Advent-Calendar-projects/actions/workflows/compile-sketches.yml)
[![Open Issues](https://img.shields.io/github/issues/mbrovdi/Let-it-Glow-Advent-Calendar-projects)](https://github.com/mbrovdi/Let-it-Glow-Advent-Calendar-projects/issues)
[![License: AGPL-3.0](https://img.shields.io/badge/License-AGPL--3.0-blue.svg)](LICENSE)
![Platform: Arduino MKR Zero](https://img.shields.io/badge/Platform-Arduino%20MKR%20Zero-00979D)
![Language: Arduino C++](https://img.shields.io/badge/Language-Arduino%20C%2B%2B-00599C)
![Project: Advent Calendar](https://img.shields.io/badge/Project-Advent%20Calendar-ff6f00)

<p align="center">
	<img src="image/Day%202.png" alt="Day 2 circuit" width="260" />
	<img src="image/Day%203.png" alt="Day 3 project" width="260" />
	<img src="image/Day%2011%2C%20picture%201.png" alt="Day 11 build" width="260" />
</p>

This repository is not just a copy of the Let it Glow activities.
It is a full Arduino MKR Zero conversion of a Raspberry Pi Pico-style maker kit, with hands-on comparisons between the two platforms.

If you are curious about the original kit context, start here:
- Day 1 kit guide (The Pi Hut): https://thepihut.com/blogs/raspberry-pi-tutorials/let-it-glow-advent-calendar-day-1-lets-get-started

## Why This Is Interesting

- Same projects, different mindset: comparing Pico + MicroPython with Arduino + C++
- Different development tools: Thonny workflow vs Arduino IDE workflow
- Different coding style: interpreted scripting vs compiled sketches
- Different electronics considerations: logic levels, power rails, pull resistors, and pin mapping

For a practical side-by-side example, see:
- examples/day 03/README.md

## Repository Structure

- `examples/`: Day-by-day Arduino sketches and README guides
- `image/`: Project photos and reference visuals

## Day Index

- Day 01: [Tools and MKR Zero setup](examples/day%2001/README.md)
- Day 02: [Activity files](examples/day%2002/)
- Day 03: [Arduino vs Pico comparisons](examples/day%2003/README.md)
- Day 04: [Activity files](examples/day%2004/)
- Day 05: [Activity files](examples/day%2005/)
- Day 06: [Activity files](examples/day%2006/)
- Day 07: [Activity files](examples/day%2007/)
- Day 08: [Activity files](examples/day%2008/)
- Day 09: [Activity files](examples/day%2009/)
- Day 10: [Activity files](examples/day%2010/)
- Day 11: [Activity files](examples/day%2011/)
- Day 12: [Activity files](examples/day%2012/)

## What You Will Build

- LED and bar graph lighting patterns
- Interactive projects using buttons and keypads
- Sensor-driven behaviors
- NeoPixel animations and effects

## Arduino vs Pi Pico (Quick Reflection)

In this project, both platforms can achieve similar outcomes, but they feel different to build with.

- Raspberry Pi Pico is fast to iterate in MicroPython and very beginner-friendly for experimentation.
- Arduino MKR Zero feels closer to embedded production habits: compile, upload, and tune hardware-aware code.
- Arduino IDE gives a clear board-and-library flow, while Thonny gives a rapid script-and-run flow.
- MKR Zero is a 3.3V logic board, so voltage planning matters when you connect external modules and sensors.

The fun part is that the same circuit idea teaches different lessons depending on which board you choose.

## Requirements

- Arduino MKR Zero
- Arduino IDE
- Breadboard, jumper wires, LEDs, and basic components
- Adafruit NeoPixel library (for NeoPixel-based activities):
	- https://github.com/adafruit/Adafruit_NeoPixel

## Getting Started

1. Start with Day 01 for setup guidance.
2. Open any activity folder for the day you want to run.
3. Connect your Arduino MKR Zero and build the circuit from that activity.
4. Open the corresponding `.ino` file in the Arduino IDE.
5. Select board: **Arduino MKR Zero**.
6. Select the correct COM port and upload.

## Notes

- Wiring and required parts can vary by day.
- Check each day folder README for activity-specific instructions.
- The compile badge at the top verifies sketches build in GitHub Actions.

Happy making.
