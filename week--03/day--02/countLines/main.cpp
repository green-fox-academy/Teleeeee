#include <iostream>
#include <exception>
#include <string>
#include <fstream>


int numberOfLines(std:: string str){

    std::ifstream myFile;
    int counter = 0;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open(str);
        std::string inn;
        while (!myFile.eof()){
            getline(myFile, inn);
            counter++;
        }
        myFile.close();


    }catch (std::ifstream::failure &e){
        return 0;
    }

    return counter;


}

int main () {

    std::string filename = "text.txt";

    std::cout << numberOfLines(filename);


    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file.

    return 0;
}