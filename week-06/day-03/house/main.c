#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct house{
    char* address;
    int price;
    float number_of_rooms;
    float area_square_meters;
}house_t;

int worth_buying(house_t* house_p){
    float value = 400 * house_p->area_square_meters;
    if(value > 80000){
        return 0;
    }else{
        return 1;
    }
}

int how_many_worth_buying(house_t* houses, int size){
    int counter = 0;
    for (int i = 0; i < size ; ++i) {
        if(worth_buying(&houses[i]) == 1){
            counter++;
            printf("The number of this house is %d and it's worth buying\n ", i);
        }else{
            printf("The number of this house is %d and it does not worth buying\n ", i);
        }
    }
    return counter;
}

int main()
{
    house_t first_house = {"home",0,5,100};
    house_t second_house = {"home",0,2,150};
    house_t third_house = {"home",0,6,50};
    house_t fourth_house = {"home",0,8,8900};
    house_t fifth_house = {"home",0,9,10000};

    house_t list_to_evalate[5] = {first_house,second_house,third_house,fifth_house,fourth_house};

    printf("%d",how_many_worth_buying(list_to_evalate, 5));

    return 0;
}