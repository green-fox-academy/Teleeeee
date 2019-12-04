#include <stdio.h>
#include <string.h>

typedef enum DIGIMON_LEVEL{
    baby,
    in_training,
    rookie,
    champion,
    ultimate,
    mega
} digimon_level_t;

typedef struct digimon{
    char name[128];
    int age;
    int health;
    char name_of_tamer[256];
    digimon_level_t level;
} digimon_t;

int get_minimum_health_index(digimon_t* list_of_digimons, int size_of_list){
    if(list_of_digimons == NULL) return - 2;
    if(size_of_list <= 0) return -1;
    int index_of_minimum = 0;
    int minimum_helath = list_of_digimons[0].health;
    for (int i = 0; i < size_of_list ; ++i) {
        if(minimum_helath > list_of_digimons[i].health){
            minimum_helath = list_of_digimons[i].health;
            index_of_minimum = i;
        }
    }
    return index_of_minimum;
}

int get_same_digivolution_level_count(digimon_t* list_of_digimons, int size_of_list, digimon_level_t level){
    if(list_of_digimons == NULL) return - 2;
    if(size_of_list <= 0) return -1;
    int counter = 0;
    for (int i = 0; i < size_of_list ; ++i) {
        if(list_of_digimons[i].level == level){
            counter++;
        }
    }
    return counter;
}
int get_same_tamer_name_count(digimon_t* list_of_digimons, int size_of_list, char* name_of_tamer){
    if(list_of_digimons == NULL) return - 2;
    if(size_of_list <= 0) return -1;
    int counter = 0;
    for (int i = 0; i < size_of_list ; ++i) {
        if(!strcmp(list_of_digimons[i].name_of_tamer, name_of_tamer)){
            counter++;
        }
    }
    return counter;
}

int get_avarage_health_with_the_same_tamer(digimon_t* list_of_digimons, int size_of_list, char* name_of_tamer){
    if(list_of_digimons == NULL) return - 2;
    if(size_of_list <= 0) return -1;
    int health_add = 0;
    int counter = 0;
    for(int i = 0; i < size_of_list; i++){
        if(!strcmp(list_of_digimons[i].name_of_tamer, name_of_tamer)){
            health_add += list_of_digimons[i].health;
            counter++;
        }
    }
    if(counter == 0) return -3;
    return health_add/counter;
}

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

int main()
{
    digimon_t digi_list[] = {
            {"szalad", 11, 1, "papa", baby},
            {"halado", 11, 44, "lajo", ultimate},
            {"kalapos", 11, 78, "kapa", rookie},
            {"raszta", 11, 99, "hal",baby},
            {"hajas", 11, 0, "moooo",champion},
            {"kopasz", 11, 67, "hal",champion},
    };

    printf("%d\n",get_minimum_health_index(digi_list, 6));
    printf("%d\n",get_same_digivolution_level_count(digi_list, 6, mega));
    printf("%d\n",get_same_tamer_name_count(digi_list, 6, "hal"));
    printf("%d\n",get_avarage_health_with_the_same_tamer(digi_list, 6, "hal"));

    return 0;
}