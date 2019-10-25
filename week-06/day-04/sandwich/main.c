#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct sandwich{
    char* name;
    float price;
    float weight;
} sandwich_t;

float price_of_your_order(sandwich_t sandwich, int number_of_sandwiches){
    return sandwich.price*number_of_sandwiches;
}

int main()
{
    sandwich_t first_sandwich;
    first_sandwich.name = "Lajos";
    first_sandwich.price = 1.5f;
    first_sandwich.weight = 0.1f;

    printf("%0.2f",(price_of_your_order(first_sandwich, 5)));

    return 0;
}