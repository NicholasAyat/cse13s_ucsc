#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct Customer {
    char *email;
    char *name;
    int shoe_size;
    char *favorite_food;
    struct Customer *next;
} Customer;

typedef struct HashTable {
    Customer **buckets;
    int size;
} HashTable;

// Hash table operations
HashTable *create_table(void);
void free_table(HashTable *table);
unsigned int hash(char *str);
void add_customer(HashTable *table, char *email, char *name, int shoe_size, char *favorite_food);
Customer *lookup_customer(HashTable *table, char *email);
void delete_customer(HashTable *table, char *email);
void list_customers(HashTable *table);

#endif // HASHTABLE_H 