#include "hw1.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
    return M_PI * radius * radius;
}

double area_of_ring(double outer_radius, double inner_radius) {
    return area_of_disk(outer_radius) - area_of_disk(inner_radius);
}

int bigger_minus_smaller(int a, int b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
    return (x >= lower_bound && x <= upper_bound);
}

int sum_of_greater_squares(int a, int b, int c) {
    // Square the values
    int a_squared = a * a;
    int b_squared = b * b;
    int c_squared = c * c;
    
    // Find the smallest square
    int smallest;
    if (a_squared <= b_squared && a_squared <= c_squared) {
        smallest = a_squared;
    } else if (b_squared <= a_squared && b_squared <= c_squared) {
        smallest = b_squared;
    } else {
        smallest = c_squared;
    }
    
    // Return sum of all squares minus the smallest
    return a_squared + b_squared + c_squared - smallest;
}
