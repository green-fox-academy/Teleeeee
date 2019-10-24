#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer first_computer = {2.0f, 8, 64 };

    Notebook first_notebook;

    first_notebook.cpu_speed_GHz = 4.0f;
    first_notebook.ram_size_GB = 2;
    first_notebook.bits = 32;

    printf("%.2f\n" "%d\n" "%d\n", first_computer.cpu_speed_GHz, first_computer.ram_size_GB, first_computer.bits);
    printf("%.2f\n" "%d\n" "%d\n", first_notebook.cpu_speed_GHz, first_notebook.ram_size_GB, first_notebook.bits);

    return 0;
}