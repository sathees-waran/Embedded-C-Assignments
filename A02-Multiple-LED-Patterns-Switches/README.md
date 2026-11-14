# A02 - Implement Multiple Patterns on LEDs Controlled by Switches

## Problem Statement

Upon giving the power supply, all 8 LEDs should be OFF. Pressing a switch on the digital keypad selects one of four LED patterns:

- Press switch 1 for pattern 1.
- Press switch 2 for pattern 2.
- Press switch 3 for pattern 3.
- Press switch 4 for pattern 4.

## Output Requirements

1. **Pattern 1:** The LEDs glow from left to right and from right to left, as explained in assignment A01.
2. **Pattern 2:** The LEDs glow from left to right and switch OFF from left to right, with no direction change.
3. **Pattern 3:** The LEDs blink alternately.
4. **Pattern 4:** The LEDs blink nibble-wise: the first 4 LEDs are ON while the next 4 are OFF, then the first 4 are OFF while the next 4 are ON.

## Inputs

| Switch | Pattern |
|--------|---------|
| DKS1 | Pattern 1 |
| DKS2 | Pattern 2 |
| DKS3 | Pattern 3 |
| DKS4 | Pattern 4 |

## Implementation

- PORTD drives the 8 LEDs and is cleared at start-up, so all LEDs are off until a switch is pressed.
- `read_digital_keypad(STATE)` returns a switch code once per press, which makes each press a single selection event.
- One flag per pattern records the active pattern. Pressing a switch sets its flag, clears the others and resets the LED state and delay counter, so patterns switch cleanly.
- A software counter provides the delay between steps.

| Pattern | Starting value of PORTD | Update per step |
|---------|-------------------------|-----------------|
| 1 | `0x00` | Four 8-step phases of left and right shifting, as in A01 |
| 2 | `0x00` | Two 8-step phases: shift 1s in, then shift 0s in, always in one direction |
| 3 | `0x55` | `PORTD = ~PORTD`, alternating between `0x55` and `0xAA` |
| 4 | `0x0F` | `PORTD = ~PORTD`, alternating between `0x0F` and `0xF0` |

## Hardware

| Signal | Pins |
|--------|------|
| LEDs | RD0 to RD7 (PORTD) |
| DKS1 to DKS4 | RB0 to RB3 (PORTB), active low |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Pattern selection and LED logic |
| `digital_keypad.c` / `digital_keypad.h` | Keypad driver with level and state detection |
| `hex/A02-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A02-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board.
3. All LEDs stay off until a switch is pressed. Press DKS1 to DKS4 to select a pattern.

## Concepts Covered

GPIO input and output, digital keypad driver, state-based key detection, pattern selection with flags.
