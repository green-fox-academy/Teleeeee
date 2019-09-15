#include <iostream>
#include <string>
using namespace std;

int swap(int& i, int& j);

int main(int argc, char* args[]) {



    int a = 15;
    int b = 23;
    cout << a << b << endl;

    swap ( a, b);

    cout << a << b << endl;



    // Create two integer variables: a=15, b=23
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.

    return 0;
}

int swap(int& i, int& j){
    int temp = 1;
    temp = i;
    i = j;
    j = temp;


}