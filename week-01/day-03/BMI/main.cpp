#include <iostream>

int main() {
    double massInKg = 81.2 ;
    double heightInM = 178 ; // height in cm
    double BMI = massInKg/ ((heightInM*heightInM)/10000) ;

    std::cout << BMI << std::endl;

    return 0;

}