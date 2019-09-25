#include <iostream>
#include <vector>
#include <map>

#include "cmake-build-debug/dominoes.h"

std::vector<Domino> initializeDominoes()
{
    std::vector<Domino> dominoes;
    dominoes.push_back(Domino(5, 2));
    dominoes.push_back(Domino(4, 6));
    dominoes.push_back(Domino(1, 5));
    dominoes.push_back(Domino(6, 7));
    dominoes.push_back(Domino(2, 4));
    dominoes.push_back(Domino(7, 1));
    return dominoes;
}

int main(int argc, char* args[])
{
    std::vector<Domino> dominoes = initializeDominoes();
    // You have the list of Dominoes
    // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
    // eg: [2, 4], [4, 3], [3, 5] ...


    std::map<int, int> myPair;
    int a =1;
    int counter = 0;

    while (counter < 6) {
        int k = 0;
        for (; k < dominoes.size(); k++) {
            if (dominoes[a].getValues().second == dominoes[k].getValues().first) {
                std::cout << dominoes[k].toString();
                a = k;
                counter++;
            }
        }
    }

    return 0;
}