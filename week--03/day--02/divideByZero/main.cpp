#include <iostream>
#include <fstream>

int divideByZero(int x){
       if( x == 0) {
           std::cout << "fail!";
       }



    return 10/x;



}

int main() {

    int number =0;
    std::cout<< divideByZero(number);


    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0.
    // Solve the excercise without using exceptions!

    return 0;
}