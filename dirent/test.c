#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void) {
  int array = 0;
  struct listing_template {
    char name[256];
    unsigned char type;
    unsigned int row;
    unsigned int level;
  } listing[50];

  DIR *dir;
  struct dirent *entry;
  dir = opendir("/Users/anne/Google Drive/Programming/C_playground/dirent/testdir");

  while ((entry = readdir(dir)) != NULL) {
    if(!strncmp(entry->d_name, ".", 256) ||
       !strncmp(entry->d_name, "..", 256)) {
      continue;
    }
    strcpy(listing[array].name, entry->d_name);
    listing[array].type = entry->d_type;
    listing[array].row = 0;
    listing[array].level = 0;
    array++;
  }
  closedir(dir);


  for(int i = 0; i < array; i++) {
    printf("%d %d %d %d %s\n", i, listing[i].type, listing[i].row, listing[i].level, listing[i].name);
  }

  return 0;
}


/*  DIR *dir;
  struct dirent *entry;
  dir = opendir("/Users/anne/Google Drive/Programming/C_playground/dirent/testdir");

  while ((entry = readdir(dir)) != NULL) {
    printf("%s\t%d\n", entry->d_name, entry->d_type);
  }
  closedir(dir);*/
