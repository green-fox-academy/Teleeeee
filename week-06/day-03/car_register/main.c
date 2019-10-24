#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum TRANSMISSION{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH,
};

typedef struct car{
    char manufacturer_name[256];
    float price_in_euro;
    int year_of_manufactur;
    enum TRANSMISSION type_of_transmission;
}car_t;



int get_older_cars_than(struct car* array, int array_length, int age){
    int counter = 0;
    for (int i = 0; i < array_length ; ++i) {
        if( (2019 - array[i].year_of_manufactur) > age){
            counter++;
            printf("The %d. car is older than  %d\n", i, age);
        }else{
            printf("The %d. car is younger than  %d\n", i, age);
        }
    }
    return  counter;
}

int get_transmission_count(struct car* array, int array_length, enum TRANSMISSION trnsm){
    int counter = 0;
    for (int i = 0; i < array_length ; ++i) {
        if( array[i].type_of_transmission == trnsm){
            counter++;
            printf("The %d. car has the same transmission\n", i);
        }else{
            printf("The %d. car doesn't have the same transmission\n", i);
        }
    }
    return  counter;
}

int main()
{
    car_t first_car = {"Volvo", 400, 1989, MANUAL};
    car_t second_car = {"Audi", 1200, 2004, AUTOMATIC};
    car_t third_car = {"Tatra", 50, 1968, DUAL_CLUTCH};
    car_t fourth_car = {"Trabant", 10, 1979, MANUAL};
    car_t fifth_car = {"Volkswagen", 800, 2000, MANUAL};

    car_t garage[5] = {first_car, second_car, third_car, fourth_car, fifth_car};

    printf("%d\n", get_older_cars_than(garage, 5, 30));
    printf("%d\n", get_transmission_count(garage, 5, MANUAL));


    return 0;
}