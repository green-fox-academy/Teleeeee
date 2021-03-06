#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_of_string(char str[]);
int length_of_string_with_loop(char str[]);
int same_strings(char first_str[], char second_str[]);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char str[50];
    char second_str[50];

    printf("Enter two strings!\n");
    gets(str);
    gets(second_str);

    printf("%d\n", length_of_string(str));
    printf("%d\n", length_of_string_with_loop(str));

    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    printf("%d\n", same_strings(str, second_str));

    return 0;
}

int length_of_string(char str[]){
    return strlen(str);
}

int length_of_string_with_loop(char str[]){
    int i;
    for (i = 0; str[i] != '\0' ; ++i);
    return i;
}

int same_strings(char first_str[], char second_str[]){
    if(strlen(first_str) != strlen(second_str) ) return 0;
    int temp = 0;
    for (int i = 0; i <= strlen(first_str) ; ++i) {
        temp = i;
        if (first_str[i] == second_str[0] || abs(first_str[i] - second_str[0]) == 32) {
            for (int j = 0; j <= strlen(second_str) ; ++j) {
                if (second_str[j] == '\0'){
                    return 1;
                }
                if(first_str[i] != second_str[j] && abs(first_str[i] - second_str[j]) != 32) {
                    break;
                }
                if(first_str[i] == second_str[j] || abs(first_str[i] - second_str[j]) == 32){
                    i++;
                }
            }
        }
        i = temp;
    }
}