#include "hashtable.h"

HashTable *create_table(void) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    if (!table) {
        return NULL;
    }
    
    table->buckets = (Customer **)calloc(TABLE_SIZE, sizeof(Customer *));
    if (!table->buckets) {
        free(table);
        return NULL;
    }
    
    table->size = TABLE_SIZE;
    return table;
}

void free_customer(Customer *customer) {
    if (customer) {
        free(customer->email);
        free(customer->name);
        free(customer->favorite_food);
        free(customer);
    }
}

void free_table(HashTable *table) {
    if (!table) return;
    
    for (int i = 0; i < table->size; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            Customer *next = current->next;
            free_customer(current);
            current = next;
        }
    }
    
    free(table->buckets);
    free(table);
}

unsigned int hash(char *str) {
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % TABLE_SIZE;
}

Customer *create_customer(char *email, char *name, int shoe_size, char *favorite_food) {
    Customer *customer = (Customer *)malloc(sizeof(Customer));
    if (!customer) return NULL;
    
    customer->email = strdup(email);
    customer->name = strdup(name);
    customer->favorite_food = strdup(favorite_food);
    customer->shoe_size = shoe_size;
    customer->next = NULL;
    
    if (!customer->email || !customer->name || !customer->favorite_food) {
        free_customer(customer);
        return NULL;
    }
    
    return customer;
}

void add_customer(HashTable *table, char *email, char *name, int shoe_size, char *favorite_food) {
    unsigned int index = hash(email);
    
    // Check if customer already exists
    Customer *current = table->buckets[index];
    Customer *prev = NULL;
    
    while (current) {
        if (strcmp(current->email, email) == 0) {
            // Update existing customer
            Customer *new_customer = create_customer(email, name, shoe_size, favorite_food);
            if (!new_customer) return;
            
            new_customer->next = current->next;
            if (prev) {
                prev->next = new_customer;
            } else {
                table->buckets[index] = new_customer;
            }
            free_customer(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    // Add new customer
    Customer *new_customer = create_customer(email, name, shoe_size, favorite_food);
    if (!new_customer) return;
    
    new_customer->next = table->buckets[index];
    table->buckets[index] = new_customer;
}

Customer *lookup_customer(HashTable *table, char *email) {
    unsigned int index = hash(email);
    Customer *current = table->buckets[index];
    
    while (current) {
        if (strcmp(current->email, email) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void delete_customer(HashTable *table, char *email) {
    unsigned int index = hash(email);
    Customer *current = table->buckets[index];
    Customer *prev = NULL;
    
    while (current) {
        if (strcmp(current->email, email) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free_customer(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void list_customers(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Customer *current = table->buckets[i];
        while (current) {
            printf("email: %s\nname: %s\nshoesize: %d\nfood: %s\n\n",
                   current->email, current->name, current->shoe_size, current->favorite_food);
            current = current->next;
        }
    }
} 