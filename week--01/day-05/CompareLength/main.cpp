#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* args[]) {

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print "p2 is longer" if `p2` has more elements than `p1`

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

    if(sizeof(p2) > sizeof(p1)) {
        cout << "`p2` has more elements than `p1`" << endl;

    } else { //will show the sizes
        cout << "size of p2 " << sizeof(p2) << " size of p1 " << "  " << sizeof(p1) << endl;

    }

    return 0;
}