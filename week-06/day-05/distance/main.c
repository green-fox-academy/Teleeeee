#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

void distance(char* arr){
    int first= -1;
    int last = 0;
    for (int i = 0; i < strlen(arr) ; ++i) {
        if(arr[i] == 's' && first == -1){
          first = i;
        }
        if(arr[i] == 's'){
            last = i;
        }
    }
    printf("%d %d", first, last);

}

int main ()
{
    char str[] = "This is a sample string";
    char *first, *last;

    distance(str);
    return 0;
}