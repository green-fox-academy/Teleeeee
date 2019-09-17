#include <iostream>

int findMinimum(const int *arr, int size){
    int temp;
    int * ptrTemp = &temp;
    temp = *arr;
    int flag;
    for (int i = 0; i < size; ++i) {
        if(temp > arr[i]){
            temp = arr[i];
            flag = i;
        }
    }


    return *(arr + flag);

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