#include<stdio.h>



int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int first_number = 22;
    int second_number = 13;

    printf("%d\n", first_number  + second_number);
    printf("%d\n", second_number + first_number);
    printf("%d\n", first_number  - second_number);
    printf("%d\n", first_number  * second_number);
    printf("%d\n", second_number % first_number);

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    printf("Input 3 sides\n");
    scanf("%lf", &a );
    scanf("%lf", &b );
    scanf("%lf", &c );
    printf("Surface Area: %lf\n", 2*(a * b + a * c + b * c) );
    printf("Volume: %lf", a * b * c  );

    return 0;
}