#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void split_to_words(char* arr){
    char delim[2] = " ";
    char* word = strtok(arr, delim);
    while(word != NULL ){
        printf("%s\n", word);
        word = strtok(NULL, delim);
    }
}

int main()
{
    printf("Type in a sentence:\n");
    char string[256];
    gets(string);
    split_to_words(string);

    return(0);
}