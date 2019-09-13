#include <iostream>
#include <string>

using namespace std;

void greet(string x){

    cout << "Greetings  dear, " << x << endl;
}

int main(int argc, char* args[]) {


    string al = "Green Fox";

    greet(al);



    // - Create a string variable named `al` and assign the value `Green Fox` to it
    // - Create a function called `greet` that greets it's input parameter
    // - Greeting is printing e.g. `Greetings dear, Green Fox`
    // - Greet `al`

    return 0;
}