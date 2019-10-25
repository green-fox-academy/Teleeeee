#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

void print_car_stats(struct car car){
    if(car.type != 3){
        printf("Kilometer in the car: %f\n" "Gas in the car: %f\n" "Type of the car: %d\n", car.km, car.gas, car.type );
    }
    if(car.type == 3){
        printf("Kilometer in the car: %f\n" "Type of the car: %d\n", car.km, car.type );
    }
}

int main()
{
    struct car first_car;
    struct car second_car;
    first_car.type = TOYOTA;
    first_car.gas = 100;
    first_car.km = 500000.00;
    second_car.type = TESLA;
    second_car.gas = 200;
    second_car.km = 560000.00;

    print_car_stats(first_car);
    print_car_stats(second_car);

    return 0;
}