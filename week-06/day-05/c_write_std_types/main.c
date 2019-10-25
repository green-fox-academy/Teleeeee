#include <stdio.h>
#include <stdint.h>

int main() {
    int myInt = 123456789;
    float myFloat = 3.14159265359F;
    char myChar = 'c';

    int myIntRead;
    float myFloatRead;
    char myCharRead;

    FILE* file_out_text;
    file_out_text = fopen("myInt.txt", "w");
    fprintf(file_out_text, "%d", myInt);
    fclose(file_out_text);


    FILE* file_out_bin;
    file_out_bin = fopen("myInt.bin", "wb");
    fwrite(&myInt, sizeof(int), 1, file_out_bin);
    fclose(file_out_bin);;

    file_out_bin = fopen("myChar.bin", "wb");
    fwrite(&myChar, sizeof(char), 1, file_out_bin);
    fclose(file_out_bin);

    FILE* file_in_bin;
    file_in_bin = fopen("myInt.bin", "rb");
    fread(&myIntRead, sizeof(int), 1, file_in_bin);
    fclose(file_in_bin);

    file_in_bin = fopen("myChar.bin", "rb");
    fread(&myCharRead, sizeof(char), 1, file_in_bin);
    fclose(file_in_bin);

    FILE* file_out_float;
    file_out_float = fopen("myFloat.bin","wb");
    fwrite(&myFloat, sizeof(float), 1, file_out_float);
    fclose(file_out_float);

    FILE* file_in_float;
    file_in_float = fopen( "myFloat.bin", "rb");
    fread(&myFloatRead, sizeof(int), 1, file_in_bin);
    fclose(file_in_float);

    printf("My int: %d , My Float : %f, My Char : %c\n", myInt, myFloat, myChar);
    printf("My int: %d , My Float : %lf, My Char : %c", myIntRead, myFloatRead, myCharRead);

    /*
     * 1. Write out myInt to myInt.txt as a text!
     * 2. Write out myInt to myInt.bin as a binary file!
     *    Check the size of myInt.txt and myInt.bin! Why it is different?
     * 3. Write out myInt to myInt.bin, myFloat to myFloat.bin and myChar to myChar.bin!
     * 4. Read them back to myIntRead, myFloatRead and myCharRead and compare these variables to myInt, myFloat, myChar,
     *    they should be the same.
     */

    return 0;
}