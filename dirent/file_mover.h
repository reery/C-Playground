#ifndef FILE_MOVER_H
#define FILE_MOVER_H
#define DEPTH_LIMIT 128
#define BUF_SIZE 2048

// Struct template.
struct listing_template {
  char name[256];
  unsigned char type;
  unsigned int row;
  unsigned int level;
};

int crawl_folder(struct listing_template listing);
void crawl(int *, int *, char *, char *, int *, int *, int *, struct listing_template listing);

#endif /* FILE_MOVER_H */
