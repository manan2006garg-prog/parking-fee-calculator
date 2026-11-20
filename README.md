# Parking Fee Calculator

Estimate a parking fee from the number of minutes parked. The first hour costs Rs. 30, each started hour after that adds Rs. 15, and the daily fee is capped at Rs. 200.

## Build and run

Compile with a C11 compiler:

    gcc -std=c11 -Wall -Wextra -pedantic main.c -o parking-fee
    ./parking-fee

On Windows, run `parking-fee.exe` after compiling.

## Features

- Accepts parking times from 1 minute to 24 hours.
- Rounds partial hours up to the next billed hour.
- Applies and reports the daily maximum fee.
- Rejects invalid or out-of-range input.

## Learning goals

Practice integer input, validation, rounding with integer arithmetic, conditions, and formatted output in C.
