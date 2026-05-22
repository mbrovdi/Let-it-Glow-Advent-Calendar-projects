# Day 01 - Getting Started with Arduino MKR Zero

Welcome to Day 01.
This page is the Arduino-first setup guide that mirrors the Day 1 onboarding ideas from the original Pi Pico kit flow.

Original kit link:
https://thepihut.com/blogs/raspberry-pi-tutorials/let-it-glow-advent-calendar-day-1-lets-get-started

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

## Hello World in Arduino IDE

Once Blink is working, open this sketch:
- `examples/day 01/day_01_hello_world/day_01_hello_world.ino`

Use it as a simple example of how Arduino IDE uploads code and prints text to the Serial Monitor.

```cpp
void setup() {
	Serial.begin(9600);

	while (!Serial) {
	}

	Serial.println("Hello World");
}

void loop() {
}
```

How to test it:

1. Open the sketch in Arduino IDE.
2. Click Upload.
3. Open Tools > Serial Monitor.
4. Set the baud rate to 9600.
5. Confirm that `Hello World` appears in the output window.

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

## Pi Pico vs Arduino MKR Zero

This project is interesting because the activities are similar, but the experience of building them is not.

| Topic | Raspberry Pi Pico | Arduino MKR Zero |
|---|---|---|
| Development tool | Thonny | Arduino IDE |
| Main language | MicroPython | Arduino C++ |
| Workflow | Edit and run scripts quickly | Compile and upload sketches |
| Voltage mindset | Commonly taught as a 3.3V board | MKR Zero is also a 3.3V board and should not receive 5V on GPIO pins |
| Learning style | Fast experimentation | More embedded-style development |

## Why That Comparison Matters

- It shows how the same electronics idea can be taught through two different software workflows.
- It helps beginners see the tradeoff between quick scripting and compile-upload embedded programming.
- It makes the repo more than a set of examples: it becomes a practical comparison between platforms, tools, and hardware habits.
- It gave me a way to reflect on what changes when you translate a Pico-oriented kit into Arduino code and wiring.

Both are great. Seeing both in practice helps you understand tools, language tradeoffs, and hardware-level thinking.

## Next Step

Move to Day 02 and start the first activity sketch.
