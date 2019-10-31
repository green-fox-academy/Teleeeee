#include <stdint-gcc.h>
#include "bmp_utility.h"
#include "command_line_read.h"




int main(int argc, char *argv[]) {

    //input_read(argc, argv);

    uint8_t* header = read_file("GFAmono.bmp", HEADER);

    uint8_t* buffer_file =  read_file("GFAmono.bmp", get_size_bmp(header));
    int sor = 0;
    int oszlop = get_width_bmp(header);

    FILE* ascii_gen;
    ascii_gen = fopen(generate_new_name("GFAmono.bmp", strlen("GFAmono.bmp")), "w");
    for (int i = get_size_bmp(header); i > get_size_bmp(header)-get_img_size_bmp(header);) {
        for (int j = get_width_bmp(header); j >= 0 ; --j) {
            if (buffer_file[i - j] == 0) {
                fprintf(ascii_gen, "%s", "1");
            } else {
                fprintf(ascii_gen, "%s", " ");
            }

        }
        fprintf(ascii_gen, "\n");
        i = i - get_width_bmp(header);
    }


    fclose(ascii_gen);

     printf("%d\n",get_img_size_bmp(header) );
     printf("%d\n",get_size_bmp(header) );



    return 0;
}