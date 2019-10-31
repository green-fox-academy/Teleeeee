#include "command_line_read.h"
#include "bmp_utility.h"

void input_read(int argc, char *argv[]) {
    uint8_t *header = read_file(argv[2], HEADER);

    if (argc == 1){
        print_default();
    }else{
        if(strcmp(argv[1], "-asciiartgen") == 0){
            if(strcmp(argv[3], "-w") == 0){
                printf("%d", get_width_bmp(header));
            }
            if(strcmp(argv[3], "-size") == 0){
                printf("%d", get_size_bmp(header));
            }
            if(strcmp(argv[3], "-o") == 0){
            }
            if(argc == 3 && strlen(argv[4]) > 4 && strcmp(argv[3], "-o" ) == 0){
                FILE *file_open;
                file_open = fopen( generate_new_name(argv[4], strlen(argv[4])), "w");
                if(file_open == NULL) printf("Can not open output file" );
                fclose(file_open);
                printf("%s",  generate_new_name(argv[4], strlen(argv[4])));
            }
            if(strcmp(argv[3], "-regular") == 0){
            }
            if((strcmp(argv[3], "-h") == 0)){
                printf("%d", get_height_bmp(header));
            }
            if((strcmp(argv[3], "-depth") == 0)){
                printf("%d", get_depth_bmp(header));
            }

        }else{
            printf("Wrong argument format");
        }

    }
}

void print_default(){
    printf("ASCII art generator application\n"
           "=============================== \n"
           "\n"
           "asciiartgen <path-to-source-bmp> <options>...\n"
           "\n"
           "Available <options>:\n"
           "    -size               prints out the size of the BMP file in bytes\n"
           "    -w                  prints out the width of the BMP file\n"
           "    -h                  prints out the height of the BMP file\n"
           "    -depth              prints out the color depth of the BMP file \n"
           "    -o <path-to-txt>    specify where to put the resulting txt file\n"
           "    -mono               convert the BMP picture as monochromatic txt,\n"
           "                        non-white pixels will be represented with x characters\n"
           "    -mono <character>   convert the BMP picture as monochromatic txt, \n"
           "                        <character> will be used to represent non-white pixels\n"
           "    -regular            convert the BMP picture as multiple colored txt");
}
