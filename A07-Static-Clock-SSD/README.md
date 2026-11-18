# A07 - Implement a Static Clock on SSD Using Internal Timer

## Problem Statement

Implement a static (non-configurable) clock on the seven-segment display (SSD) using an internal timer.

## Output Requirements

1. As soon as the board is powered on or reset, the clock starts at 12.00.
2. The decimal point of the hours field (ones place) blinks every 500 ms (0.5 Hz).
3. The clock format is 24 hours.

## Inputs

- Timer

## Implementation

- **Time base:** Timer2 raises an interrupt about every 200 µs (`PR2` with a 1:4 prescaler at 20 MHz). The ISR counts 5000 interrupts to make one second and advances the seconds, minutes and hours counters.
- **Time storage:** Hours and minutes are global variables shared between the ISR and `main()`. The clock starts with `hr = 12` and `min = 0`.
- **Display:** `main()` splits hours and minutes into four digits and looks each one up in a segment table (`digit[]`) for the common-cathode SSD. `display()` multiplexes the four digits by writing the segment data to PORTD and enabling one digit at a time through PORTA.
- **Blinking decimal point:** The ISR tick counter doubles as a phase marker. For the first half of each second (counter below 2500) the decimal point of the hours ones digit is cleared with `& 0x7F`. For the second half it is set with `| 0x80`, so the point toggles every 500 ms.

## Hardware

| Signal | Pins |
|--------|------|
| SSD segments a to g and decimal point | RD0 to RD7 (PORTD) |
| SSD digit select (four digits) | RA2 to RA5 (PORTA) |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Clock display and decimal point blinking |
| `isr.c` | Timer2 interrupt that advances the clock |
| `timers.c` / `timers.h` | Timer2 initialisation |
| `ssd.c` / `ssd.h` | SSD driver, segment codes and multiplexing |
| `main.h` | Shared clock variables |
| `hex/A07-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A07-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The SSD shows 12.00 after power-up or reset, with the decimal point of the second digit blinking.

## Concepts Covered

Timer2 interrupts, time keeping, SSD multiplexing, segment encoding, shared variables between an ISR and main code.
