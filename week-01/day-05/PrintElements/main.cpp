#include <iostream>
#include <string>

int main(int argc, char* args[]) {


    int numbers[] = {4, 5, 6, 7};

    for (int i = 0; i < sizeof(numbers)/ sizeof(numbers[1]) ; i++) {
        std::cout << numbers[i] << "\n";

    }


    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    return 0;
}