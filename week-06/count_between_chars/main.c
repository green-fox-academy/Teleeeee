#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char word[], char between_this){
    int first_apparance = 0;
    int second_apparance = 0;
    for (int i = 0; i <= strlen(word) ; ++i) {
        if(word[i] == between_this ){
            first_apparance = i;
            for (int j = i + 1; j < strlen(word) ; ++j) {
                if(word[j] == between_this) {
                    second_apparance = j;
                    break;
                }
            }
            break;
        }
    }
    if(second_apparance > first_apparance){
        return second_apparance - first_apparance - 1;
    }else{
        return 0;
    }
}

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')

    printf("%d",count_between_chars(word, 'g'));

    return 0;
}