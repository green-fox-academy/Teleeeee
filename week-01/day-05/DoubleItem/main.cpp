#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* args[]) {
    int i;
    int numList[] = {3, 4, 5, 6, 7};

    for ( i = 0; i < 5 ; ++i){//simple add to itself loop
        numList[i] = numList[i] + numList[i];
        cout << numList[i] << endl;
    }//to make sure everything is fine
    cout << numList[0]<< endl;
    cout << numList[1]<< endl;
    cout << numList[2]<< endl;
    cout << numList[3]<< endl;
    cout << numList[4]<< endl;



    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    return 0;
}