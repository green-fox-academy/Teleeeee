#include <iostream>
#include "cmake-build-debug/Rectangle.h"

int main() {

    Rectangle rect1;

    rect1.setX1(5);
    rect1.setY1(5);
    rect1.setX2(10);
    rect1.setY2(10);

    Rectangle rect2(3, 5, 17, 10);


    std::cout << rect1.area() << std::endl;
    std::cout << rect2.area() << std::endl;

    return 0;
}