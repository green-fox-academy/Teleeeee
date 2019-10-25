#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void position_i(char* arr){
    for (int i = 0; i < strlen(arr) ; ++i) {
        if(arr[i] == 'i'){
            printf("%d\n", i);
        }
    }
}

int main ()
{
    char string[55] = "This is a string for testing";
    char *p;

    position_i(string);

    return 0;
}