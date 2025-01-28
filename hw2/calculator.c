#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;

  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }
  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }

  // Read initial value
  if (!fgets(buffer, BUFSIZE, infile)) {
    fclose(infile);
    return 1;
  }
  remove_newline(buffer, BUFSIZE);
  
  char *endptr;
  long result = strtol(buffer, &endptr, 10);
  
  // Process operations
  while (fgets(buffer, BUFSIZE, infile)) {
    remove_newline(buffer, BUFSIZE);
    
    // Read operator
    char operator = buffer[0];
    
    // Read next number
    if (!fgets(buffer, BUFSIZE, infile)) {
      break;
    }
    remove_newline(buffer, BUFSIZE);
    
    long num = strtol(buffer, &endptr, 10);
    
    // Perform operation
    switch (operator) {
      case '+':
        result += num;
        break;
      case '-':
        result -= num;
        break;
      case '*':
        result *= num;
        break;
      case '/':
        if (num == 0) {
          printf("ERROR\n");
          fclose(infile);
          return 0;
        }
        result /= num;
        break;
    }
  }
  
  printf("%ld\n", result);
  fclose(infile);
  return 0;
}