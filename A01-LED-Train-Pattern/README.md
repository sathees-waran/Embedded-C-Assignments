# A01 - Implement LED Train Pattern on LEDs

## Problem Statement

Write an Embedded C program to display a pattern on the LEDs.

## Output Requirements

1. Consider 8 LEDs from the board. These LEDs have to glow one by one, as if a train bogie is coming out of a tunnel, every second (approximately, without a timer implementation), from left to right, as soon as the board is powered on or reset. This is called the **exit**.
2. Once all LEDs are ON, the LEDs should switch OFF one by one, as if the train bogie is entering a tunnel, from left to right. This is called the **entry**.
3. Once the exit and entry are complete, change the direction of the train from right to left.
4. This change of direction is repeated between every exit and entry of the train.

## Inputs

- No external inputs.
- The program is software controlled.

## Implementation

- PORTD is configured as output and drives the 8 LEDs (RD0 to RD7).
- A software counter creates the delay between LED steps, so no timer is used.
- A step counter `i` selects one of four phases, each lasting 8 steps:

| Steps | Phase | Operation on PORTD |
|-------|-------|--------------------|
| 0 to 7 | Exit, first direction | `(PORTD << 1) \| 1` shifts a 1 in from the RD0 side |
| 8 to 15 | Entry, first direction | `PORTD << 1` shifts a 0 in from the RD0 side |
| 16 to 23 | Exit, reverse direction | `(PORTD >> 1) \| 0x80` shifts a 1 in from the RD7 side |
| 24 to 31 | Entry, reverse direction | `PORTD >> 1` shifts a 0 in from the RD7 side |

- After step 31 the counter resets and the whole sequence repeats.

## Hardware

| Signal | Pins |
|--------|------|
| LEDs | RD0 to RD7 (PORTD) |

## Files

| File | Purpose |
|------|---------|
| `main.c` | LED train logic |
| `main.h` | Macros for output direction |
| `hex/A01-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A01-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board.
3. The LED train runs automatically after power-up or reset.

## Concepts Covered

GPIO configuration, bitwise shift operations, software delay generation.
