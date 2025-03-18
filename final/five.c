#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to insert a word and count into a tree
static WordCountTree *insert_word(WordCountTree *tree, char *word, size_t count) {
  if (!tree) {
    WordCountTree *new_node = calloc(1, sizeof(WordCountTree));
    if (!new_node) return NULL;
    
    new_node->word = strdup(word);
    new_node->count = count;
    return new_node;
  }
  
  int cmp = strcmp(word, tree->word);
  if (cmp < 0) {
    tree->left = insert_word(tree->left, word, count);
  } else if (cmp > 0) {
    tree->right = insert_word(tree->right, word, count);
  } else {
    tree->count += count;
  }
  
  return tree;
}

// Helper function to traverse a tree and insert all its nodes into another tree
static WordCountTree *copy_tree(WordCountTree *dest, WordCountTree *src) {
  if (!src) {
    return dest;
  }
  
  // Process current node
  dest = insert_word(dest, src->word, src->count);
  
  // Process children
  dest = copy_tree(dest, src->left);
  dest = copy_tree(dest, src->right);
  
  return dest;
}

WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {
  WordCountTree *result = NULL;
  
  // Copy all nodes from tree1
  result = copy_tree(result, tree1);
  
  // Copy and merge all nodes from tree2
  result = copy_tree(result, tree2);
  
  return result;
}