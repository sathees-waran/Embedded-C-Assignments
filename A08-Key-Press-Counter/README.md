# A08 - Implement a 4 Digit Key Press Counter

## Problem Statement

Implement a 4-digit key press counter.

## Output Requirements

1. Implement a 4-digit key press counter.
2. On every key press, the counter value increments by 1.
3. On a long key press (2 seconds), the count resets to zero.

## Inputs

- DKS1 (Digital Keypad Switch 1) as the count input
- DKS1 long press (2 seconds) to reset the count

## Implementation

- **Key reading:** The keypad is read in level mode, so the program can tell how long DKS1 stays pressed.
- **Press length measurement:** While DKS1 is held, a `delay` counter increases on every pass of the main loop. The loop is paced by the SSD refresh, so the counter measures time.
- **Short press:** When the key is released and the counter is above 0 but below the long-press threshold (200 passes), the count increases by 1.
- **Long press:** Once the counter passes the threshold while the key is still held, the count is reset to 0. The release afterwards does not add a count.
- **Display:** The count is split into thousands, hundreds, tens and ones digits, converted with a segment table and shown with `display()`, which multiplexes the four SSD digits.
- The long-press threshold is a loop-pass count, not a hardware timer, so the real duration depends on the SSD refresh time and should be calibrated to 2 seconds.

## Hardware

| Signal | Pins |
|--------|------|
| DKS1 | RB0 (PORTB), active low |
| SSD segments a to g and decimal point | RD0 to RD7 (PORTD) |
| SSD digit select (four digits) | RA2 to RA5 (PORTA) |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Counting, long-press detection and display update |
| `digital_keypad.c` / `digital_keypad.h` | Keypad driver with level and state detection |
| `ssd.c` / `ssd.h` | SSD driver, segment codes and multiplexing |
| `hex/A08-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A08-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. Press DKS1 briefly to count up. Hold it for about 2 seconds to reset the display to 0000.

## Concepts Covered

Level-triggered key reading, long-press detection, SSD multiplexing, digit extraction with division and modulo.
