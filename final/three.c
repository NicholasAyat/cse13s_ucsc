#include "final.h"

#include <stdio.h>

int apply_many_times(int (*func)(int), int x, size_t n) {
  int result = x;
  
  // Apply the function n times
  for (size_t i = 0; i < n; i++) {
    result = func(result);
  }
  
  return result;
}