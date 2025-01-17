# Homework 1 - Nicholas Ayat (DESIGN.md)

## Introduction
The aim of this assignment is to get you comfortable with writing functions in C and to help you understand how we can structure C programs across multiple files. You'll write five functions and complete the `caat` program. This involves using tools like `make` and separating your code into logical files.

## My design for functions

### Function 1: `area_of_disk`
**Prototype:**
```c
float area_of_disk(float radius);
```
**Purpose:** Calculates the area of a disk given its radius using the formula: \( A = \pi r^2 \).

**Plan:**
- Use the constant `M_PI` from `<math.h>` for the value of \( \pi \).
- Compute \( r^2 \) using `radius * radius`.
- Return \( M\_PI * r^2 \).

### Function 2: `area_of_ring`
**Prototype:**
```c
float area_of_ring(float outer_radius, float inner_radius);
```
**Purpose:** Calculates the area of a ring using the formula: \( A = \pi (r_{outer}^2 - r_{inner}^2) \).

**Plan:**
- Compute the areas of the outer and inner disks.
- Subtract the inner disk's area from the outer disk's area.
- Return the result.

### Function 3: `bigger_minus_smaller`
**Prototype:**
```c
float bigger_minus_smaller(float num1, float num2);
```
**Purpose:** Computes the difference between the larger and smaller of two numbers.

**Plan:**
- Use an `if` statement or the `fmax` and `fmin` functions from `<math.h>` to determine the larger and smaller numbers.
- Return the difference between the larger and smaller values.

### Function 4: `value_in_range`
**Prototype:**
```c
bool value_in_range(float lower, float value, float upper);
```
**Purpose:** Determines whether a value is within a given range \([lower, upper]\), inclusive.

**Plan:**
- Use logical comparisons (`<=` and `>=`) to check if the value lies within the range.
- Return `true` if it does, and `false` otherwise.

### Function 5: `sum_of_greater_squares`
**Prototype:**
```c
float sum_of_greater_squares(float a, float b, float c);
```
**Purpose:** Calculates the sum of the squares of the two largest values among \( a, b, c \).

**Plan:**
- Compute \( a^2, b^2, c^2 \).
- Identify the two largest squares using conditional logic or sorting.
- Return the sum of these two largest squares.

---

## My design for `caat.c`
**Purpose:** A program that doubles vowels (`aeiouAEIOU`) in the input stream and outputs the result. All other characters are output unchanged.

**Plan:**
- Read characters from `stdin` using `getchar()`.
- Check if each character is a vowel.
  - If it is, output the character twice using `putchar()`.
  - Otherwise, output the character once.
- Stop processing upon encountering `EOF`.

---

## HW #1 Deliverables
1. `DESIGN.md` (this file)
2. `hw1.c`
3. `caat.c`
4. Updated `hw1_test.c` (optional for custom tests)
5. Submit the commit ID to Canvas.