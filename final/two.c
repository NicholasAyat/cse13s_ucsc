#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_characters(char *text, char *toremove) {
  if (!text || !toremove) {
    return NULL;
  }

  size_t text_len = strlen(text);
  char *result = malloc(text_len + 1);  // +1 for null terminator
  if (!result) {
    return NULL;
  }

  size_t j = 0;  // Index for result string
  
  // For each character in text
  for (size_t i = 0; i < text_len; i++) {
    int should_keep = 1;  // true until proven false
    
    // Check if current char is in toremove
    for (size_t k = 0; toremove[k] != '\0'; k++) {
      if (text[i] == toremove[k]) {
        should_keep = 0;
        break;
      }
    }
    
    if (should_keep) {
      result[j++] = text[i];
    }
  }
  
  result[j] = '\0';  // Null terminate
  return result;
}