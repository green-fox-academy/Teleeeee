#include <iostream>
#include <map>

using namespace std;


int main() {
    map<int,char> first;

    if(first.empty() == 1){
        cout << "this map is empty" << endl;
    }


    first[97] = 'a';
    first[98] = 'b';
    first[99] = 'c';
    first[65] = 'A';
    first[66] = 'B';
    first[67] = 'C';


    for(std::map<int, char>::iterator it = first.begin(); it != first.end() ; it++ ){   //print out all key value pair
        cout << it->first << ":" << it->second << endl;
    }


    cout << first.find(97)->first << first.find(97)->second << endl;  //print out all key value pair
    cout << first.find(98)->first << first.find(98)->second << endl;
    cout << first.find(99)->first << first.find(99)->second << endl;
    cout << first.find(65)->first << first.find(65)->second << endl;
    cout << first.find(66)->first << first.find(66)->second << endl;
    cout << first.find(67)->first << first.find(67)->second << endl;



    first[68] = 'D';                                                      // add another key value pair

    cout << first.find(97)->first << first.find(97)->second << endl;       // check the result
    cout << first.find(98)->first << first.find(98)->second << endl;
    cout << first.find(99)->first << first.find(99)->second << endl;
    cout << first.find(65)->first << first.find(65)->second << endl;
    cout << first.find(66)->first << first.find(66)->second << endl;
    cout << first.find(67)->first << first.find(67)->second << endl;
    cout << first.find(68)->first << first.find(68)->second << endl;



    cout << "The value with 99 is " <<  first.find(99)->second << endl;    // print out value associated with key 99

    first.erase(97);                                                      // erase key value pair 97


    if(first.count(100) > 0){                                            //Print whether there is an associated value with key 100 or not
        cout << "there is a value with keyy 100";

    } else{
        cout << "There is no such key as 100" << endl;
    }




    for (int i = 0; i <= first.find(99)->first; ++i) {                   //erase all the elements of map
        first.erase(i);

    }

    cout << first.find(97)->first << first.find(97)->second << endl;    // check the result
    cout << first.find(98)->first << first.find(98)->second << endl;
    cout << first.find(99)->first << first.find(99)->second << endl;
    cout << first.find(65)->first << first.find(65)->second << endl;
    cout << first.find(66)->first << first.find(66)->second << endl;
    cout << first.find(67)->first << first.find(67)->second << endl;
    cout << first.find(68)->first << first.find(68)->second << endl;







}