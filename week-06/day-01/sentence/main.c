#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void string_to_word(char arr[]);
void positions(char* charachter, int positions[], char arr[]);

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];
    scanf("%s",string);

    string_to_word(string);


    // create a function which takes a char array as a parameter and
    // lists all position where character 'i' is found


    char string_second_input[55] = "This is a string for testing";
    char *p;
    int arr[100] = {};
    *p = 'i';

    positions(p, arr, string_second_input);

    for(int a = 0;;a++){
        if(arr[a] == 0){
            break;
        }
        printf("%d\n", arr[a]);
    }

    return(0);
}

void string_to_word(char arr[]){
    const char delim[] = ".";
    char* token;
    token = strtok(arr,delim);

    while(token != NULL){
        puts(token);
        token = strtok(NULL, delim);
    }
}

void positions(char* charachter, int positions[], char arr[]){
    int counter = 0;
    for(int i = 0; i < strlen(arr); i++ ){
        if(*charachter == arr[i]){
            positions[counter] = i;
            counter++;
        }
    }
}