#include <iostream>
#include <string>

// it does what it needs to but not in a nice way

int unique(int sortIt[], int size) {
    int temp[size];
    for (int i = 0; i < size ; i++) {
        for (int j = size; j > 0 ; --j) {
            if(sortIt[i] == sortIt[j] && i != j ){ // make every element 0 if it occurs
                    sortIt[i] = 0;                 // twice
                    break;
            }

        }
    }
    for (int k = 0; k < size -1 ; k++) {
        for (int h = 0; h < size - k - 1 ; ++h) { //bubble sort 0s will be first
            if(sortIt[h] > sortIt[h + 1]){
                int temp1 = sortIt[h];
                sortIt[h] = sortIt[h + 1];
                sortIt[h + 1] = temp1;
            }
        }
    }
    for (int m = 0; m < size ; ++m) { // can not cut out elements from array only print
        if(sortIt[m] != 0)            // out non 0 elements
        std::cout << sortIt[m] << " ";
    }
}


int main(int argc, char *args[]){

    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    int size = 8;

    unique(numbers, size);
}

