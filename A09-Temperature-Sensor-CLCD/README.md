# A09 - Implement a Temperature Sensor Node with CLCD Display

## Problem Statement

Implement a temperature sensor node with a character LCD (CLCD) display.

## Output Requirements

1. As soon as the board is powered up or reset, the CLCD displays the title in the first line.
2. In the second line, the room temperature is displayed with its unit.

## Inputs

- LM35 temperature sensor

## Implementation

- **ADC:** The LM35 output is read on channel 2 (AN2) with the 10-bit ADC in right-justified mode.
- **Conversion:** The LM35 gives 10 mV per degree Celsius. With a 5 V reference and 1024 steps, `millivolts = adc_value x 5 / 1024 x 1000` and `temperature = millivolts / 10`.
- **CLCD:** The display runs in 4-bit mode, with data on the upper nibble of PORTD, RS on RE2 and EN on RE1. `init_clcd()` runs the standard start-up sequence, then `clcd_print()` and `clcd_putch()` write text and single characters at a chosen line and column.
- **Display layout:** The title `A09 - LM35` is printed once on line 1. In the main loop, line 2 shows `Temp : ` followed by the two-digit temperature and a unit character.
- **Heater for testing:** RC5 is set high at start-up to turn on the simulated board heater, which lets you watch the temperature change in PICSimLab. Remove those two lines in `init_config()` if you do not want the heater on.

## Hardware

| Signal | Pins |
|--------|------|
| LM35 temperature sensor | AN2 (RA2) |
| CLCD data (4-bit mode) | RD4 to RD7 (PORTD) |
| CLCD RS | RE2 |
| CLCD EN | RE1 |
| Heater (testing) | RC5 |

## Files

| File | Purpose |
|------|---------|
| `main.c` | ADC reading, temperature conversion and display update |
| `adc.c` / `adc.h` | ADC initialisation and channel read |
| `clcd.c` / `clcd.h` | CLCD driver (initialisation, print and character write) |
| `main.h` | Port macros |
| `hex/A09-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A09-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The title appears on line 1 and the temperature on line 2. Change the LM35 temperature in PICSimLab to see the reading follow.

## Concepts Covered

ADC reading, LM35 scaling, CLCD interfacing in 4-bit mode, formatted output on a character display.
