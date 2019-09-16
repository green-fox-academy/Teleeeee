#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> ListA = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"}; //Create a list ('List A') which contains the following values
    vector<string> ListB;                                                           //Create a new list ('List B') with the values of List A
    ListB = ListA;

    bool isDurian = find(ListA.begin(), ListA.end(), "Durian") !=ListA.end();   //Print out whether List A contains Durian or not

    if(isDurian){
        cout << "there is a Durian" << endl;
    } else {
        cout << "there is no Durian" << endl;
    }

    ListA.erase(ListA.begin() + 3, ListA.cbegin() + 4 );     //Remove Durian from List B

    for (int i = 0; i < ListA.size() ; ++i) {
        cout <<  ListA[i] << endl;

    }


    ListA.push_back("Kiwifruit");                                               //Add Kiwifruit to List A after the 4th element
    for (int i = 0; i < ListA.size() ; ++i) {
        cout << ListA[i] << endl;
    }



    if(ListA.size() > ListB.size()){                                              //Compare the size of List A and List B
        cout << "ListA is bigger\n";
    } else if(ListA.size() < ListB.size()){
        cout << "ListB is bigger \n";

    } cout << "Lists are same size \n";

    cout <<  find(ListA.cbegin(), ListA.cend(), "Avocado") - ListA.cbegin() << '\n';//Get the index of Avocado from List A

    for (int j = 0; j < ListA.size(); ++j) {
        if("Avocado" == ListA[j])
            cout << j << endl;
    }
    cout <<  find(ListB.cbegin(), ListB.cend(), "Durian") - ListB.cbegin() << '\n'; //Get the index of Durian from List B
    for (int j = 0; j < ListA.size(); ++j) {
        if("Durian" == ListB[j])
            cout << j << endl;
    }

    vector<string> temp = {"Passion Fruit", "Pomelo"};                                    //Add Passion Fruit and Pomelo to List B in a single statement
    ListB.insert( end(ListB), begin(temp), end(temp) );

    for (int i = 0; i < ListB.size() ; ++i) {
        cout <<  ListB[i] << endl;
    }

    cout << ListA[2];                                                                       //print out the 3rd element from List A


}