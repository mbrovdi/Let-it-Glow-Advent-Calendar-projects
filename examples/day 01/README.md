# Day 01 - Getting Started with Arduino MKR Zero

Welcome to Day 01.
This page is the Arduino-first setup guide that mirrors the Day 1 onboarding ideas from the original Pi Pico kit flow.

## Goal for Day 01

- Install and test the Arduino development environment
- Connect and identify your Arduino MKR Zero
- Build your first simple breadboard circuit layout
- Understand why this Arduino version is interesting compared to Pi Pico

## Tools You Need

- Arduino MKR Zero board
- USB cable (data-capable)
- Breadboard
- Jumper wires
- LEDs (at least 1)
- Resistors (220 ohm is ideal for LED current limiting)
- Arduino IDE

## Install Arduino IDE

1. Download Arduino IDE: https://www.arduino.cc/en/software
2. Open Arduino IDE and go to Tools > Board > Boards Manager.
3. Install the board package: Arduino SAMD Boards.
4. Connect your MKR Zero via USB.
5. Select board: Arduino MKR Zero.
6. Select the correct COM port in Tools > Port.

## First Upload Test

1. In Arduino IDE, open File > Examples > 01.Basics > Blink.
2. Upload to the board.
3. Confirm the on-board LED blinks.

This confirms your board, cable, drivers, and IDE are working.

## Breadboard Basics (MKR Zero)

- Use the 3.3V pin and GND rails from MKR Zero.
- Place an LED on the breadboard with a 220 ohm resistor in series.
- Connect a digital output pin through the resistor to the LED anode.
- Connect LED cathode to GND.

Important: MKR Zero is a 3.3V logic board. Avoid feeding 5V signals into GPIO pins.

## Arduino vs Pi Pico: Why This Project Is Interesting

This repo intentionally recreates a Pico-flavored kit journey on Arduino MKR Zero.
You learn the same electronics concepts through a different development style:

- Pico path: usually MicroPython + Thonny, fast script iteration
- Arduino path: C++ sketches + Arduino IDE, compile-upload embedded workflow

Both are great. Seeing both in practice helps you understand tools, language tradeoffs, and hardware-level thinking.

## Related Kit Context

Original Day 1 inspiration:
https://thepihut.com/blogs/raspberry-pi-tutorials/let-it-glow-advent-calendar-day-1-lets-get-started

## Next Step

Move to Day 02 and start the first activity sketch.
