#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Question one.
long long *factorial_numbers(size_t n);

// Question two.
typedef struct ll_float {
  float value;
  struct ll_float *next;
} ll_float;

ll_float *delete_range(ll_float *list, float start, float end);

// Question three.
size_t count_strings_with_property(bool (*property)(char *), char **strings,
                                   size_t len);

// Question four.
typedef struct {
  int shoe_size;
  int customer_id;
  int num_purchases;
} ShoeCustomer;

void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
