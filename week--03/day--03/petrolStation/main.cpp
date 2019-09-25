#include <iostream>
#include "cmake-build-debug/station.h"
#include "cmake-build-debug/car.h"

int main() {

    station myStation(100);

    car first(0, 10);
    car second(20, 25);
    car third(6, 15);
    car fourth(4, 5);
    car fifth(3, 15);

    std::cout << first.isFull() << std::endl;

    myStation.fill(first);
    std::cout << first.isFull() << std::endl;
    myStation.fill(second);
    std::cout << second.isFull() << std::endl;
    myStation.fill(third);
    std::cout << third.isFull() << std::endl;
    myStation.fill(fourth);
    std::cout << fourth.isFull() << std::endl;
    myStation.fill(fifth);
    std::cout << fifth.isFull() << std::endl;








}