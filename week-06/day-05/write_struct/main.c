#include <stdio.h>
#include <stdint.h>

/*
 * 1. Create a struct which represents a person:
 * - name (max 64 characters)
 * - age (integer)
 * - height in meters (floating point)
 */

typedef struct PERSON{
    char name[64];
    int age;
    float heigt;
}person_t;

int main() {

    person_t first_person = {"levente", 25, 1.75f};
    person_t second_person = {"lajos" , 55, 1.56f};
    person_t third_person = {"lajos" , 55, 1.56f};
    person_t fourth_person = {"lajos" , 55, 1.56f};
    person_t fifth_person = {"lajos" , 55, 1.56f};
    person_t sixth_person = {"lajos" , 55, 1.56f};
    person_t sevens_person = {"lajos" , 55, 1.56f};
    person_t eights_person = {"lajos" , 55, 1.56f};
    person_t ninnth_person = {"lajos" , 55, 1.56f};
    person_t tenth_person = {"lajos" , 55, 1.56f};

    person_t first_arr[10] = {first_person, second_person, third_person, fourth_person, fifth_person, sixth_person, sevens_person,
                        eights_person, ninnth_person, tenth_person};
    person_t elev;
    person_t twelve;
    person_t thir;
    person_t fou;
    person_t fi;
    person_t si;
    person_t sev;
    person_t eig;
    person_t nin;
    person_t twe;
    person_t second_arr[10] = {elev, twelve, thir, fou, fi, si, sev, eig, nin, twe};


    FILE* bin_file_out;
    bin_file_out = fopen("person.bin", "wb");
    fwrite(first_arr, sizeof(person_t), 10, bin_file_out);
    fclose(bin_file_out);

    FILE* bin_file_in;
    bin_file_in = fopen("person.bin","rb");
    fread(second_arr, sizeof(person_t), 10, bin_file_in);
    fclose(bin_file_in);

    for (int i = 0; i < 10 ; ++i) {
        printf("%s, %d, %f\n", first_arr[i].name, first_arr[i].age, first_arr[i].heigt);
        printf("%s, %d, %f\n", second_arr[i].name, second_arr[i].age, second_arr[i].heigt);
    }


    /*
     * 2. Create a person struct, fill it with some data and write it out to a binary file.
     *    Read it back to another struct variable and compare them. Are they equal?
     */

    /*
     * 3. Create an array which holds 10 person strcut.
     *    Fill them with some data and write out the array to a binary file.
     *    Read it back to another array and compare the array content to the first one. Are they equal?
     */


    return 0;
}