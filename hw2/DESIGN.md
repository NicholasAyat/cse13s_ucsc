# Homework 2: Design Document

  * author: *Nicholas Ayat* 
  * date: January 2025

## introduction

This design document for hw2 outlines my approach to solving the tasks outlined in Homework 2, which involve implementing several functions that operate on integers and arrays, as well as building a basic calculator program. I will describe the purpose of each function, the methods I intend to use, and any relevant considerations/edge cases that arise.

## function 1: `next_collatz_number`

This function computes the next Collatz number for a given input integer `n`.

### plan
- Check if `n` is even; if so, return `n / 2`.
- If `n` is odd, return `3 * n + 1`.
- Ensure the function handles any edge cases, such as very large input values, without overflow.

## function 2: `count_collatz_steps`

This function calculates the number of steps required for a given number `n` to reach 1 using the Collatz sequence.

### plan
- Use a loop to repeatedly apply `next_collatz_number` until `n` equals 1, counting the number of steps.
- Potentially consider a recursive approach for elegance, but ensure it does not result in a stack overflow for large inputs.
- Return the step count.
- I'm planning to use iteration for better memory efficiency.

## function 3: `maximum`

This function finds the maximum value in an array of integers.

### plan
- Initialize a variable to hold the maximum value, setting it to the first element of the array.
- Iterate through the array, updating the maximum value whenever a larger element is encountered.
- Ensure the function correctly handles arrays of size 1 and does not exceed the array bounds.
- Explaination for why `sizeof` cannot be used to determine the array size: since the array is passed as a pointer, `sizeof` gives the size of the pointer, not the array.

## function 4: `sum_positive`

This function calculates the sum of all positive elements in an array of integers.

### plan
- Initialize a sum variable to 0.
- Iterate through the array, adding elements to the sum only if they are greater than 0.
- Ensure negative numbers and zeros are ignored during the summation.

## function 5: `count_negative`

This function counts the number of negative integers in an array.

### plan
- Initialize a counter variable to 0.
- Iterate through the array, incrementing the counter whenever a negative number is encountered.
- Return the final count.
- This logic is pretty similar to my plan for `sum_positive`.

## the calculator program

The calculator program processes a sequence of arithmetic operations from a file.

### plan
1. Parse the first line of the file to initialize a running total (`long` type).
2. For subsequent lines, alternate between reading an operator and a number:
   - Apply the operator to the running total and the number.
   - Handle division carefully to avoid division by zero, outputting "ERROR" if such a case occurs.
3. Continue processing until the end of the file.
4. Output the final result, ensuring correctly formatted.

### design considerations/edge cases
- Use `strtol` for converting strings to `long` values, ensuring proper error handling for invalid input.
- Use a loop to manage alternating lines (operator/number), keeping track of the current operator.
- Validate input format
- Edge cases such as an empty file or invalid operators.