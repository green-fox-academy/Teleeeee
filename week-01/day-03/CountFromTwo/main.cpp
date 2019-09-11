#include <iostream>

int main(int argc, char* args[]) {

    int firstnumber;
    int secondnumber;

    std::cout << "Please give me two numbers to work with \n First:" << std::endl;
    std::cin >> firstnumber;
    std::cout << "One more!" << std::endl;
    std::cin >> secondnumber;

    if(firstnumber >= secondnumber) {
        std::cout << "The second number should be bigger" << std::endl;
    }
    do {
        std::cout << firstnumber << std::endl;
        firstnumber = firstnumber + 1;
    } while(firstnumber < secondnumber);

    return 0;
}