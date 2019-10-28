#include <stdio.h>
#include <stdlib.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char*string_repeater(char* string, int repeat){
    int size = 0;
    while (string[size] != '\0'){ size++;}
    char* temp = malloc(((size * repeat)) * sizeof(char));
    int i = 0;
    for (int k = 0; k < repeat; k++) {
        if(i == size ){i = 0;}
        for (; i < size; ++i) {
            temp[(size * k) + i] = string[i];
        }

    }
    temp[repeat * size ] = '\0';
    return temp;

}

int main()
{
    char* string = "OnionFruit";
    char* multiplied = string_repeater(string, 5);
    printf("%s", multiplied);

    return 0;
}