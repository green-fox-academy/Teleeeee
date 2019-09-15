#include <iostream>
using namespace std;

int main() {

    int i;
    int j;

    cout << "I need two numbers" << endl;
    cout << "First!" << endl;
    cin >> i;
    cout << "Second!" << endl;
    cin >> j;
    int myArray[i][j];
    for( int k = 1; k <= i  ; ++k){
        for( int l = 1; l <= j  ; ++l){
            if(k == l){
                myArray[k][l] = 1;
                cout << " " << myArray[k][l];
            } else {
                myArray[k][l] = 0;
                cout << " " << myArray[k][l];
            }
        }
        cout << endl;
    }
    return 0;
}