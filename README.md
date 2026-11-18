# Embedded C Assignments

A collection of Embedded C assignments written for the PIC16F877A microcontroller. Each assignment is a standalone MPLAB X project with its own folder, source code, pre-built HEX file and README describing the problem statement, implementation and how to run it.

**Progress:** 10 of 15 assignments uploaded. The remaining assignments will be added in the same structure.

## Tools and Environment

| Item | Details |
|------|---------|
| Microcontroller | PIC16F877A (8-bit, PIC16 mid-range) |
| IDE | MPLAB X IDE |
| Compiler | MPLAB XC8 (project configured for v2.31) |
| Simulator | PICSimLab |
| Language | Embedded C |
| Oscillator | 20 MHz (instruction cycle = 0.2 µs) |
| Peripherals used | GPIO, digital keypad, 7-segment display (SSD), character LCD (CLCD), ADC, Timer0/1/2 |

## Assignments

| No. | Assignment | Description | Key Concepts |
|-----|------------|-------------|--------------|
| A01 | [LED Train Pattern](A01-LED-Train-Pattern) | Eight LEDs glow one by one like a train leaving a tunnel, switch off one by one like it enters, then the direction reverses. Starts automatically on power-up or reset. | GPIO output, bit shifting, software delay |
| A02 | [Multiple LED Patterns Controlled by Switches](A02-Multiple-LED-Patterns-Switches) | Four keypad switches select four LED patterns: bidirectional train, one-way fill and clear, alternate blink and nibble-wise blink. All LEDs are off at power-up. | GPIO input and output, digital keypad driver, state detection |
| A03 | [Time Separator with Timer0, Timer1 and Timer2](A03-Time-Separator-Timers) | Three LEDs, one per timer, toggle every 500 ms like the colon of a digital clock, with no drift between them. | Timer0, Timer1, Timer2, timer interrupts, preload values |
| A04 | [Point Brightness Control](A04-Point-Brightness-Control) | An LED idles at 10% brightness. A switch press raises it to 100% for 5 seconds before it dims again. | Software PWM, Timer0 interrupt, switch input |
| A05 | [Timer-Based PWM LED Dimmer](A05-PWM-LED-Dimmer) | LED brightness starts at 50% and is raised or lowered with two level-triggered switches between 0% and 100%. | Timer2 ISR-based PWM, duty cycle, level-triggered input |
| A06 | [Potentiometer-Controlled PWM LED Dimmer](A06-Potentiometer-PWM-LED-Dimmer) | LED brightness follows the potentiometer knob. The ADC value is converted to a duty cycle and the PWM is generated in a Timer2 ISR. | ADC, Timer2 ISR PWM, duty cycle |
| A07 | [Static Clock on SSD](A07-Static-Clock-SSD) | A 24-hour clock on the four-digit SSD that starts at 12.00. The decimal point of the hours' ones digit blinks every 500 ms. | Timer2 interrupt, SSD multiplexing, time keeping |
| A08 | [4-Digit Key Press Counter](A08-Key-Press-Counter) | DKS1 increments a four-digit count shown on the SSD on every press. A long press (about 2 seconds) resets it to zero. | Keypad input, long-press detection, SSD multiplexing |
| A09 | [Temperature Sensor Node with CLCD](A09-Temperature-Sensor-CLCD) | An LM35 reading is converted to degrees Celsius. The CLCD shows a title on line 1 and the room temperature on line 2. | ADC, LM35, CLCD in 4-bit mode |
| A10 | [Scrolling Number Marquee with Direction Control](A10-Scrolling-Number-Marquee) | A hard-coded 10-digit number scrolls across the four SSDs. Keys change the direction left or right and stop or start the scroll. | SSD multiplexing, keypad input, scroll logic |

## Repository Structure

```
Embedded-C-Assignments/
├── README.md
├── .gitignore
├── A01-LED-Train-Pattern/
│   ├── README.md
│   ├── hex/                      Pre-built HEX file for PICSimLab
│   └── A01-SATHEESWARAN_M.X/     MPLAB X project (source and project files)
├── A02-Multiple-LED-Patterns-Switches/
├── A03-Time-Separator-Timers/
├── A04-Point-Brightness-Control/
├── A05-PWM-LED-Dimmer/
├── A06-Potentiometer-PWM-LED-Dimmer/
├── A07-Static-Clock-SSD/
├── A08-Key-Press-Counter/
├── A09-Temperature-Sensor-CLCD/
└── A10-Scrolling-Number-Marquee/
```


## How to Build and Run

1. Open MPLAB X IDE and choose **File > Open Project**, then select the `.X` folder inside an assignment folder.
2. Confirm the device is PIC16F877A and the compiler is XC8, then click **Clean and Build**.
3. In PICSimLab, select a board with the PIC16F877A, set the clock to 20 MHz, and load the HEX file from the assignment's `hex/` folder (or the one generated in `dist/`).
4. Run the simulation and follow the assignment README for the expected behaviour.

Each assignment README lists the exact switches and LEDs it uses.
