#include <iostream>

int main() {
    int number;
    std::cout << "Give me a number please!" << std::endl;
    std::cin >> number;

    int odd = number / 2;

    if ( odd == 0)
    {
        std::cout << "Even!" << std::endl;
    }else {
        std::cout << "Odd!" << std::endl;
    }

    return 0;
}