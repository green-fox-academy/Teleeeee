#include <iostream>
#include <string>

int sum(int);


int main(int argc, char* args[53435]) {

    int yourNumb;
    std::cout << "give me a number"<< std::endl;
    std::cin >> yourNumb;

    std::cout << "The sum from 0 to your number is " << sum(yourNumb);




    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    return 0;
}

int sum( int yourNumber ){
    int sum = 0;
    for (int i = 1; i <= yourNumber ; ++i) { // DO NOT try to count from yourNumber to 0
        sum += i;
    }
    return sum;
}
