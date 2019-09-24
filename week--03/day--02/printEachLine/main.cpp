#include <iostream>
#include <fstream>
#include <string>

int main () {

    std::ifstream myFileReading;
    myFileReading.open("my-file.txt");
    std:: string str;
    while (!myFileReading.eof()) {
        getline(myFileReading, str);
        std::cout << str << std::endl;
    }
    myFileReading.close();

    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file first.

    return 0;
}