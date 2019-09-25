#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

std::string ticTacResult(std::string fileName){
    std::vector<std::string> temp;
    std::string result;
    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open(fileName);
        std::string text;
        while(!myFile.eof()) {
            getline(myFile, text);
            temp.push_back(text);
        }
        myFile.close();

    }catch(const std::string &e){
        std::cout << e << std::endl;
    }
    for(int i = 0; i < 3; i++) {
        if (temp[0].find('O', i)  == i && temp[1].find('O', i)  == i &&  temp[2].find('O', i) == i ) {
            result = "O";
            break;
        }
        if (temp[0].find('X', i)  ==  temp[1].find('X', i)  ==  temp[2].find('X', i) ) {
            result =  "X";
            break;
        }
        if(temp[i].find("XXX", 0) == 0 || temp[i].find("XXX", 0) == 0 || temp[i].find("XXX", 0) == 0 ) {
            result = "X";
            break;
        }
        if(temp[i].find("OOO", 0) == 0 || temp[i].find("OOO", 0) == 0 || temp[i].find("OOO", 0) == 0 ) {
            result = "O";
            break;
        }else{
            result = "draw";
            break;
        }
    }
    return result;


}

int main() {


    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("win-o.txt");
    // should print O

    std::cout << ticTacResult("win-x.txt");
    // should print X

    std::cout << ticTacResult("draw.txt");
    // should print draw

    return 0;
}