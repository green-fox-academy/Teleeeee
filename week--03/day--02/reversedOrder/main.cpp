#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    std::vector<std::string>  word;
    try {
        myFile.open("reversed-order.txt");
        std::string temp;


        while (!myFile.eof()) {
            getline(myFile, temp);
            word.push_back(temp);
        }

        myFile.close();

    }catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    for(int i = word.size() -1; i >=0 ; --i){
        std::cout << word[i] << std::endl;

    }

    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.
    return 0;
}