#include<iostream>
#include <string>
#include <cstdio>
using namespace std;
int main () {
    string s = "11:11:11PM";

    int hh, mm, ss ;
    char t12[3];
    scanf("%d:%d:%d%s", &hh, &mm, &ss, t12) ;

    cout << hh << mm << ss;

    return 0;
}