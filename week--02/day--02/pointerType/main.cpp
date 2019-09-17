#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *pointToA = &a;
    double *pointToB = &b;

    std::cout <<"At memory adress " << pointToA << " " << *pointToA << std::endl;
    std::cout <<"At memory adress " << pointToB << " " << *pointToB << std::endl;



    return 0;
}