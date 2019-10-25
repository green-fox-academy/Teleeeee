#include <stdio.h>
#include "string.h"

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */
typedef enum SCREEN{
    SMALL,
    MEDIUM,
    BIG,
}screen_size;

typedef struct smartphones{
    char name[256];
    int year_realesed;
    screen_size screen;

}smartphones_t;

smartphones_t get_the_oldest_phone(smartphones_t* arr, size_t size);
smartphones_t smartphone_init(char name[256], int year, int screen);
int get_screen_size_count(smartphones_t* arr, size_t size, screen_size screen);

int main()
{

    smartphones_t temp_arr[15];
    char name[256] = {'\0'};
    int year_realesed;
    screen_size screen;

    FILE* file_in;
    file_in = fopen("phones.txt","r");
    if(file_in == NULL){
        printf("Couldn't find the file!");
    }
    int i = 0;
    while(i < 15){
          fscanf(file_in,"%s %d %d", name, &year_realesed, &screen);
          temp_arr[i] = smartphone_init(name, year_realesed, screen);
          i++;
    }
    fclose(file_in);

    FILE* file_out = fopen("phones_prices.txt","w");
    for (int j = 0; j < 15 ; ++j) {
        fprintf(file_out, "%s %d\n", temp_arr[j].name,
                (((temp_arr[j].screen <= SMALL) ? 0 : (temp_arr[j].screen <= MEDIUM ? 50 : 300)) + 300));
    }


    smartphones_t oldest_phone = get_the_oldest_phone(temp_arr, 15);
    printf("Oldest phone: %s, %d has the same screen size", oldest_phone.name, get_screen_size_count(temp_arr,15,BIG));

    return 0;
}
smartphones_t smartphone_init(char name[256], int year, int screen){
    smartphones_t smartph;
    strcpy(smartph.name ,name);
    smartph.year_realesed = year;
    if(screen < 12)smartph.screen = SMALL;
    if(screen >= 12 && screen < 15)smartph.screen = MEDIUM;
    if(screen > 15)smartph.screen = BIG;
    return smartph;
}

smartphones_t get_the_oldest_phone(smartphones_t* arr , size_t size){
    int year = arr[0].year_realesed;
    int oldest_index = 0;
    for (size_t i = 0; i < size; ++i) {
        if(year > arr[i].year_realesed  ){
            year = arr[i].year_realesed;
            oldest_index = i;
        }
    }
    return arr[oldest_index];
}

int get_screen_size_count(smartphones_t* arr, size_t size, screen_size screen){
    int counter = 0;
    for (size_t i = 0; i < size ; ++i) {
        if(arr[i].screen == screen){
            counter++;
        }
    }
    return counter;
}