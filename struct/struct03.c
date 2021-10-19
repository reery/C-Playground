#include <stdio.h>
#include <string.h>

typedef struct character {
    char * firstName;
    char * surName;
    char * gender;
    int age;
} character;

int main(void) {
    character slavko = {"Slavko", "Stanic", "M", 36};
    character anne = {"Anne", "Schumann", "W", 30};

    printf("%s %s is %i years old and %s (%ld bytes)\n", slavko.firstName, 
        slavko.surName, slavko.age, slavko.gender, sizeof(slavko));
    printf("%s %s is %i years old and %s (%ld bytes, strlen = %ld)\n", anne.firstName, 
        anne.surName, anne.age, anne.gender, 
        sizeof(*anne.surName) * strlen(anne.surName) + 1, strlen(anne.surName));

    return 0;
}