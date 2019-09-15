#include <iostream>
#include <string>


int main( int argc, char* args[]) {
    int a = 3;
    a = 3 + 9;
    std::cout << a << std::endl;

    int b = 100;
    b-=7;
    std::cout << b << std::endl;

    int c = 44;
    c = c + c;
    std::cout << c << std::endl;

    int d = 125;
    d = d / 5;
    std::cout << d << std::endl;

    int e = 8;
    e = e * e * e;
    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
    bool f = f1 > f2;
    std::cout << f << std::endl;

    int g1 = 350;
    int g2 = 200;
    bool g = (g2 * g2) > g1 ;
    std::cout << g << std::endl;

    int h = 135798745;
    bool divisor = (h % 11) == 0 ;
    std::cout << divisor << std::endl;

    int i1 = 10;
    int i2 = 3;
    bool i = (i2 * i2) < i1 < (i2 * i2 * i2);
    std::cout << i << std::endl;

    int j = 1521;
    if (j % 3 !=0){
        std::cout << "divadable by 3"<< std::endl;
    } else if (j % 5 !=0) {
        std::cout << "divadable by 5"<< std::endl;

    } else{
        std::cout << 0 << std::endl;
    }



    return 0;
}