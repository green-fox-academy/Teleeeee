#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char* word, char* sentence ){
    int temp = 0;
    char delim = ' ';
    char delim_second = '.';
    for (int i = 0; i <= strlen(sentence) ; ++i) {
        temp = i;
        if (sentence[i] == word[0] || sentence[i] - 32 == word[0] || sentence[i] == word[0] - 32) {
            for (int j = 0; j <= strlen(word) ; ++j) {
                if (word[j] == '\0' && (sentence[i] == delim || sentence[i] == delim_second)){
                    return 1;
                }
                if(sentence[i] == word[j] || sentence[i] - 32 == word[0] || sentence[i] == word[0] - 32){
                    i++;
                }
            }
        }
        i = temp;
    }
    return 0;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return 1 if the given sentence contains the given word
    // and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "keeps";
    char *sentence = "An ApPle a day keeps the doctor away.";

    // the output should be: 1
    printf("%d",is_in_sentence(word, sentence));

    return 0;
}