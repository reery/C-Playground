#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "file_mover.h"

int crawl_folder(struct listing_template listing){
  int total_items = 0;
  int files = 0;
  int folders = 0;
  int total_folders_to_crawl = 1;
  int levels = 0;
  char next_folder[BUF_SIZE] = "";
  int i = 0;
  char basedir[BUF_SIZE] = "/Users/anne/Google Drive/Programming/C_playground/dirent/testdir/";
  printf("DEBUG: listing in crawl_folder = %d %d %d %d %s\n", i, listing[i].type, listing[i].row, listing[i].level, listing[i].name);


  for(total_folders_to_crawl = 1; total_folders_to_crawl > 0; total_folders_to_crawl--){
    crawl(&files, &total_items, basedir, next_folder, &folders, &levels, &total_folders_to_crawl, listing);
  }

  printf("total_items in function crawl_folder: %d\n", total_items);
  printf("files: %d\n", files);
  printf("folders: %d\n", folders);

  return total_items;
}


void crawl(int *files, int *total_items, char *basedir, char *next_folder, int *levels, int *folders, int *total_folders_to_crawl, struct listing_template listing){
  printf("DEBUG: starting crawl-function.\n");
  DIR *dir;
  struct dirent *entry;
  int i = 0;
  char buf[BUF_SIZE];
  printf("DEBUG: basedir=%s\n", basedir);
  printf("DEBUG: next_folder=%s\n", next_folder);
  snprintf(buf, sizeof(buf), "%s%s", basedir, next_folder);
  printf("DEBUG: dir = %s\n", buf);
  printf("DEBUG: listing in crawl = %d %d %d %d %s\n", i, listing[i].type, listing[i].row, listing[i].level, listing[i].name);

  dir = opendir(buf);

  while ((entry = readdir(dir)) != NULL) {
    puts("DEBUG: readdir successful\n");
    if(!strncmp(entry->d_name, ".", BUF_SIZE) ||
       !strncmp(entry->d_name, "..", BUF_SIZE)) {
      continue;
    }
    printf("DEBUG: entry->d_name = %s\n", entry->d_name);
    strcpy(listing[*total_items].name, entry->d_name);
    listing[*total_items].type = entry->d_type;

    if(listing[*total_items].type == 4){
      *folders = *folders + 1;
    } else if(listing[*total_items].type == 8){
      *files = *files + 1;
    }

    listing[*total_items].row = 0;
    listing[*total_items].level = 0;
    *total_items = *total_items + 1;
    printf("DEBUG: total_items = %d, folders = %d, files = %d\n", *total_items, *folders, *files);

  }
  puts("DEBUG: closing directory\n");
  closedir(dir);

  //total_folders_to_crawl = total_folders_to_crawl - 1 + folders;
  total_folders_to_crawl = 0;

  return;
}
