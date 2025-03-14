#include "fileio.h"
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Helper function to check if a string contains tabs
static int contains_tab(const char *str) {
    while (*str) {
        if (*str == '\t') return 1;
        str++;
    }
    return 0;
}

void load_customers(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *email, *name, *shoe_size_str, *food;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline if present
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        // Parse fields using strtok
        email = strtok(line, "\t");
        name = strtok(NULL, "\t");
        shoe_size_str = strtok(NULL, "\t");
        food = strtok(NULL, "\t");

        if (email && name && shoe_size_str && food) {
            int shoe_size = atoi(shoe_size_str);
            add_customer(table, email, name, shoe_size, food);
        }
    }

    fclose(file);
}

void save_customers(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return;
    }

    for (int i = 0; i < table->size; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            fprintf(file, "%s\t%s\t%d\t%s\n",
                    current->email,
                    current->name,
                    current->shoe_size,
                    current->favorite_food);
            current = current->next;
        }
    }

    fclose(file);
} 