#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> telephoneBook = {
        {"William A. Lathan","405-709-1865"},
        {"John K. Miller",	"402-247-8568"},
        {"Hortensia E. Foster",	"606-481-6467"},
        {"Amanda D. Newland",	"319-243-5613"},
        {"Brooke P. Askew",	"307-687-2982"},
    };
    std::cout << "K.Millers phone number is: " << telephoneBook.find("John K. Miller")->second << std::endl;      //What is John K. Miller's phone number
    for (std::map<std::string, std::string>::iterator it = telephoneBook.begin(); it !=telephoneBook.end(); it++ ) { // Whose phone number is 307-687-2982?
        if(it->second == "307-687-2982"){
            std::cout << it->first << std::endl;
        }
    }

    bool temp;

    for (std::pair<std::string, std::string> myPair : telephoneBook) {  //Do we know Chris E. Myers' phone number?
        if(myPair.first == "Chris E. Myers") {
            bool temp = true;
        }
    }if(temp){
        std::cout<< "we know Chris E. Myers" << std::endl;
    } else{
        std::cout << "we don't know Chris E. Myers" << std::endl;
    }


}