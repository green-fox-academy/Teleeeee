#include <iostream>
#include <fstream>

int divideByZero(int x){
    try {
        if(x==0){
            throw std::string ("Fail!");
        }

    }catch (std::string exception) {
        std::cout << exception << std::endl;

    }

    return 10/x;


}

int main() {
    int number = 0;
    std::cout << divideByZero(number);
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0.
    // Solve the excercise using exceptions!
    // Hint: The try-catch block should be in main().

    return 0;
}