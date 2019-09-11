#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a = 24;
    int mod2 = a%2;
    bool even = (mod2==0);
    int out = 0;

    if (even) {
        a + a;
        std::cout << "Added 1" << std::endl;
    }
    std::cout << out << std::endl;


    int b = 13;
    std::string out2 = "";

    if (  b < 20 && b > 10) {
        out2 = "Sweet!";
    } else if(b < 10 ){
        out2 = "Less!";
    } else if (b> 20){
        out2 = "More!";
    }

    std::cout << out2 << std::endl;

    int c = 123;
    int credits = 100;
    bool isBonus = false;

    if(credits >= 50 && isBonus == false ){
        c = c-2;
    }else if(credits < 50 && isBonus == false){
        c = c-1;
    }else if (isBonus == true){
        c = c + 0;
    }

    std::cout << c << std::endl;
    int d = 8;
    int time = 120;
    std::string out3 = "";

    if( d % 4 == 0 && time <= 200 ) {
        out3 = "check";
    } else if (time > 200){
        out3 = "Time out!";
    }else{
        out3 = "Run Forest Run";
    }

    std::cout << out3 << std::endl;



    return 0;
}

