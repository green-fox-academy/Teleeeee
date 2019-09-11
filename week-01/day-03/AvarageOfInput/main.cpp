#include <iostream>

int main() {
    int a;
    int b;
    int c;
    int d;
    int e;

    std::cout << "Please specify 5 numbers for me!" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> e;

    double sum = a + b + c + d + e;
    double avarage = sum / 5;

    std::cout << "Sum:" << sum << "Avarage:" << avarage << std::endl;

    return 0;


}