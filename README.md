# Arduino OLED Stopwatch

A simple digital stopwatch built using an Arduino UNO and a 0.96-inch OLED display. The project features push-button control for starting, pausing, and resuming time measurement, with the elapsed time displayed on the OLED screen.

## Project Overview

The primary objective of this project was to develop a functional stopwatch using an Arduino microcontroller, push buttons, and an OLED display.

The stopwatch uses the Arduino's built-in `millis()` function for time measurement instead of relying on blocking delays. This allows the microcontroller to continuously execute the main program while tracking elapsed time.

## Features

- **Start:** Initiates the stopwatch when the start button is pressed.
- **Pause:** Temporarily stops time measurement.
- **Resume:** Continues counting from the previously paused time.
- **OLED Interface:** Displays the elapsed time on a 128×64 OLED display.
- **Non-blocking Time Measurement:** Uses `millis()` for time tracking without using `delay()`.

## Hardware Components

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| 0.96-inch OLED Display (128×64, I2C) | 1 |
| Push Buttons | 2 |
| Jumper Wires | As required |

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| Start Button | Digital Pin 2 |
| Pause Button | Digital Pin 12 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| OLED VCC | 5V (if supported by the module) |
| OLED GND | GND |

Both push buttons are configured using the Arduino's internal pull-up resistors (`INPUT_PULLUP`).

## Software & Libraries

- Arduino IDE
- Arduino C/C++
- Wire Library
- Adafruit GFX Library
- Adafruit SSD1306 Library

## Working Principle

1. Initially, the OLED displays a "CLICK TO START!" message.
2. Pressing the start button initiates time measurement.
3. The `millis()` function is used to calculate the elapsed time.
4. The calculated time is continuously updated on the OLED display.
5. Pressing the pause button temporarily stops the stopwatch.
6. Pressing the start button again resumes the stopwatch from its previously paused state.

## How to Run

1. Install the Arduino IDE.
2. Install the following libraries through the Arduino Library Manager:
   - Adafruit GFX Library
   - Adafruit SSD1306
3. Connect the hardware components according to the pin configuration.
4. Open the Arduino sketch in the Arduino IDE.
5. Select Arduino UNO as the target board.
6. Select the appropriate COM port.
7. Upload the code to the Arduino.
8. Press the start button to operate the stopwatch.

## Concepts Explored

Through this project, I explored and practised the following concepts:

- Digital input interfacing.
- Push-button operation using internal pull-up resistors.
- I2C communication protocol.
- OLED display interfacing and graphics rendering.
- Time measurement using the `millis()` function.
- Non-blocking programming techniques.
- Boolean variables and basic state management.
- Pause and resume logic in embedded applications.

## Future Improvements

- Implement software-based button debouncing.
- Add a reset functionality.
- Introduce lap-time recording.
- Improve time formatting to display hours, minutes, seconds, and milliseconds.
