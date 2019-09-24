#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copyFile(std::string first, std::string second){
    std::ifstream myFileIn;
    std::ofstream myFileOut;
    myFileIn.open(first);
    myFileOut.open(second);
    myFileIn.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    bool succes = false;
    try {
        while (!myFileIn.eof()) {
            std::string str;
            getline(myFileIn, str);
            myFileOut << str << '\n';
            succes = true;
        }
        myFileIn.close();
        myFileOut.close();
    }catch (std::ofstream::failure& e){
        std::cout << e.what() << std::endl;

    }

    return succes;

}

int main() {

    std::string file1 = "myFile1.txt";
    std::string file2 = "myFile2.txt";

    std::cout << copyFile(file1, file2);

    return 0;
}