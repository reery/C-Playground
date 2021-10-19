#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Functin prototype
int print_file_edit_menu(char *);
void print_file_contents(FILE *);
void edit_file(FILE *);
void get_filename(char *, int);

// Global variables
const int char_limit = 120;
const int max_filename_length = 64;

int main(void) {
  char filename[max_filename_length];
  int selected_menu_option;
  FILE * fp;

  get_filename(filename, max_filename_length);

  while(1) {
    selected_menu_option = print_file_edit_menu(filename);

    switch (selected_menu_option) {
      case 1:
        puts("Deleting file and start from the beginning.");
        if( (fp = fopen(filename, "w+")) != NULL) {
          puts("Starting a new file.");
          edit_file(fp);
          fclose(fp);
        } else {
        printf("Cannot read the file '%s'. OK? ", filename);
        while( getchar() != '\n') ;
        }
        break;
      case 2:
        puts("Opening the file to append.");
        if( (fp = fopen(filename, "a+")) != NULL) {
          puts("Appending to file.");
          edit_file(fp);
          fclose(fp);
        } else {
        printf("Cannot read the file '%s'. OK? ", filename);
        while( getchar() != '\n') ;
        }
        break;
      case 3:
        if( (fp = fopen(filename, "r")) != NULL) {
          puts("Printing contents of file:");
          print_file_contents(fp);
          fclose(fp);
        } else {
        printf("Cannot read the file '%s'. OK? ", filename);
        while( getchar() != '\n') ;
        }
        break;
      case 4:
        get_filename(filename, max_filename_length);
        break;
      case 5:
        puts("Quitting.");
        exit(EXIT_SUCCESS);
        break;
      default:
        puts("Strange error. Aborting.");
        exit(EXIT_FAILURE);
        break;
    }
  }

  return 0;
}


int print_file_edit_menu(char * filename) {
  char menu_option;
  char ch;
  int menu_option_int;

  printf("What do you want to do with the file ""%s""?\n", filename);
  puts("1) Rewrite         2) Append  ");
  puts("3) Show contents   4) Change input file");
  puts("5) Quit");

  while(1) {
    scanf("%c", &menu_option);
    menu_option_int = atoi(&menu_option);

    if( menu_option_int <= 5 && menu_option_int >= 1 && isdigit(menu_option) ) {
      while( getchar() != '\n') ;

      return menu_option_int;
    } else {
      fputs("Please choose between the numbers 1 and 5: ", stdout);
      while( getchar() != '\n') ;
    }
  }

  puts("Wrong input. Meh. Aborting.");
  return 5;
}


void print_file_contents(FILE * fp) {
  rewind(fp);
  char ch[char_limit];

  while( (fgets(ch, char_limit, fp)) != NULL ) {
    fputs(ch, stdout);
  }

  fputs("End of file. OK? ", stdout);
  while( getchar() != '\n' ) ;
  return;
}


void edit_file(FILE * fp) {
  puts("You can add content so the file. Finish with an empty line.");
  char buffer[char_limit];

  while( fgets(buffer, char_limit, stdin) && buffer[0] != '\n' ) {
    fputs(buffer, fp);
  }
}


void get_filename(char filename[max_filename_length], int max_filename_length) {
  char ch;

  fputs("File to open: ", stdout);

  while( fgets(filename, char_limit, stdin) ) {
    if( isspace(filename[0]) ) {
      fputs("Cannot use such a filename. Try again: ", stdout);
      continue;
    }

    filename[strlen(filename) - 1] = '\0';
    return;
  }

  return;
}
