#include <stdio.h>

#define DISTANCE 345


int main()
{
    // Modifiy this program to print out the number we want

    printf("%d\n", 65);

    int seconds = 17;
    float speed = DISTANCE / (float)seconds;

    printf("%f\n", speed);

    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120 };
    for (int i = 0; i < 9  ; ++i) {
         printf("%c", (char)array[i]);
    }


    return 0;
}