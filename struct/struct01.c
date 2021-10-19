#include <stdio.h>
#define MAX_POS 8

struct files {
  int size;
  char name[256];
};

void add_name(struct files files_array1, int*);
void add_size(struct files files_array1, int*);
void print_struct(struct files files_array1, int*);


int main(void){
  struct files files_array[MAX_POS];
  int position = 0;
  char answer, ch;

  add_size(&files_array, &position);
  add_name(&files_array, &position);

  do{
    puts("Do you want to add more (y/n)? ");
    answer = getchar();
    while((ch = getchar()) != '\n'){
      continue;

    if(answer == 'y' && position <= MAX_POS){
      position++;
      add_size(&files_array, &position);
      add_name(&files_array, &position);
    } else if(position > MAX_POS){
      printf("You can't add more than %d.\n", MAX_POS);
      break;
    }
    } while (answer == 'y')
  }

  print_struct(&files_array, &position);

  return 0;
}

void add_name(struct files files_array1, int *position){
  puts("Please add a name: ");
  scanf("%s", files_array1[*position].name);
}

void add_size(struct files files_array1, int *position){
  puts("Please add a size: ");
  scanf("%d", &files_array1[*position].size);
}

void print_struct(struct files files_array1, int *position){
  for(int i = 0; i <= *position; i++){
    printf("Name: %s\nSize: %d\n", files_array1[i].name, files_array1[i].size);
  }
}
