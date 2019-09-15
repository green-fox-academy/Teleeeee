#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//got the whole idea from others
bool anagram(string str1, string str2);


int main(){
    string string1;
    string string2;
    cout << "Give me 2 words and I check if they are anagrams or not" << endl;
    cin >> string1;
    cin >> string2;



    if(anagram(string1, string2) == 1){
        cout << "true";
    } else {
        cout << "false";
    }
}


bool anagram(string str1, string str2) {

    if (str1.length() == str2.length()) { //char. count check
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 == str2) { // if sorted strings are the same
            return true;
        } else {
            return false;
        }
    }
}