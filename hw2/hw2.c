/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include "hw2.h"

int next_collatz_number(int n) {
    if (n % 2 == 0) {
        return n / 2;
    }
    return 3 * n + 1;
}

int count_collatz_steps(int n) {
    if (n == 1) {
        return 0;
    }
    
    int steps = 0;
    long current = n;
    
    while (current != 1) {
        current = next_collatz_number(current);
        steps++;
    }
    
    return steps;
}

int maximum(int *nums, int len) {
    if (len <= 0) {
        return 0;
    }
    
    int max = nums[0];
    for (int i = 1; i < len; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int sum_positive(int *nums, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}

int count_negative(int *nums, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] < 0) {
            count++;
        }
    }
    return count;
}