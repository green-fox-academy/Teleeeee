#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
    std::map <std::string, std::string> myMap {
            {"978-1-60309-452-8", "A Letter to Jo"},
            {"978-1-60309-459-7","Lupus"},
            {"978-1-60309-444-3","Red Panda and Moon Bear"},
            {"978-1-60309-461-0","The Lab"}
    };

    for (std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); it++ ) {  //Print all the key-value pairs in the following format
        std::cout << it->second << " (ISBN: " << it->first << ")" <<std::endl;
    }


    myMap.erase("978-1-60309-444-3");                                                               //Remove the key-value pair with key 978-1-60309-444-3

    for (std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); it++ ) {  //Remove the key-value pair with value The Lab
        if (it->second == "The Lab"){
            myMap.erase(it->first);
        }
    }

    myMap.insert(std::pair<std::string, std::string>("978-1-60309-450-4","They Called Us Enemy"));  //Add the following key-value pairs to the map
    myMap.insert(std::pair<std::string, std::string>("978-1-60309-453-5","Why Did We Trust Him?")); //Add the following key-value pairs to the map

    myMap.find("478-0-61159-424-8");

    std::string tempHelp = myMap.find("978-1-60309-453-5")->second;                                           //Print whether there is an associated value with key 478-0-61159-424-8 or not

    bool sizeTemp = tempHelp.empty() == 0;

    if(sizeTemp){
        std::cout<< "Found value" << std::endl;
    }else{
        std::cout << "There is no such value" << std:: endl;
    }


    std::cout << myMap.find("978-1-60309-453-5")->second << std::endl;                                        //Print the value associated with key 978-1-60309-453-5




}