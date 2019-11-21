#include <stdio.h>

float GetTrickyAvg(int* matrix, int size){
    if(size == 0)return 0;
    int smallest_odd_number = matrix[0];
    int largest_even_number = 0;
    float  avarage = 0;
    for (int i = 0; i < size ; ++i) {
            if(matrix[i] > largest_even_number && matrix[i]%2 == 0){
                largest_even_number = matrix[i];
            }
            if(matrix[i] < smallest_odd_number && matrix[i]%2 != 0) {
                smallest_odd_number = matrix[i];
            }
    }
    avarage = ((float)(float)largest_even_number + (float)smallest_odd_number)/ 2.0f;
    return avarage;
}

int main() {
    int arr[6] = {-5, 3, 34344, 0, 122, -555};
    printf("%f", GetTrickyAvg(arr, 6));
    return 0;
}