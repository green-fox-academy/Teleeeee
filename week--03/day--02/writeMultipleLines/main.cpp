#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void writeIntoFile(std::string path, std::string parameter, int lines){
    std::ofstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        myFile.open(path);
        for(int i = 1; i <= lines; i++){
            myFile << parameter << std::endl;
        }
        myFile.close();

    }catch (std::ofstream::failure& e){
        std::cout << e.what() << std::endl;
    }



}


int main() {

    std::string str1 = "green apple";
    std::string path = "C:\\github\\Teleeeee\\week--03\\day--02\\writeMultipleLines\\cmake-build-debug\\5apple.txt";
    int lines = 9;

    writeIntoFile(path, str1, lines);



    return 0;
}