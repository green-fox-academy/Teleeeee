#include <iostream>
#include <string>
int main(int argc, char* args[]) {

    int a = 1;

    std::string insteadofnumber = "";

    while ( a < 101 ) {
        if ( (a % 3 == 0) && (a % 5 == 0)) {
            insteadofnumber = "FizzBuzz";
            std::cout << insteadofnumber << std::endl;
        } else if (a % 5 == 0) {
            insteadofnumber = "Buzz";
            std::cout << insteadofnumber << std::endl;
        } else if ( a % 3 == 0 ) {
            insteadofnumber = "Fizz";
            std::cout << insteadofnumber << std::endl;
        } else {
            std::cout << a << std::endl;
        }
        a = a + 1;

    }

    return 0;
}