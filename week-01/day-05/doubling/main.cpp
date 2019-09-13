#include <iostream>
#include <string>



int doubling( int& x) {
    x = 2 * x;

    std::cout << x << std::endl;

}


int main(int argc, char* args[]) {

    int baseNum = 123;

    doubling(baseNum);

    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    return 0;
}
