#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int where_is_the_character(char str[], char character);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    char str_input[100];
    char character_input;

    printf("Enter a character to find it's index and enter a string which I should look for: \n");
    scanf("%s", &character_input);
    scanf("%s", str_input);

    printf("%d", where_is_the_character(str_input,character_input));

    return 0;
}

int where_is_the_character(char str[], char character){
    int index_number = -1;
    for (int i = 0; i <= strlen(str) ; ++i) {
        if(str[i] == character){
            index_number = i;
            break;
        }
    }
    return index_number;
}