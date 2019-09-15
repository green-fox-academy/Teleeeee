#include <iostream>

int main() {
    double mile;
    std::cout << "Distance in mile:" << std::endl;
    std::cin >> mile;

    double km = mile * 1.6;

    std::cout << "Distance in km: " << km << std::endl;

    return 0;


}