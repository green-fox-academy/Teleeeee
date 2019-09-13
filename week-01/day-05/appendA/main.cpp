#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* args[]) {

    string animals[] = {"koal", "pand", "zebr"};
    for (int i = 0; i < 3 ; ++i) {
        animals[i] = animals[i] + "a";

    }//check results

    cout << animals[0] << '\n';
    cout << animals[1] << '\n';
    cout << animals[2] << '\n';



    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    return 0;
}