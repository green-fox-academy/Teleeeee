#include <iostream>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

int main ()
{
    // Create a function which swaps the values of 'a' and 'b' variables.
    // This time use a void function and pointers.

    int a = 10;
    int b = 316;

    swap(&a, &b);

    std::cout<< a << " " << b;

    return 0;
}