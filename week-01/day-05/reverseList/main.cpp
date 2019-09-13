#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {

    int aj[5] = {3, 4, 5, 6, 7};
    int bj[5];

    for (int i = 4, j =0 ; i >= 0; i-- ,j++) {
        bj[j] = aj[i];
        cout << bj[j] << endl; // check temp array
    }

    for (int k = 0; k < 5; k++) { // check end result
               aj[k] = bj[k];
               cout << aj[k] << endl;
    }

}

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`


