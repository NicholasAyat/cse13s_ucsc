#include "final.h"
#include <stdio.h>

size_t count_increasing_columns(int **matrix, size_t rows, size_t cols) {
  if (!matrix || rows < 2) {
    return 0;
  }

  size_t increasing_count = 0;

  // For each column
  for (size_t col = 0; col < cols; col++) {
    int is_increasing = 1;  // true until proven false
    
    // Check each element in the column with its previous
    for (size_t row = 1; row < rows && is_increasing; row++) {
      if (matrix[row][col] <= matrix[row - 1][col]) {
        is_increasing = 0;
      }
    }
    
    if (is_increasing) {
      increasing_count++;
    }
  }

  return increasing_count;
}