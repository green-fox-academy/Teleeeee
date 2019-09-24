#include <iostream>

int* findMinimum(int *arr, int size){
    int temp;
    temp = *arr;
    int flag = 1;
    //int* minPtr = arr;
    for (int i = 0; i < size; ++i) {
        if(temp > arr[i]){
            temp = arr[i];
            flag = i;
            //minPtr = &arr[i];
        }
    }
    return (arr+flag);
    //return minPtr;
}


int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = 7;
    std::cout << findMinimum(numbers, size);


    return 0;
}