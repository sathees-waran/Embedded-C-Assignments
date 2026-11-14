# A04 - Implement a Point Brightness Control

## Problem Statement

Implement a point brightness control using PWM (timer ISR based). The LED should dim to a fixed brightness (10% duty cycle). Once the user presses a switch, the LED should glow at 100% duty cycle for 5 seconds. After the 5 seconds time out, the LED should dim back to 10% duty cycle.

## Output Requirements

1. As soon as the board is powered on or reset, the LED glows at a dimmed brightness (duty cycle = 10%).
2. On the switch input, the LED glows at 100% brightness for 5 seconds.
3. After 5 seconds, the LED goes back to 10% brightness.

## Inputs

- DKS1 (Digital Keypad Switch 1) as the trigger
- Timer for dimming

## Implementation

- **PWM:** A loop counter runs from 0 to `PERIOD` (100). The LED on RD7 is ON while the counter is below `duty_cycle` and OFF otherwise, so `duty_cycle` is the brightness in percent.
- **Trigger:** The main loop reads the keypad. When DKS1 is pressed, `duty_cycle` is set to 100 and Timer0 interrupts are enabled.
- **5-second timeout:** Timer0 (1:2 prescaler, preload 6 for 250 ticks) interrupts every 100 µs at 20 MHz. The ISR counts 50000 interrupts, which is 5 seconds, then lowers the brightness and disables the Timer0 interrupt.
- Shared variables `duty_cycle` and `req_time` are declared in `main.c` and exposed to the ISR through `main.h`.

## Hardware

| Signal | Pins |
|--------|------|
| LED | RD7 (PORTD) |
| DKS1 | RB0 (PORTB), active low |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Initialisation, software PWM and switch handling |
| `main.h` | LED and shared variable definitions |
| `timers.c` / `timers.h` | Timer0 initialisation |
| `isr.c` | Timer0 ISR that implements the 5-second timeout |
| `digital_keypad.c` / `digital_keypad.h` | Keypad driver |
| `hex/A04-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A04-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The LED on RD7 glows dimly. Press DKS1 to see it at full brightness for 5 seconds.

## Concepts Covered

Software PWM, duty cycle, Timer0 interrupt, time-out handling, switch input.
