#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int first, int second);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int firstInput;
    int secondInput;

    scanf("%d", &firstInput);
    scanf("%d", &secondInput);

    printf("%d", sum_of_digits(firstInput,secondInput));

    return 0;
}


int sum_of_digits(int first, int second)
{

    char buffer_first[50] = {};
    char buffer_second[50] = {};
    int first_sum = 0;
    int second_sum = 0;

    sprintf(buffer_first, "%d", first);
    sprintf(buffer_second, "%d", second);

    for (int i = 0; i < 50; ++i) {
        if(buffer_first[i] == '\0'){
            break;
        }
        else{
            first_sum = first_sum + (buffer_first[i] - '0');
        }
    }

    for (int i = 0; i < 50; ++i) {
        if(buffer_second[i] == '\0'){
            break;
        }
        else{
            second_sum = second_sum + (buffer_second[i] - '0');
        }
    }

    if(first_sum == second_sum){
        return 1;
    }else{
        return  0;
    }

}