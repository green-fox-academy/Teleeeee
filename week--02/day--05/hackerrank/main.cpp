#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    string s = "11:11:11PM";
    if (s.find("PM")){
        s.erase(8, 2 );


    }
    for( int i =0; i < 8; i++){
        cout << s[i] << " ";
    }





}