#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// the resulting array should be 20 elements long
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* pointer_even = NULL;
    int* pointer_odd = NULL;

    pointer_even = malloc(10 * sizeof(int));
    pointer_odd = malloc(10 * sizeof(int));
    for (int i = 0; i < 10 ; ++i) {
        i % 2 == 0 ? (*(pointer_even + i) = i, *(pointer_odd + i) = (i + 1)) :
        (*(pointer_even + i) = (i + 1), *(pointer_odd + i) = i );
    }
    realloc(pointer_even, 20 * sizeof(int));
    for (int j = 10 ; j < 20 ; ++j) {
        *(pointer_even + j) = *(pointer_odd + (j - 10));
    }
    free(pointer_odd);

    int temp = 0;
    for (int k = 0; k < 20 ; ++k) {
        for (int i = 0; i < 20 ; ++i) {
            if(pointer_even[k] > pointer_even[i]){
                temp = pointer_even[i];
                pointer_even[i] = pointer_even[k];
                pointer_even[k] = temp;
            }
        }
    }
    for (int l = 0; l < 20 ; ++l) {
        printf("%d\n", pointer_even[l]);
    }

    free(pointer_even);

    return 0;
}