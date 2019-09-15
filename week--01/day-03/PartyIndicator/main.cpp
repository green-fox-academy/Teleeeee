#include <iostream>

int main() {
    int girls;
    int guys;

    std::cout << "How many girl are here?" << std::endl;
    std::cin >> girls;
    std::cout << "How many guys are here?" << std::endl;
    std::cin >> guys;

    int all = guys + girls;

    if(girls >= guys && all >= 20) {
        std::cout << "The party is excellent!" << std::endl;
    } else if(girls != guys && all >= 20 && girls > 0){
        std::cout << "Quite cool party!" << std::endl;
    } else if (girls == 0) {
        std::cout << "Sausage party" << std::endl;
    } else if (all < 20) {
        std::cout << "Average party..." << std::endl;

    }

    return 0;
}