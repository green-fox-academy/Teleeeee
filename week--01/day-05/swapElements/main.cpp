#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {

    string abc[] = {"first", "second", "third"};



   string a = abc[0];
   string b = abc[2];

   abc[2] = a;
   abc[0] = b;




    cout << "The first element is " <<  abc[0] << " and the third element is " << abc[2]; // check if works



    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    return 0;
}