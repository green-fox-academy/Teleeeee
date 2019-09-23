#include <iostream>

int main(){

    int inputNumber;

    std::cout << "Tell me how many number do you want to store" << std::endl;
    std::cin >> inputNumber;

    int myArray[inputNumber];

    std::cout << "Now enter as many as you wanted to." << std::endl;
    for (int i = 0; i < inputNumber ; ++i) {
        std::cin >> myArray[i];
    }

    int biggestNumbIndex;
    int absoluteHighest = 0;

    for (int j = 0; j < inputNumber ; ++j) {
            if (*(myArray + j) >= absoluteHighest) {
                absoluteHighest = *(myArray+j);
                biggestNumbIndex = j;
            }
        }
    std::cout << myArray[biggestNumbIndex] << "  " <<  &myArray[biggestNumbIndex] << std::endl;


    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    return 0;
}