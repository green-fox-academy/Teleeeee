#include <iostream>
#include <string>
#include <vector>
using namespace std;

string palindromBuilder(string string1) {
    char letters[string1.length()];
    string temp;
    for (int i = 0; i < (string1.length()) ; ++i) {
        letters[i] = string1[i];
    }

    for (int j = string1.length() - 1; j >= 0 ; --j) {
        string1 = string1 + letters[j];

    }

    return string1;

}

int main() {
    cout << "Please give me a word" << endl;
    string input;
    cin >> input;
    cout << palindromBuilder(input);

}