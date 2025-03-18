#include "final.h"

#include <stdio.h>

// Helper function to find the maximum depth of the tree
static size_t find_max_depth(BinaryTree *tree) {
  if (!tree) {
    return 0;
  }
  
  size_t left_depth = find_max_depth(tree->left);
  size_t right_depth = find_max_depth(tree->right);
  
  return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

// Helper function to sum values at a specific depth
static int sum_at_depth(BinaryTree *tree, size_t current_depth, size_t target_depth) {
  if (!tree) {
    return 0;
  }
  
  if (current_depth == target_depth) {
    return tree->val;
  }
  
  return sum_at_depth(tree->left, current_depth + 1, target_depth) +
         sum_at_depth(tree->right, current_depth + 1, target_depth);
}

int sum_values_at_max_depth(BinaryTree *tree) {
  if (!tree) {
    return 0;
  }
  
  size_t max_depth = find_max_depth(tree) - 1;  // Convert to 0-based depth
  return sum_at_depth(tree, 0, max_depth);
}