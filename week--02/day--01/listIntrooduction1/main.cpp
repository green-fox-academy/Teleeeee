#include <iostream>
#include <string>
#include <vector>
using namespace std;


void print(vector<string> &input ){
    for(const auto & it : input)
        cout << it;
}

int main() {
    vector<string> list;

    cout << list.size() << '\n';
    cout << list.empty() << '\n';

    list.emplace_back( "William\n");

    cout << list.empty() << '\n';

    cout << list[0];

    list.emplace_back("John\n");

    print(list);

    list.emplace_back("Amanda\n");

    cout << list[2];

    cout << size(list) << endl;

    print(list);

    //Create an empty list which will contain names (strings)
    //Print out the number of elements in the list
    //Add William to the list
    //Print out whether the list is empty or not
     //       Add John to the list
    //Add Amanda to the list
    //Print out the number of elements in the list
    //Print out the 3rd element
    //Iterate through the list and print out each name


}