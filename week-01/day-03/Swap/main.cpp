#include <iostream>

int main() {
    int a = 123;
    int b = 526;
    int swap ;

    swap = a;
    a = b;
    b = swap;


    std::cout << a  << std::endl;
    std::cout << b  << std::endl;

    return 0;

}