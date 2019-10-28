#include <stdio.h>
#include <stdlib.h>

// Please use the realloc function where applicable!
// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int x;
    int sum = 0;
    int* pointer = NULL;
    printf("Please enter a number :");
    scanf("%d", &x);
    pointer = malloc(x* sizeof(int));
    printf("Now fill in those variables with numbers:");
    for (int i = 0; i < x ; ++i) {
        int k;
        scanf("%d", &k);
        *(pointer + i) = k;
        sum +=k;
    }
    realloc(pointer, sum * sizeof(int));
    for (int j = 0; j < sum ; ++j) {
        pointer[j] = 1;
    }
    for (int l = 0; l < sum ; ++l) {
        printf("%d\n", *(pointer + l));
    }
    free(pointer);

    return 0;
}