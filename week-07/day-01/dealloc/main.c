#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;
    pointer = malloc(10 * sizeof(int));

    for (int i = 0; i < 10 ; ++i) {
        i % 2 == 0 ? (*(pointer + i) = i) : (*(pointer + i) = (i + 1)) ;
        printf("%d\n", *(pointer + i));
    }

    free(pointer);

    return 0;
}