#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {

    std::ifstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        myFile.open("duplicated-chars.txt");
        std::string word;
        while (std::getline(myFile, word)) {
            std::istringstream ss(word);
            std::string token;
            while (std::getline(ss, token, ' ')) {
                for (int i = 0; i < token.length(); i++) {
                    if (token[i] == token[i + 1]) {
                        token.erase(i, 1);
                    }
                }
                std::cout << token << " ";
            }
        }
        myFile.close();

    }catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }




    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    return 0;
}