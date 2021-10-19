#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS_LENGTH 41
#define FILENAME "testfile.a"

int main(void) {
  char words[MAX_WORDS_LENGTH];
  FILE *fp;

  if( (fp = fopen(FILENAME, "a+")) == NULL ) {
    printf("Error while opening the file %s.", FILENAME);
    exit(EXIT_FAILURE);
  }

  puts("Plase type some words. Finish with a # as a first letter.");

  while( (fgets(words, 40, stdin)) && words[0] != '#' ) {
    //fprintf(fp, "%s\n", words);
    fputs(words, fp);
  }

  puts("Thank you. Contents of the file are now:");

  rewind(fp);

  while( fgets(words, 41, fp) != NULL ) {
    printf("%s", words);
  }

  if( (fclose(fp)) != 0 ) {
    printf("Error while closing the file %s.\n", FILENAME);
  }

  puts("Done.");

  return 0;
}
