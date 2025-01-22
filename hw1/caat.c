#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a character is a vowel
bool is_vowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
    }
}

int main(void) {
    int c;
    
    // Read characters until EOF
    while ((c = getchar()) != EOF) {
        putchar(c);  // Output the character once
        
        // If it's a vowel, output it again
        if (is_vowel(c)) {
            putchar(c);
        }
    }
    
    return 0;
}
