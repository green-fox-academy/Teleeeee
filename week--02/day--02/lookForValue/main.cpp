#include <iostream>

int lookForValue(int *arr, int size, int input){
    int temp = 0;
    for (int i = 0; i < size ; ++i) {
        if (*(arr + i) == input) {
            temp = i;
        }
    }
    if(input == *(arr + temp)) {
        return temp;
    } else{
        return -1;
    }
}


int main(){

    int number;
    std::cout << "if you give me a numer I will find it" << std::endl;
    std::cin >> number;


    int myArr[10] = {23, 45, 754, 342, 346, 675, 123, 896, 568, 453};
    int size = 10;

    std::cout << lookForValue(myArr, size, number);

    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return -1

    return 0;
}