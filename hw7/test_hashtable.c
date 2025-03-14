#include <assert.h>
#include "hashtable.h"

void test_create_table(void) {
    HashTable *table = create_table();
    assert(table != NULL);
    assert(table->size == TABLE_SIZE);
    assert(table->buckets != NULL);
    free_table(table);
}

void test_add_lookup_customer(void) {
    HashTable *table = create_table();
    
    // Test adding a new customer
    add_customer(table, "test@example.com", "Test User", 42, "Pizza");
    Customer *customer = lookup_customer(table, "test@example.com");
    assert(customer != NULL);
    assert(strcmp(customer->email, "test@example.com") == 0);
    assert(strcmp(customer->name, "Test User") == 0);
    assert(customer->shoe_size == 42);
    assert(strcmp(customer->favorite_food, "Pizza") == 0);
    
    // Test updating an existing customer
    add_customer(table, "test@example.com", "Updated User", 43, "Burger");
    customer = lookup_customer(table, "test@example.com");
    assert(customer != NULL);
    assert(strcmp(customer->name, "Updated User") == 0);
    assert(customer->shoe_size == 43);
    assert(strcmp(customer->favorite_food, "Burger") == 0);
    
    free_table(table);
}

void test_delete_customer(void) {
    HashTable *table = create_table();
    
    // Add and then delete a customer
    add_customer(table, "test@example.com", "Test User", 42, "Pizza");
    delete_customer(table, "test@example.com");
    Customer *customer = lookup_customer(table, "test@example.com");
    assert(customer == NULL);
    
    free_table(table);
}

void test_hash_collisions(void) {
    HashTable *table = create_table();
    
    // Add multiple customers (some might hash to the same bucket)
    add_customer(table, "user1@example.com", "User One", 42, "Pizza");
    add_customer(table, "user2@example.com", "User Two", 43, "Burger");
    add_customer(table, "user3@example.com", "User Three", 44, "Pasta");
    
    // Verify we can look up all customers
    Customer *customer1 = lookup_customer(table, "user1@example.com");
    Customer *customer2 = lookup_customer(table, "user2@example.com");
    Customer *customer3 = lookup_customer(table, "user3@example.com");
    
    assert(customer1 != NULL);
    assert(customer2 != NULL);
    assert(customer3 != NULL);
    
    assert(strcmp(customer1->name, "User One") == 0);
    assert(strcmp(customer2->name, "User Two") == 0);
    assert(strcmp(customer3->name, "User Three") == 0);
    
    free_table(table);
}

int main(void) {
    test_create_table();
    test_add_lookup_customer();
    test_delete_customer();
    test_hash_collisions();
    
    printf("All tests passed!\n");
    return 0;
} 