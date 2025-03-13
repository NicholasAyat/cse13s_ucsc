# Homework 7: Design Document

  * author: *Nicholas Ayat* 
  * date: March 2025

## Introduction

We will design and implement a customer database using hash tables in C. The database will support operations such as adding, looking up, deleting, listing, and saving customer data. Each customer has an email address (unique key), name, shoe size, and favorite food. Data will be stored and retrieved from a TSV file.

## Data Structure Design

### Customer Structure
Define a `Customer` struct to store customer data:

```c
typedef struct Customer {
    char *email;
    char *name;
    int shoe_size;
    char *favorite_food;
    struct Customer *next; // For handling collisions using linked lists
} Customer;
```

### Hash Table Structure
A hash table with separate chaining will be used:

```c
#define TABLE_SIZE 1000 // Chosen based on expected dataset size

typedef struct HashTable {
    Customer **buckets;
    int size;
} HashTable;
```

## Functional Design

### Hash Function
A simple hash function using djb2:

```c
unsigned int hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}
```

### Initialization
Create a hash table with `TABLE_SIZE` buckets, initializing each bucket to NULL.

```c
HashTable *create_table();
```

### Add Customer
If the email exists, update the existing customer. Otherwise, insert a new node.

```c
void add_customer(HashTable *table, char *email, char *name, int shoe_size, char *favorite_food);
```

### Lookup Customer
Find and return customer details based on email.

```c
Customer *lookup_customer(HashTable *table, char *email);
```

### Delete Customer
Find and remove a customer from the hash table, freeing allocated memory.

```c
void delete_customer(HashTable *table, char *email);
```

### List Customers
Iterate through all buckets and print stored customer details.

```c
void list_customers(HashTable *table);
```

### Load from File
Read `customers.tsv`, parse each line, and populate the hash table.

```c
void load_customers(HashTable *table, const char *filename);
```

### Save to File
Write the hash table contents to `customers.tsv` in TSV format.

```c
void save_customers(HashTable *table, const char *filename);
```

### Cleanup
Free all allocated memory, including customer entries and the hash table itself.

```c
void free_table(HashTable *table);
```

## Input Handling and Edge Cases

- Reject duplicate email addresses and update instead.
- Strip or replace tabs in user input to maintain TSV format integrity.
- Validate numerical input for shoe size.

## Memory Management & Debugging

- Use `malloc` and `free` properly to prevent leaks.
- Employ `Valgrind` for leak detection:
  
  ```sh
  valgrind --leak-check=full ./businessdb
  ```

## File Organization

- `main.c`: Handles user interaction.
- `hashtable.c`: Implements hash table functions.
- `hashtable.h`: Contains struct and function declarations.
- `fileio.c`: Handles file reading/writing.
- `fileio.h`: Contains function prototypes for file operations.
- `Makefile`: Builds the project with necessary flags.

## Testing Plan

- Implement `test_hashtable.c` to verify hash table operations.
- Create `test_fileio.c` to ensure correct file parsing and writing.
- Validate with a sample `customers.tsv` file.