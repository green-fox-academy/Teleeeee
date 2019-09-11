#include <iostream>

int main() {
    float a = 6; //hours coded daily
    float b = 17; // how many week long a semester is
    float c = 5; //workdays in a week
    float d = c * b * a;// hours coded on course
    float e = 52 * 17;
    std::cout << d << std::endl;
    std::cout << d / e * 100 << std::endl;

    return 0;
}