#include <iostream>

void biggest(int *arr, int size){
    int biggestNumbIndex;
    for (int j = 0; j < size ; ++j) {
        if (*(arr + j) >= *arr) {
            biggestNumbIndex = j;
        }
    }

    std::cout << arr[biggestNumbIndex] << "  " <<  &arr[biggestNumbIndex] << std::endl;


}

int main()
{

    int inputNumber;

    std::cout << "Tell me how many number do you want to store" << std::endl;
    std::cin >> inputNumber;

    int myArray[inputNumber];
    std::cout << "Now enter as many as you wanted to." << std::endl;
    for (int i = 0; i < inputNumber ; ++i) {
        std::cin >> myArray[i];
    }

    biggest(myArray, inputNumber);

    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality

    return 0;
}

