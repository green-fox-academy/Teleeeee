#include <iostream>
#include <string>
int factorio(int factorial, int& value );
int main(int argc, char* args[]) {

    int yourNumber = 0;
    int a = 0;
    std::cout << "Give me a number under 13";
    std::cin >> yourNumber;
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    factorio(yourNumber,a);
    std::cout << a;



    return 0;
}

int factorio( int factorial, int& value){ //calculates factorial
    value = 1;
    for (int i = 1; i <= factorial ; i++) {
        value = i * value;
    }

}