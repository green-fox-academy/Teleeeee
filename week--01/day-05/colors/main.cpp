#include <iostream>
#include <string>

using namespace std;

int main() {
    string colors[3][5] = {"\"lime\"","\"forest green\"","\"olive\"","\"pale green\"","\"spring green\"","\"orange red\"", "\"red\"", "\"tomato\"", " " ," " , "\"orchid\"", "\"violet\"", "\"pink\"", "\"hot pink\"", " "};
    for(int k = 0; 3 > k; ++k){ //print to check
        for(int l = 0; 5 > l; ++l){
            if(k == l){
                cout << " " << colors[k][l];
            } else {
                cout << " " << colors[k][l];
            }
        }
        cout << endl;

    }


    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`
}