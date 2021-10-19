#include <stdio.h>
#include "file_mover.h"

struct listing_template listing[DEPTH_LIMIT];

int main(void){
  int array = 0;

  puts("Starting main program...\n");

  array = crawl_folder(listing);

  for(int i = 0; i < array; i++) {
    printf("%d %d %d %d %s\n", i, listing[i].type, listing[i].row, listing[i].level, listing[i].name);
  }

  return 0;
}
