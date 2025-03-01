# Homework 6: Design Document

  * author: *Nicholas Ayat* 
  * date: February 2025

## introduction

This document outlines the design approach for implementing a Wordle solver. The solver will iteratively suggest words based on heuristic scoring, refining the vocabulary at each step based on game feedback. Efficient data structures and memory management will be crucial for performance and correctness.

## function implementations

### 1. `int compute_letter_score(char letter, char **vocabulary, int vocab_size)`
- Computes the score of a letter based on its occurrence in the remaining vocabulary.
- Plan:
  - Iterate over vocabulary and count words containing `letter`.
  - Return the count.

### 2. `int compute_word_score(char *word, char **vocabulary, int vocab_size)`
- Computes the heuristic score of a word by summing the unique letter scores.
- Plan:
  - Use `compute_letter_score` for each unique letter in `word`.
  - Sum the scores and return.

### 3. `char *find_best_guess(char **vocabulary, int vocab_size)`
- Identifies the word with the highest heuristic score.
- Plan:
  - Iterate over vocabulary and compute `compute_word_score` for each word.
  - Track and return the highest-scoring word.

### 4. `void filter_vocabulary(char **vocabulary, int *vocab_size, char *guess, char *feedback)`
- Filters words from the vocabulary based on game feedback.
- Plan:
  - Iterate through vocabulary.
  - Apply rules for 'x' (gray), 'y' (yellow), and 'g' (green) responses.
  - Free memory of eliminated words and set pointers to NULL.
  - Update `vocab_size` accordingly.

### 5. `void free_vocabulary(char **vocabulary, int vocab_size)`
- Frees all allocated memory for vocabulary.
- Plan:
  - Iterate through `vocabulary` and free each non-NULL entry.
  - Free the vocabulary array itself.

## memory management strategy
- All word strings are dynamically allocated; must be freed properly.
- `filter_vocabulary` must avoid dangling pointers.
- `valgrind --leak-check=full ./solver` will be used for leak detection.

## testing plan
- Create comprehensive test cases in `search_util_test.c`.
- Ensure `compute_word_score` ranks words correctly.
- Verify `filter_vocabulary` correctly removes invalid words.
- Check for memory leaks and stability under edge cases.