#ifndef FILEIO_H
#define FILEIO_H

#include "hashtable.h"

// File operations
void load_customers(HashTable *table, const char *filename);
void save_customers(HashTable *table, const char *filename);

#endif // FILEIO_H 