#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Question one.
size_t count_increasing_columns(int **matrix, size_t rows, size_t cols);

// Question two.
char *remove_characters(char *text, char *toremove);

// Question three.
int apply_many_times(int (*func)(int), int x, size_t n);

// Question four.
typedef struct BinaryTree {
  int val;
  struct BinaryTree *left;
  struct BinaryTree *right;
} BinaryTree;

int sum_values_at_max_depth(BinaryTree *tree);

// Question five.
typedef struct WordCountTree {
  char *word;
  size_t count;
  struct WordCountTree *left;
  struct WordCountTree *right;
} WordCountTree;

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
