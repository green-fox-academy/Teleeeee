#include <iostream>
#include <string>

int main(int argc, char* args[]){
    std::string UserName;

    std::cout << "Please input your name!" << std::endl;
    std::cin >> UserName;

    std::cout << "Hello " << UserName << std::endl;

    return 0;
}