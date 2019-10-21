#include <stdio.h>

int main() {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8
    int guess_number = 0;
    int correct_number = 6;


    while(guess_number != correct_number){
        scanf("%d",&guess_number);
        if(guess_number < correct_number){
            printf("The stored number is higher\n");
        }
        if(guess_number > correct_number){
            printf("The stored number is lower\n");
        }
    }

    printf("Correct");


    return 0;
}