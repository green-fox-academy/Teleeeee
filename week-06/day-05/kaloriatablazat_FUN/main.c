#include <stdio.h>

int main() {

    unsigned int buffer[100000] = {-1};

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
        if(buffer[j] == -1)break;
        // change á to a
        if(buffer[j] == 195 && buffer[j+1] == 161 ) {
            buffer[j] = 97;
            buffer[j + 1] = ' ';
        }
        //change ő to o
        if(buffer[j] == 197 && buffer[j+1] == 145 ){
            buffer[j] = 111;
            buffer[j + 1] = ' ';
        }
        //change ö to o
        if(buffer[j] == 195 && buffer[j+1] == 182 ){
            buffer[j] = 111;
            buffer[j + 1] = ' ';
        }
        //change  é to e
        if(buffer[j] == 195 && buffer[j+1] == 169 ){
            buffer[j] = 101;
            buffer[j + 1] = ' ';
        }
        //change  í to i
        if(buffer[j] == 195 && buffer[j+1] == 173 ){
            buffer[j] = 105;
            buffer[j + 1] = ' ';
        }
        //change  ú to u
        if(buffer[j] == 195 && buffer[j+1] == 186 ){
            buffer[j] = 117;
            buffer[j + 1] = ' ';
        }
        // change ó to o
        if(buffer[j] == 195 && buffer[j+1] == 179 ){
            buffer[j] = 111;
            buffer[j + 1] = ' ';
        }
        // change ü to u
        if(buffer[j] == 195 && buffer[j+1] == 188 ){
            buffer[j] = 117;
            buffer[j + 1] = ' ';
        }
        //change ű to u
        if(buffer[j] == 197 && buffer[j+1] == 177 ){
            buffer[j] = 117;
            buffer[j + 1] = ' ';
        }
        //change special character to U
        if(buffer[j] == 195 && buffer[j+1] == 154 ){
            buffer[j] = 85;
            buffer[j + 1] = ' ';
        }
        //change special character to E
        if(buffer[j] == 195 && buffer[j+1] == 137 ){
            buffer[j] = 69;
            buffer[j + 1] = ' ';
        }
        //change special character to O
        if(buffer[j] == 195 && buffer[j+1] == 150 ){
            buffer[j] = 79;
            buffer[j + 1] = ' ';
        }
        //change special character
        if(buffer[j] == 195 && buffer[j+1] == 129 ){
            buffer[j] = 65;
            buffer[j + 1] = ' ';
        }
        //change special character
        if(buffer[j] == 197 && buffer[j+1] == 144 ){
            buffer[j] = 79;
            buffer[j + 1] = ' ';
        }
        //change special character to U
        if(buffer[j] == 195 && buffer[j+1] == 156 ){
            buffer[j] = 85;
            buffer[j + 1] = ' ';
        }
        //change special character I
        if(buffer[j] == 195 && buffer[j+1] == 141 ){
            buffer[j] = 73;
            buffer[j + 1] = ' ';
        }
        //instead of tabs put '
        if(buffer[j] == 9){
             buffer[j] = ',';
        }
        //take out extra spaces
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