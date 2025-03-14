#include "hashtable.h"
#include "fileio.h"

#define MAX_INPUT 1024
#define DATABASE_FILE "customers.tsv"

// Helper function to safely get input without buffer overflow
static void get_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    } else {
        buffer[0] = '\0';
    }
}

// Helper function to check for tabs in input
static int validate_input(const char *input) {
    while (*input) {
        if (*input == '\t') return 0;
        input++;
    }
    return 1;
}

int main(void) {
    HashTable *table = create_table();
    if (!table) {
        fprintf(stderr, "Failed to create hash table\n");
        return 1;
    }

    // Load existing database
    load_customers(table, DATABASE_FILE);

    char command[MAX_INPUT];
    char email[MAX_INPUT];
    char name[MAX_INPUT];
    char food[MAX_INPUT];
    char shoe_size_str[MAX_INPUT];

    while (1) {
        printf("command: ");
        get_input(command, sizeof(command));

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            printf("email address? ");
            get_input(email, sizeof(email));
            if (!validate_input(email)) {
                printf("Error: Input cannot contain tab characters\n");
                continue;
            }

            printf("name? ");
            get_input(name, sizeof(name));
            if (!validate_input(name)) {
                printf("Error: Input cannot contain tab characters\n");
                continue;
            }

            printf("shoe size? ");
            get_input(shoe_size_str, sizeof(shoe_size_str));
            int shoe_size = atoi(shoe_size_str);

            printf("favorite food? ");
            get_input(food, sizeof(food));
            if (!validate_input(food)) {
                printf("Error: Input cannot contain tab characters\n");
                continue;
            }

            add_customer(table, email, name, shoe_size, food);
        } else if (strcmp(command, "lookup") == 0) {
            printf("email address? ");
            get_input(email, sizeof(email));

            Customer *customer = lookup_customer(table, email);
            if (customer) {
                printf("email: %s\nname: %s\nshoesize: %d\nfood: %s\n",
                       customer->email, customer->name, customer->shoe_size, customer->favorite_food);
            } else {
                printf("user not found!\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("email address? ");
            get_input(email, sizeof(email));

            Customer *customer = lookup_customer(table, email);
            if (customer) {
                delete_customer(table, email);
            } else {
                printf("user not found!\n");
            }
        } else if (strcmp(command, "list") == 0) {
            list_customers(table);
        } else if (strcmp(command, "save") == 0) {
            save_customers(table, DATABASE_FILE);
        } else {
            printf("unknown command\n");
        }
    }

    free_table(table);
    return 0;
} 