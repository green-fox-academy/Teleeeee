#include <iostream>

using namespace std;

int main()
{
    int numb = 1;
    int sum = 0;
    double av;
    int temp;
    int i = 0;
    cout << "Type in a number " << endl;
    cin >> numb;

    cout << "Type in " << numb << " number \n";

    do{ cout << "More number here! \n";
        int temp;
        cin >> temp;
        sum += temp;
        i++;
    }while(i < numb);
    av = (double)sum / numb;

    cout << "SUM:" << sum << endl;
    cout << "Average" << av << endl;

    return 0;
}
