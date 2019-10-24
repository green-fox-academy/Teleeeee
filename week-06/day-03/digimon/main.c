#include <stdio.h>
#include "string.h"

/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

enum DIGIVOLUTION{
    BABY,
    IN_TRANING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA,
};

typedef struct digimon{
    char name[128];
    int age;
    int health;
    char name_of_tamer[256];
    enum DIGIVOLUTION level;

}digimon_t;

int minimum_health_index(digimon_t array[], int size){
    if(array == NULL){ return -2;}
    if(size < 1){
        printf("Array too small\nerror code");
        return -3;}
    int minimum_health = array[0].health;
    int minimum_index = 0;
    for (int i = 0; i < size ; ++i) {
        if(array[i].health < minimum_health ){
            minimum_health = array[i].health;
            minimum_index = i;
        }
    }
    printf("%s has the lowest health and his index is", array[minimum_index].name);
    return minimum_index;
};

int same_digivolution_count(digimon_t array[], int size, enum DIGIVOLUTION level){
    if(array == NULL){ return -2;}
    if(level > MEGA){
        printf("Too high level was given");
        return 0;}
    if(size < 1){
        printf("Array too small\nerror code");
        return -3;}
    int counter = 0;
    for (int i = 0; i < size ; ++i) {
        if(array[i].level == level){
            counter++;
            printf("%s is on the same level \n", array[i].name);
        }
    }
    return counter;
};

int same_tamer_count(digimon_t array[], int size, char tamer_name[256]){
    if(array == NULL){ return -2;}
    if(size < 1){
        printf("Array too small\nerror code");
        return -3;}
    int counter = 0;
    for (int i = 0; i < size ; ++i) {
        if(!strcmp(array[i].name_of_tamer, tamer_name)) {
            counter++;
            printf("%s has the same tamer\n", array[i].name);

        }
    }
    return counter;
};

float avarage_health(digimon_t array[], int size, char* tamer_name){
    if(array == NULL){ return -2;}
    if(size < 1){
        printf("Array too small\nerror code");
        return -3;}
    float avarage = 0;
    float digimon_count = same_tamer_count(array, size, tamer_name);
    for (int i = 0; i < size ; ++i) {
        if(array[i].health > 100){
            array[i].health = 100;
        }
    }
    for (int i = 0; i < size ; ++i) {
        if(!strcmp(array[i].name_of_tamer, tamer_name)){
            avarage = avarage + array[i].health;
        }
    }
    return (avarage/digimon_count);
};

int main()
{

    digimon_t first_digimon = {"Geza", 25, 110,"Ash", MEGA};
    digimon_t second_digimon = {"Aladar", 1, 67,"Dumbo", BABY};
    digimon_t third_digimon = {"Elemer", 100, 42,"PTeam", ROOKIE};
    digimon_t fourth_digimon = {"Lajos", 6, 1,"Dumbo", BABY};
    digimon_t fifth_digimon = {"Margit", 44, 5,"PTeam", ROOKIE};
    digimon_t sixth_digimon = {"Margit", 66, 60,"PTeam", ROOKIE};
    digimon_t seventh_digimon = {"Margit", 23, 70,"Dumbo", ROOKIE};
    digimon_t eigth_digimon = {"Margit", 78, 30,"PTeam", ROOKIE};
    digimon_t ninveth_digimon = {"Margit", 55, 40,"Ash", ROOKIE};
    digimon_t tenth_digimon = {"Margit", 13, 11, "PTeam",ROOKIE};

    digimon_t all_toghether[10] = {first_digimon, second_digimon, third_digimon, fourth_digimon, fifth_digimon,
                                   sixth_digimon, seventh_digimon, eigth_digimon, ninveth_digimon, tenth_digimon};

    printf("%d\n", minimum_health_index(all_toghether, 0));

    printf("%d\n",same_digivolution_count(all_toghether, 10, BABY));

    printf("%d\n",same_tamer_count(all_toghether, 10, "Ash"));

    printf("%.2f\n",avarage_health(all_toghether, 10, "Dumbo"));



    return 0;
}