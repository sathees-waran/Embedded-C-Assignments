# A03 - Implement the Time Separator with Timer 0, Timer 1 and Timer 2

## Problem Statement

Implement the time separator with Timer 0, Timer 1 and Timer 2. The system should generate the time separator (half-second blink) of a digital clock with multiple timers. Every timer has a dedicated indicator, one LED per timer.

## Output Requirements

1. All three LEDs assigned to the timers toggle every 500 ms (0.5 Hz toggle rate) as soon as the board is powered on or reset.
2. All LEDs stay synchronized on long runs of several hours, with no drift in the output.

## Inputs

- Timer0
- Timer1
- Timer2

## Implementation

Each timer interrupts at a fixed short interval, and a counter in the ISR toggles that timer's LED after enough interrupts to make 500 ms.

| Timer | Resolution | Clock setting | Reload method | LED |
|-------|------------|---------------|---------------|-----|
| Timer0 | 8-bit | Internal clock, 1:2 prescaler | Preload with 6 to count 250 ticks. The ISR adds a correction to `TMR0` for interrupt latency and the write-to-`TMR0` delay | RD0 |
| Timer1 | 16-bit | Internal clock, 1:1 prescaler | Preload `0x3CB0` (15536) to count 50000 ticks. The ISR reloads it on every overflow | RD1 |
| Timer2 | 8-bit | 1:4 prescaler | Period register `PR2` gives an automatic reload, with no software reload needed | RD2 |

- `PEIE` and `GIE` are enabled after the timers are configured, since Timer1 and Timer2 are peripheral interrupts.
- A single `isr()` handles all three interrupt flags, each with its own static counter, and clears each flag after use.
- `main()` has an empty loop: the whole application runs in interrupts.

## Hardware

| Signal | Pins |
|--------|------|
| Timer0 indicator | RD0 |
| Timer1 indicator | RD1 |
| Timer2 indicator | RD2 |

## Files

| File | Purpose |
|------|---------|
| `main.c` | Port and interrupt setup |
| `timers.c` / `timers.h` | Timer0, Timer1 and Timer2 initialisation |
| `isr.c` | Interrupt service routine with the three toggle counters |
| `hex/A03-SATHEESWARAN_M.hex` | Pre-built HEX file for PICSimLab |

## How to Run

1. Open `A03-SATHEESWARAN_M.X` in MPLAB X IDE and build it with XC8.
2. Load the HEX file in PICSimLab on the PIC16F877A board at 20 MHz.
3. The three LEDs on RD0, RD1 and RD2 start toggling together after power-up or reset.

## Concepts Covered

Timer0, Timer1 and Timer2 configuration, prescalers, preload values, interrupt service routines, drift-free timing.
