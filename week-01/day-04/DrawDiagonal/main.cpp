#include <iostream>

int main(){
    int dia = 1;
    std::cout << "number pls!";
    std::cin >> dia;

    for(int sor = 1; sor <= dia ; sor++) {
        if (sor == 1 || sor == dia) {
            for (int b = 1; b <= dia; b++) {
                std::cout << "%";
            }
            std::cout << std::endl;
        } else {
            std::cout << "%";
            for( int oszlop = 2; oszlop <= dia - 1; oszlop++ ){
                if (sor == oszlop ){
                    std::cout << "%";
                } else std::cout <<" ";
            }
            std::cout << "%" << std::endl;
        }

    }
    return 0;
}