// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // Test score_letter
  printf("Testing score_letter:\n");
  printf("'a' appears in %d words\n", score_letter('a', vocabulary, num_words));
  printf("'z' appears in %d words\n", score_letter('z', vocabulary, num_words));

  // Test score_word
  printf("\nTesting score_word:\n");
  int letter_scores[26] = {0};
  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }
  printf("Score for 'stalk': %d\n", score_word("stalk", letter_scores));
  printf("Score for 'ether': %d\n", score_word("ether", letter_scores));

  // Test filter_vocabulary_gray
  printf("\nTesting filter_vocabulary_gray:\n");
  size_t removed = filter_vocabulary_gray('a', vocabulary, num_words);
  printf("Removed %zu words containing 'a'\n", removed);

  // Test filter_vocabulary_yellow
  printf("\nTesting filter_vocabulary_yellow:\n");
  removed = filter_vocabulary_yellow('t', 0, vocabulary, num_words);
  printf("Removed %zu words based on yellow 't'\n", removed);

  // Test filter_vocabulary_green
  printf("\nTesting filter_vocabulary_green:\n");
  removed = filter_vocabulary_green('e', 1, vocabulary, num_words);
  printf("Removed %zu words based on green 'e'\n", removed);

  // Clean up
  free_vocabulary(vocabulary, num_words);
  return 0;
}
