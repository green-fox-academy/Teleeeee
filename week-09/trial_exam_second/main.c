#include <stdio.h>
#include "doggo_register.h"

char* get_oldest(struct dog* doggo_register, int size){
    int oldest_index = 0;
    for (int i = 0; i < size ; ++i) {
        if(doggo_register[i].age > doggo_register[oldest_index].age){
            oldest_index = i;
        }
    }
    return doggo_register[oldest_index].name;
}

int get_size_count(struct dog* doggo_register, int size, enum size dog_size){
    int size_count = 0;
    for (int i = 0; i < size ; ++i) {
        if(doggo_register[i].dog_size == dog_size){
            size_count++;
        }
    }
    return size_count;
}

int main() {
    struct dog dogoo_reigster[] = {
            {"anna", 8, 8, BIG},
            {"bela", 4 , 4, SMALL},
            {"lajos", 81 , 81, MEDIUM},
            {"mama", 12 , 12, LARGE},
            {"papa", 99 , 99, SMALL},
            {"jim", 4 , 4, LARGE},
            {"kazmer", 33 , 33, MEDIUM},
            {"lomeretu", 2 , 2, MEDIUM},
            {"csillag", 0 , 0, SMALL},
    };

    printf("%s\n", get_oldest(dogoo_reigster, 9));
    printf("%d", get_size_count(dogoo_reigster, 9, BIG));
    return 0;
}