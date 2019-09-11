#include <iostream>

int main() {
    int firstNumber;
    int secondNumber;
    std::cout <<"I want two numbers!" << std::endl;
    std::cout << "First:" << std::endl;
    std::cin >> firstNumber;
    std::cout << "Second:" << std::endl;
    std::cin >> secondNumber;

    if (firstNumber > secondNumber) {
        std::cout << "First was bigger!" << std::endl;
    } else if (firstNumber < secondNumber){
        std::cout << "Second was bigger!" << std::endl;
           } else {
        std::cout << "I dunno?!" << std::endl;
    }

    return 0;

}