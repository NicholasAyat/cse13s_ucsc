/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool str_suffix(char *haystack, char *needle) {
    // Get lengths of both strings
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    
    // If needle is longer than haystack, it can't be a suffix
    if (needle_len > haystack_len) {
        return false;
    }
    
    // Compare the last needle_len characters of haystack with needle
    return strcmp(haystack + haystack_len - needle_len, needle) == 0;
}

char *str_repeat(char *s, int n) {
    int s_len = strlen(s);
    int total_len = s_len * n + 1;  // +1 for null terminator
    
    // Allocate memory for the result
    char *result = malloc(sizeof(char) * total_len);
    if (!result) return NULL;  // Handle allocation failure
    
    // Initialize first character as null terminator
    result[0] = '\0';
    
    // Copy string n times
    for (int i = 0; i < n; i++) {
        strcat(result, s);
    }
    
    return result;
}

bool str_is_palindrome(char *s) {
    int len = strlen(s);
    char *clean = malloc(len + 1);  // Allocate space for cleaned string
    if (!clean) return false;
    
    // Copy only alphanumeric chars to clean, converting to lowercase
    int j = 0;
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            clean[j++] = tolower(s[i]);
        }
    }
    clean[j] = '\0';
    
    // Check if palindrome
    int clean_len = strlen(clean);
    bool is_palindrome = true;
    for (int i = 0; i < clean_len/2; i++) {
        if (clean[i] != clean[clean_len-1-i]) {
            is_palindrome = false;
            break;
        }
    }
    
    free(clean);
    return is_palindrome;
}

float dot_product(float *vec_a, float *vec_b, int length) {
    float sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += vec_a[i] * vec_b[i];
    }
    return sum;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
    int accumulator = initial;
    for (int i = 0; i < length; i++) {
        accumulator = f(accumulator, nums[i]);
    }
    return accumulator;
}

// Helper functions for maximum_with_reduce and sum_positive_with_reduce
static int max_helper(int a, int b) {
    return (a > b) ? a : b;
}

static int sum_positive_helper(int acc, int val) {
    return acc + (val > 0 ? val : 0);
}

int maximum_with_reduce(int *nums, int length) {
    return reduce(nums, length, max_helper, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int length) {
    return reduce(nums, length, sum_positive_helper, 0);
}
