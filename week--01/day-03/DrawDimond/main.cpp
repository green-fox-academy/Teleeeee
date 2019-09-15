#include <iostream>

int main() {

    int i, j, k, l, m;
    int num ;

    std::cout << "Input:";
    std::cin >> num;

    for( i = 1 ; i < num ; i++) //set conditions according to lines
    {
        for( j = num ; j >= i; j--)
        {
            std::cout << " ";
        } //set spacing before
        for(j= 1 ; j <= i ; j++)
        {
            std::cout << " *";
        }
        std::cout <<std::endl;
    } //outer loop

    for ( k = 0; k <= num - 1; k++)
    { // lower triangel
        for(l = 0; l <= k ; l++)//for spaces
        {
            std::cout << " ";

        }
        for(m = num   ; m  >= k +1  ; m--)
        {
            std::cout << " *";

        }
        std::cout << std::endl;

    }
}


/*
    int input;
    std::cout << "number here pls!\n";
    std::cin >> input;

    int lineWidth = input;
    for (int i = 0; i < input ; ++i) {
        int m = input / 2;
        int k = abs(m-i);
        for (int j = 0; j < input ; ++j) {
            if(j >= k && j < input - k){
                std::cout << "*";
            }else{
                std::cout << " ";
            }

        }
        std::cout << std:: endl;
    }

    }
*/