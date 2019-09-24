#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        myFile.open("reversed-lines.txt");
        std::string word;
        while (std::getline(myFile, word)) {
            int tokenLenght = word.length();
            std::string temp = word;
            std::string actualltemp = "";
            for (int i = 0; i < tokenLenght ; i++) {
                actualltemp[0] = word[0];
                temp[i] = word[tokenLenght - i];
            }
            temp.append(1, actualltemp[0]);
            temp.erase(0,1 );
            std::cout << temp<< std::endl;
        }

    }catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }


    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    return 0;
}


//std::istringstream ss(word);
//std::string token;
//while (std::getline(ss, token, ' '))