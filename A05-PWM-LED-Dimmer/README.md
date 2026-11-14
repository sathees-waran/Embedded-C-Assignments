# A05 - Using Timer Based PWM, Implement a LED Dimmer Application

## Problem Statement

Implement an LED dimmer application using PWM (timer ISR based). The brightness of the LED illumination is controlled by the user through switches.

## Output Requirements

1. As soon as the board is powered on or reset, the LED glows at a 50% duty cycle (half of its maximum intensity).
2. The increment brightness input increases the duty cycle up to 100% (fully ON).
3. The decrement brightness input decreases the duty cycle down to 0% (fully OFF).

## Inputs

| Input | Function |
|-------|----------|
| DKS1 | Increase brightness, level triggered |
| DKS2 | Decrease brightness, level triggered |
| Program cycles | Period |

## Implementation

- **PWM generation:** Timer2 is configured with `PR2 = 249`, a 1:1 prescaler and a 1:1 postscaler, so it interrupts every 250 instruction cycles (50 µs at 20 MHz).
- Each interrupt, the ISR compares `pwm_count` with `duty_cycle` and drives PORTD high or low, then advances `pwm_count`. When `pwm_count` reaches `PWM_PERIOD` (100) it wraps to 0.
- One PWM period is therefore 100 x 50 µs = 5 ms (200 Hz), and `duty_cycle` from 0 to 100 maps directly to brightness in percent.
- **Level-triggered input:** The main loop reads the keypad in level mode. While DKS1 is held, `duty_cycle` rises by 1 per loop pass up to 100. While DKS2 is held, it falls by 1 per pass down to 0.
- **Program cycles as delay:** A counting loop in the main loop sets how fast the brightness changes while a key is held.
- `duty_cycle` and `pwm_count` are `volatile` because they are shared between `main()` and the ISR.

## Hardware

| Signal | Pins |
|--------|------|
| LEDs | RD0 to RD7 (PORTD), driven together |
| DKS1 (increase) | RB0 (PORTB), active low |
| DKS2 (decrease) | RB1 (PORTB), active low |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Initialisation and key handling |
| `main.h` | LED macros and PWM period |
| `timers.c` / `timers.h` | Timer initialisation (Timer2 is used for PWM) |
| `isr.c` | Timer2 ISR that generates the PWM waveform |
| `digital_keypad.c` / `digital_keypad.h` | Keypad driver |
| `hex/A05-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A05-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The LEDs start at half brightness. Hold DKS1 to brighten and DKS2 to dim.

## Concepts Covered

Timer2 ISR-based PWM, duty cycle control, level-triggered switch input, `volatile` shared variables.
