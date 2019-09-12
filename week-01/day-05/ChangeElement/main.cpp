#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {

    int s[] = {1, 2, 3, 8, 5, 6};
    int a = 4;
    s[3]= a;

    cout << s[3] << endl;


    // - Create an array variable named `s`
    //   with the following content: `[1, 2, 3, 8, 5, 6]`
    // - Change the 8 to 4
    // - Print the fourth element

    return 0;
}