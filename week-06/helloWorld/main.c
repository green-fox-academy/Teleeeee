#include <stdio.h>

int main() {

    // Modify this program to greet you instead of the World!
    printf("Hello, me!\n");

    // Greet 3 of your classmates with this program, in three separate lines
    // like:
    //
    // Hello, Esther!
    // Hello, Mary!
    // Hello, Joe!
    char name[10] = "Esther";
    char name1[10] = "Mary";
    char name2[10] = "Joe";

    printf("Hello, %s!\n", name);
    printf("Hello, %s!\n", name1);
    printf("Hello, %s!\n", name2);

    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    char myName[10] = "Levente";
    int  myAge = 25;
    float myHeight = 1.71f;

    printf("%s\n", myName );
    printf("%d\n", myAge );
    printf("%.2f\n", myHeight);

    return 0;
}