# Day 12: Dazzling Displays

This final activity builds a simple sensor display project using an LCD and temperature sensor with Arduino hardware.

## Overview

The project focuses on:

- Reading temperature data from a sensor
- Displaying live values on an I2C LCD
- Integrating sensor and display output in one sketch

## Components

- Arduino MKR Zero (or Arduino Uno variant, based on your setup)
- I2C LCD display
- Potentiometer (for contrast adjustment, if required by your LCD module)
- Temperature sensor
- Male-to-female jumper wires

## Libraries

Install these libraries from Arduino IDE Library Manager:

- `LiquidCrystal_I2C`
- `DHT20`

## How to Run

1. Build the LCD and sensor circuit according to your module pinout.
2. Open the Day 12 sketch in Arduino IDE.
3. Select your board (**Arduino MKR Zero** or **Arduino Uno**, whichever matches your hardware).
4. Select the correct COM port.
5. Upload the sketch.
6. Verify temperature readings appear on the LCD.

## Notes

- I2C LCD modules can use different addresses (for example `0x27` or `0x3F`).
- If text is not visible, adjust LCD contrast.
- Confirm the selected board matches your physical board before uploading.

## Images

![Day 12 Picture 1](../../image/Day%2012,%20picture%201.png)
![Day 12 Picture 2](../../image/Day%2012,%20picture%202.png)
![Day 12 Picture 3](../../image/Day%2012,%20picture%203.png)
![Day 12 Picture 4](../../image/Day%2012,%20picture%204.png)
![Day 12 Picture 5](../../image/Day%2012,%20picture%205.png)