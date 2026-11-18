# A06 - Implement a LED Dimmer Application Using PWM (Timer ISR Based)

## Problem Statement

Implement a LED dimmer application using PWM (timer ISR based). The brightness of the LED illumination is based on the user input from tuning the knob of a potentiometer.

## Output Requirements

1. On giving power supply to the board, read the value of the potentiometer and set the duty cycle from it. Then read the potentiometer value again:
   1. If it is different from the previous value, update the duty cycle accordingly.
   2. If it is the same, do nothing.
2. Repeat this at regular intervals or continuously.
3. Use a timer to generate the PWM.

## Inputs

- Potentiometer 1 as the knob
- Timer for PWM

## Implementation

- **ADC:** The potentiometer is read on channel 0 (AN0) with the 10-bit ADC in right-justified mode.
- **Conversion to duty cycle:** `duty_cycle = (adc_value * 100) / 1023` maps the ADC range 0 to 1023 to 0 to 100 percent.
- **Update only on change:** The previous duty cycle starts at 255, an impossible value, so the first reading always updates the PWM. After that `set_pwm_duty()` is called only when the new duty cycle differs from the previous one.
- **Sampling interval:** The main loop reads the potentiometer every 10 ms using `__delay_ms(10)`.
- **PWM generation:** Timer2 is configured with `PR2 = 249` and a 1:1 prescaler, so it interrupts every 250 instruction cycles (50 µs at 20 MHz). Each interrupt, the ISR compares a counter (0 to 99) with the duty cycle and drives PORTD high or low. One PWM period is 100 x 50 µs = 5 ms (200 Hz), and the duty value maps directly to brightness in percent.
- The duty value is a `volatile` variable shared between `main()` and the ISR through `set_pwm_duty()`.

## Hardware

| Signal | Pins |
|--------|------|
| Potentiometer 1 | AN0 (RA0) |
| LEDs | RD0 to RD7 (PORTD), driven together |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Potentiometer reading, duty cycle calculation and change detection |
| `adc.c` / `adc.h` | ADC initialisation and channel read |
| `pwm.c` / `pwm.h` | Timer2 setup, PWM ISR and duty cycle setter |
| `main.h` | LED port macros |
| `hex/A06-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A06-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. Turn the potentiometer 1 knob and watch the LED brightness change from off to full brightness.

## Concepts Covered

ADC reading, ADC-to-duty-cycle conversion, Timer2 ISR-based PWM, change detection, `volatile` shared variables.
