#include "midterm.h"

#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {
    // Handle empty list
    if (!list) {
        return NULL;
    }
    
    // Remove nodes from start of list if needed
    while (list && list->value >= start && list->value <= end) {
        ll_float *temp = list;
        list = list->next;
        free(temp);
    }
    
    // Handle remaining nodes
    ll_float *current = list;
    while (current && current->next) {
        if (current->next->value >= start && current->next->value <= end) {
            ll_float *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    return list;
}