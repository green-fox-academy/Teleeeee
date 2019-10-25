#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void write_word_times(char* filename, char* word, int line_count){
    FILE* file_write_to;
    file_write_to = fopen(filename, "w");

    for (int i = 0; i < line_count ; ++i) {
        if(i != line_count - 1) {
            fprintf(file_write_to, "%s\n", word);
        }else{
            fprintf(file_write_to, "%s", word);
        }
    }

}

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file
int count_lines(char* filename){
    char temp_string[256] = {'\0'};
    int line_counter = 1;
    FILE* file_in;
    file_in = fopen(filename,"r");
    if(file_in == NULL){
        return 0;
    }
    while (fgets(temp_string, 256,file_in) != NULL){}
    for (int i = 0; i < 256 ; ++i) {
        if(temp_string[i] == '\n'){
            line_counter++;
        }
    }
    return line_counter;
}

int main ()
{

    write_word_times("file_times_written.txt","I love bacon", 5);

    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    FILE* file_out;

    file_out = fopen("my_file.txt","w");
    fputs("Paplogo Levente", file_out);

    fclose(file_out);

    return 0;


    printf("%d", count_lines("my_file.txt") );

    return 0;

    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, for that you may use C-programming, although it is not mandatory


    FILE* file_in;
    file_in = fopen("my_file.txt","r");
    if(file_in == NULL){
        printf("There is a problem with opening the file");
    }

    int c;

    while ((c = fgetc(file_in)) > 0){
        printf("%c\n", c );
    }

    fclose(file_in);


    return 0;
}