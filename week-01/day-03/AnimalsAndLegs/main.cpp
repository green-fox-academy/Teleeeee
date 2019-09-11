#include <iostream>

int main() {
    int NumberOfChickens;
    int NumberOfPigs;

    std::cout << "How many chickens does the farmer have?" << std::endl;
    std::cin >> NumberOfChickens;
    std::cout << "How many pigs does the farmer have?" << std::endl;
    std::cin >> NumberOfPigs;

    int NumberOfChikenlegs = NumberOfChickens * 2;
    int NumberOfPiglegs = NumberOfPigs * 4;
    int AllLegs = NumberOfChikenlegs + NumberOfPiglegs;

    std::cout << "There are " << AllLegs << " legs on that farm!" << std::endl;

    return 0;
}