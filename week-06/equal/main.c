#include <stdio.h>
#include <stdlib.h>

int is_equal(int first, int second)
{
    if(first == second ){
        return  1;
    }
    else{
        return 0;
    }
}


int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int firstInput;
    int secondInput;

    scanf("%d", &firstInput);
    scanf("%d", &secondInput);

    printf("%d", is_equal(firstInput,secondInput));

    return 0;
}