#include <stdio.h>
#include <string.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    char arr[256] = {'\0'};
    printf("Give me your full name and age\n");
    gets(arr);

    char* first_name;
    char* last_name;
    int age;
    char* token = strtok(arr, " ");
    for (int i = 0; i < 3 ; ++i) {
        switch (i){
            case 0 :
                first_name = token;
                break;
            case 1:
                last_name = token;
                break;
            case 2:
                age = (token[0] - '0') * 10 + (token[1] - '0') ;
                break;
        }
        token = strtok(NULL, " ");
    }

    printf("Your name is: %s lol %s and you are %d years old", first_name, last_name, age);

    return 0;
}