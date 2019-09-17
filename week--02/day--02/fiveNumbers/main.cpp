#include <iostream>

int main(){
    int myArr[5];
    std::cout <<"I need fice numers" << std::endl;
    for (int i = 0; i < 5 ; ++i) {
        std::cin >> myArr[i];
    }
    for (int j = 0; j < 5 ; ++j) {
        std::cout << "The "<< j + 1 << " value is " << *(myArr + j) << std::endl;

    }


    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    return 0;
}