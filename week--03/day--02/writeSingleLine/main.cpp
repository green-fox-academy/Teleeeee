#include <iostream>
#include <fstream>
#include <string>

int main() {

    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream myFile;
    myFile.open("my-file.txt");
    myFile << "Levente Paplogo" << std::endl;

    return 0;
}