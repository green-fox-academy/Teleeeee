#include <stdio.h>
#include <stdlib.h>

int prime_number(int input);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int input;

    scanf("%d", &input);

    printf("%d", prime_number(input));

    return 0;
}

int prime_number(int input){
    int counter = 0;
    for (int i = 2; i <= input / 2 ; ++i) {
        if(input % i == 0){
            counter++;
            break;
        }
    }
    if(counter == 0 && input !=1){
        return  1;
    }else{
        return  0;
    }
}