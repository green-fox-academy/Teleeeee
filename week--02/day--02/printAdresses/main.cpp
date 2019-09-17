#include <iostream>

int main(){

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    int myArr[5] = {};
    std::cout << "Give me 5 numbers";
    for (int i = 0; i < 5 ; ++i) {
        std::cin >> myArr[i];
    }

    // print out the memory addresses of the elements in the array
    for (int j = 0; j < 5 ; ++j) {
        std::cout << "For the "<< j + 1 << " element the memory address is " <<&myArr[j] << std::endl;

    }

    return 0;
}