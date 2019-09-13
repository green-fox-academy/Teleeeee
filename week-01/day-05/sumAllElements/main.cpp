#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* args[]) {

    int ai[] = {3, 4, 5, 6, 7};
    int aisum ;
    for (int i = 0; i < 5 ; ++i) {
        aisum = aisum + ai[i];

    }

    cout << aisum << endl;




    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    return 0;
}