#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char*func( char* first, char* second, int size_first, int size_second){

    char* pointer = calloc((size_first + size_second ), sizeof(char) );
    for (int i = 0; i < (size_first + size_second ) ; ++i) {
        if(i >= size_first) {
            pointer[i] = second[i - size_first];
        }else{
            pointer[i] = first[i];
        }
    }
    return pointer;
}

int main()
{
    char string[11] =  "What's up ";
    char string_other[8] =  "Levente";
    char* sum = NULL;

    sum = func(string, string_other, strlen(string), strlen(string_other));

    printf("%s", sum);

    free(sum);


    return 0;
}