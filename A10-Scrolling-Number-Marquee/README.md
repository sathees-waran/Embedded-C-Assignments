# A10 - Implement a Scrolling Number Marquee with Direction Control

## Problem Statement

Implement a scrolling number marquee on the SSDs with scroll direction control on a key press.

## Output Requirements

1. As soon as the board is powered on or reset, a static (hard-coded) message starts scrolling from right to left on the SSDs.
2. The scroll repeats indefinitely until a direction change key is pressed.
3. The scroll frequency is 0.5 Hz (approximate, non-timer based).
4. On press of the Right Direction key, the scroll direction changes from left to right at that instant.
5. On press of the Left Direction key, the scroll direction changes from right to left at that instant.
6. On press of the Stop / Start key, the scroll stops at that instant.
7. On press of any key, the scroll starts at that instant.

## Inputs

1. Static number message in code (10 digits plus 2 spaces)
2. DKS1 as the Left Direction key
3. DKS2 as the Right Direction key
4. DKS3 as the Stop / Start key

## Implementation

- **Message buffer:** The message is a table of 12 symbols: the digits 0 to 9 followed by two filler symbols. The four SSDs show a window of four consecutive symbols that starts at index `i`.
- **Scrolling:** Every `DELAY` passes of the main loop (a software counter, not a timer), `i` moves one position and the four displayed symbols are refreshed using `(i + n) % 12`, so the message wraps around endlessly.
  - Left direction (DKS1): `i` increases, so the message moves from right to left. This is the direction at power-up.
  - Right direction (DKS2): `i` decreases, so the message moves from left to right.
- **Stop / Start:** DKS3 toggles a `start` flag that pauses or resumes the scroll. Pressing DKS1 or DKS2 also resumes scrolling.
- **Key handling:** The keypad is read in state mode, so each press triggers once.
- **Display:** `display()` multiplexes the four SSD digits on every pass of the main loop.
- The scroll speed is set by `DELAY` and by the SSD refresh time, so it should be calibrated against the 0.5 Hz target.

## Hardware

| Signal | Pins |
|--------|------|
| DKS1 (left), DKS2 (right), DKS3 (stop / start) | RB0, RB1, RB2 (PORTB), active low |
| SSD segments a to g and decimal point | RD0 to RD7 (PORTD) |
| SSD digit select (four digits) | RA2 to RA5 (PORTA) |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Message table, scroll logic and key handling |
| `digital_keypad.c` / `digital_keypad.h` | Keypad driver with level and state detection |
| `ssd.c` / `ssd.h` | SSD driver, segment codes and multiplexing |
| `hex/A10-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A10-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The number starts scrolling right to left. Use DKS1 and DKS2 to change direction and DKS3 to stop or start.

## Concepts Covered

SSD multiplexing, circular buffer indexing with modulo, key-controlled state flags, software-timed scrolling.
