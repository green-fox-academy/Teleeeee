#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server



// Write a function that returns the GET / POST request ratio.
double getPostRatio(std::vector<std::string> &allVector){
    double counterP = 0;
    double counterG = 0;
    for(int i = 0; i < allVector.size(); i++) {
        if(allVector[i].length() == 47){
            counterP++;
        } else if(allVector[i].length() == 46){
            counterG++;
        }
    }

    return counterG/counterP;

}

// Write a function that returns an array with the unique IP adresses.
std::vector<std::string> ipAddresses(std::vector<std::string> &allVector ){
    //cut out unnecessary parts
    for(int i = 0; i < allVector.size(); i++){
        allVector[i].erase(0, 27);
        allVector[i].erase(13,allVector[i].length() - 1);

    }

    //here only IP addresses in the Vector

    //delete duplicated addresses

    for(int k = 0; k < allVector.size(); k++){
        for(int n = k + 1; n < allVector.size(); ){
            if(allVector[k] == allVector[n] && k!=n){   //delete address which are same as k and
                allVector.erase(allVector.begin()+n);   //doesn't step so it will check the same n allVector[n] is diff. after the deletion
            }else{
                n++;                                    //only steps if didn't delete anything
            }
        }
    }


    //should be only single addresses in Vector

    return allVector;



}


int main() {
    std::ifstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    std::vector<std::string> allLines;

    try {
        myFile.open("log.txt");

        while(!myFile.eof()){
            std::string line;
            getline(myFile, line);
            allLines.push_back(line);
        }
        myFile.close();

    }catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    //prints out GET/POST ratio
    std::cout << getPostRatio(allLines) << std::endl;



    ipAddresses(allLines);

    //prints out all unique IP adresses
    for(int i = 0; i < allLines.size(); i++) {
        std::cout << allLines[i] << std::endl;
    }

    return 0;
}