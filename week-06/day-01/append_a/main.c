#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_a(char str[]){
    char append_it = 'a';
    str[strlen(str)] = append_it;
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char str_input[100] = {};
    printf("Enter a string:\n");
    scanf("%s", str_input);

    append_a(str_input);

    printf("%s", str_input);

    return 0;
}