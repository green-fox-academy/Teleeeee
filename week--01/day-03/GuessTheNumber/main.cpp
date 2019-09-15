#include <iostream>

int main(int argc, char* args[]){


    int good = 3;
    int guess;

    std::cout << "Guess the number!" << std::endl;


    do{ std::cout << "Give me a number";
        std::cin >> guess;
        if( guess < good){
            std::cout << "The stored number is higher \n";
        }else if(guess > good) {
            std::cout << "The stored number is lower\n";
        } else {
            std::cout << "You found the number:\n" << guess << std::endl;
        }

    }while(guess != good);

    return 0;
}