#include <iostream>

int main(int argc, char* args[]) {

    int number ;
    int multi = 1;
    int sum;
    std::cout << "Please give me a number to work with!" << std::endl;
    std::cin >> number;

    while(multi < 11) {
        sum = number * multi;
        std::cout << multi << " * " << number << " = " << sum << std::endl;
        multi = multi + 1;
    }

    return 0;
}