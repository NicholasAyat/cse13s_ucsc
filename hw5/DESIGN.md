# Homework 5: Design Document

  * author: *Nicholas Ayat* 
  * date: February 2025

## introduction

This document outlines the approach to implementing a playable version of Wordle in C. The main focus will be on string manipulation, searching algorithms, and dynamic memory management. Special attention will be given to efficiently handling guesses, feedback processing, and ensuring proper memory cleanup.

## function implementations

### 1. `bool is_valid_guess(char *word)`
- This function checks if a guessed word is valid.
- Plan:
  - Ensure the word is exactly five characters long.
  - Verify that the word consists only of lowercase ASCII letters.
  - Check against the predefined list of valid words.
  - Return `true` if all conditions are met, `false` otherwise.

### 2. `void compare_guess(char *guess, char *secret, char *feedback)`
- This function generates feedback for a guessed word.
- Plan:
  - Initialize feedback with all gray (`'X'`) markers.
  - Mark exact matches (green `G`).
  - Mark misplaced matches (yellow `Y`), ensuring letters are not overcounted.
  - Return feedback as a string of five characters.

### 3. `void play_round(char *guess, char *secret)`
- This function handles a single round of gameplay.
- Plan:
  - Validate the guess using `is_valid_guess`.
  - Call `compare_guess` to generate feedback.
  - Print the result to the player.

### 4. `void game_loop()`
- This function runs the entire game session.
- Plan:
  - Choose a secret word randomly from the dictionary.
  - Loop until the player correctly guesses the word or exceeds a maximum number of attempts.
  - Collect user input, validate guesses, and provide feedback.

### 5. `void free_resources()`
- This function ensures that all dynamically allocated memory is freed.
- Plan:
  - Deallocate memory for stored words.
  - Ensure no memory leaks occur by testing with Valgrind.

## memory management
- Allocate memory dynamically where necessary, primarily for storing words and feedback.
- Use `malloc` for dynamic allocations and `free` all allocated memory before exiting.
- Test with `valgrind --leak-check=full ./wordle_game` to verify that no memory is leaked.

## potential hard mode implementation
- Track known letter constraints based on previous guesses.
- Warn the player if their guess contradicts known constraints.

## testing plan
- Verify word validation logic with a diverse set of test cases.
- Ensure feedback generation produces correct results for various input scenarios.
- Run extensive tests on memory allocation and deallocation to prevent leaks.