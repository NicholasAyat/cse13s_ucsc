# Homework 3: Design Document

  * author: *Nicholas Ayat* 
  * date: January 2025

## introduction

This design document for hw3 outlines my approach to solving the tasks in Homework 3, which involves working with strings, arrays, and function pointers. I will describe the purpose of each function, the methods I intend to use, and relevant considerations for ensuring correctness and efficiency.

## function 1: `str_suffix`

This function determines whether `needle` is a suffix of `haystack`.

### plan
- Determine the lengths of both strings.
- If `needle` is longer than `haystack`, return `false` immediately.
- Compare the last `length(needle)` characters of `haystack` with `needle`.
- Implement iteratively for efficiency.

## function 2: `str_repeat`

This function returns a newly allocated string that consists of `n` repetitions of `s`.

### plan
- Compute the total memory needed (`n * length(s) + 1` for null terminator).
- Allocate memory.
- Use a loop to copy `s` into the allocated memory `n` times.
- Return the allocated memory pointer.

## function 3: `string_is_palindrome`

This function checks if `s` is a palindrome while ignoring case, whitespace, and punctuation.

### plan
- Allocate a scratch space to store only alphanumeric characters in lowercase.
- Use two-pointer technique: compare characters from the start and end, moving inward.
- Free allocated memory before returning.
- Validate correctness with various test cases.

## function 4: `dot_product`

Computes the dot product of two float arrays of equal length.

### plan
- Initialize an accumulator variable to 0.
- Iterate over both arrays, summing up element-wise products.
- Return the accumulated sum.

## function 5: `reduce`

Implements a generic reduce function.

### plan
- Initialize accumulator with `initial` value.
- Iterate through the array, applying `f(accumulator, element)` for each element.
- Return the final accumulated value.

## function 6: `maximum_with_reduce`

Finds the maximum element in an array using `reduce`.

### plan
- Define a helper function that returns the larger of two integers.
- Call `reduce` with this function and `INT_MIN` as the initial value.

## function 7: `sum_positive_with_reduce`

Computes the sum of all positive elements using `reduce`.

### plan
- Define a helper function that adds an element to the accumulator only if it’s positive.
- Call `reduce` with this function and `0` as the initial value.