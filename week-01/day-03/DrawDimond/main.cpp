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
        } //for steric
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