#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int percentile(int* matrix, int size, int n){
    int* temp_matrix = matrix;
    int temp = 0;
    for (int j = 0; j < size ; ++j) {
        for (int i = 0; i < size; ++i) {
            if(temp_matrix[j] < temp_matrix[i]){
                temp = temp_matrix[i];
                temp_matrix[i] = temp_matrix[j];
                temp_matrix[j] = temp;
            }
        }
    }
    double percentiel_rank = (float)n/100 * (float)size;
    (int)percentiel_rank != percentiel_rank ? percentiel_rank = (int)percentiel_rank + 1  : percentiel_rank ;

    return temp_matrix[(int)percentiel_rank - 1];
}


int main()
{
    int size_of_matrix;
    printf("Give me te size of the matrix\n");
    scanf("%d", &size_of_matrix);

    int* matrix = malloc(size_of_matrix * sizeof(int));

    for (int i = 0; i < size_of_matrix ; ++i) {
        scanf("%d", &matrix[i]);
    }

    printf("%d", percentile(matrix, size_of_matrix, 75));

    free(matrix);

    return 0;
}