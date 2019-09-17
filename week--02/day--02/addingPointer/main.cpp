#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *ptrA = &a;
    int *ptrB = &b;

    *ptrA = *ptrA + *ptrB;

    std::cout << *ptrA;

    return 0;
}