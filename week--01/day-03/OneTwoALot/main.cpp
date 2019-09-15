#include <iostream>

int main() {

    int numberin;
    std::cout << "Please give me a number!" << std::endl;
    std::cin >> numberin;

    if (numberin <= 0) {
        std::cout << "Not enough!" << std::endl;
    } else if (numberin == 1 ) {
        std::cout << "One!" << std::endl;
    } else if (numberin == 2 ) {
        std::cout << "Two!" << std::endl;
    } else {
            std::cout << "A lot!" << std::endl;
    }

    return 0;
}