#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number" << std::endl;
    std::cin >> num;

    for (int i=1; i<=num; i = i + 2 ){
        for (int j=1; j<=i; j = j +2){
            std::cout << "*";
        }
        std::cout << "\n";
    }

}