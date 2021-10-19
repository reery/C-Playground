#include <stdio.h>

struct person {
  char name[30];
  int age;
};

void print_humans(struct person *human);
void check_age(struct person *human, int, int);

int main(void) {
  struct person human[] = {"Joe", 25, "Sal", 30};

  print_humans(human);
  fputs("What age is Sal now? ", stdout);
  check_age(human, 1, 80);
  print_humans(human);

  return 0;
}


// FUNCTIONS
void print_humans(struct person *human) {
  printf("Person 1: %s\t%p\tAge: %d\t%p\n", human[0].name, &human[0].name, human[0].age, &human[0].age);
  printf("Person 1: %s\t%p\tAge: %d\t%p\n", human[1].name, &human[1].name, human[1].age, &human[1].age);

  return;
}

void check_age(struct person *human, int position, int max_age) {
  int result;
  char ch;

  do{
    result = scanf("%i", &human[position].age);
    while((ch = getchar()) != '\n')
      continue;

    if(result == 1 && human[position].age <= max_age) {
      return;
    } else {
      fputs("Please type a number: ", stdout);
    }
  } while(1);

  return;
}
