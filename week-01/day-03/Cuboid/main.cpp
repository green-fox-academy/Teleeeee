#include <iostream>

int main() {
    double a = 0.30;
    double b = 0.15;
    double c = 0.10;
    double SurfaceArea =  2*(a * b + a * c + b * c);
    double VolumeofCuboid = a * b * c;

    std::cout << "Surface Area:" << SurfaceArea << std::endl;
    std::cout << "Volume:" << VolumeofCuboid << std::endl;

    return  0;

}