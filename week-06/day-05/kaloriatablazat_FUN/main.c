#include <stdio.h>

int main() {

    int buffer[100000] = {-1};

    FILE* file_in = fopen("kaloriatablazat.txt", "r");
    if(file_in == NULL){
        return -2;
    }

    int i = 0;
    while(!feof(file_in)){
        buffer[i] = fgetc(file_in);
        i++;
    }
    fclose(file_in);

    for (int j = 0; ; ++j) {
        if(buffer[j] == -1){
            break;
        }
        if(buffer[j] == 9){
             buffer[j] = ',';
        }
        if (buffer[j] == 32){
            for (int k = j;; ++k) {
                if(buffer[k] == -1){
                    break;
                }
                buffer[k] = buffer[k+1];
            }
            j--;
        }

    }
    for (int k = 0;; ++k) {
        if(buffer[k] == -1){
            break;
        }
        printf("%c", buffer[k]);
    }

    FILE* file_out = fopen("kaloriatablazatfix.txt", "w");

    for(int j = 0;; j++){
        if(buffer[j] == -1){
            break;
        }
        fprintf(file_out, "%c", buffer[j]);
    }

    fclose(file_out);

    return 0;
}