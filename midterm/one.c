#include "midterm.h"

long long *factorial_numbers(size_t n) {
    // Allocate array of size n
    long long *result = calloc(n, sizeof(long long));
    if (!result) {
        return NULL;
    }
    
    // First two numbers are always 1
    result[0] = 1;  // 0! = 1
    if (n > 1) {
        result[1] = 1;  // 1! = 1
    }
    
    // Calculate remaining factorials iteratively
    for (size_t i = 2; i < n; i++) {
        result[i] = result[i-1] * i;
    }
    
    return result;
}