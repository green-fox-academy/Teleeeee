#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int substr_checker(char first[], char second[]);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char str_input_first[100] = {};
    char str_input_second[100] = {};

    printf("Enter two strings");

    scanf("%s", str_input_first);
    scanf("%s", str_input_second);

    printf("%d", substr_checker(str_input_first,str_input_second));

    return 0;
}

int substr_checker(char first[], char second[]){
    if(strlen(first) < strlen(second)) return 0;
    if(strlen(first) == strlen(second)) return -1;
    int temp = 0;
    for (int i = 0; i <= strlen(first) ; ++i) {
        temp = i;
        if (first[i] == second[0] || abs(first[i] - second[0]) == 32) {
            for (int j = 0; j <= strlen(second) ; ++j) {
                if (second[j] == '\0'){
                    return 1;
                }
                if(first[i] != second[j] && abs(first[i] - second[j]) != 32) {
                    break;
                }
                if(first[i] == second[j] || abs(first[i] - second[j]) == 32){
                    i++;
                }
            }
        }
        i = temp;
    }
    return 0;
}