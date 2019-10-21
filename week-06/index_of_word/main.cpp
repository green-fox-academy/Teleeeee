#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int is_in_sentence(char word[], const char sentence[]){
    char delim = ' ';
    char delim_second = '.';
    int counter = 0;
    for (int i = 0; i < strlen(sentence) ; ++i) {
        if(sentence[i] == delim) counter +=1;
        if(sentence[i] == word[0] || abs(sentence[i] - word[0]) == 32 ){
            int temp = i;
            for (int j = 0; j <= strlen(word) ; ++j) {
                if (word[j] == '\0' && (sentence[i] == delim || sentence[i] == delim_second)){
                    return counter;
                }
                if(sentence[i] == word[j] || abs(sentence[i] - word[j]) == 32){
                    i++;
                }
            }i = temp;
        }
    }
    return 0;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char* word = "doctor";
    const char* sentence = "An apple a day keeps the doctor away.";

    // the output should be: 6
    printf("%d",is_in_sentence(word, sentence));

    return 0;
}