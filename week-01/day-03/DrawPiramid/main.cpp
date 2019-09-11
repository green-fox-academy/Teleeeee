#include <iostream>

int main() {

    int num;
    std::cout << "give me a number to work with" << std::endl;
    std::cin >> num;
    for ( int i = 0; i < num; i++ )
    {
        for (int j= (num + 1) - i ; j > 0 ; j--)
            std::cout << " ";
        for( int a = 0; a < i * 2 + 1; a++)
            std::cout << "*";
        std::cout<< std::endl;

    }

    return 0;
}