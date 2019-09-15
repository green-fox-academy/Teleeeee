#include <iostream>
#include <string>
using namespace std;



//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending
void bubbleSort(int arr[],int n, bool whichway);
int main(int argc, char* args[])
{
    int parameters[8] = {1,8,4,3,6,9,2,5};
    cout << "true or false";
    bool upordown = true;
    cin >> upordown;


    bubbleSort(parameters, 8, upordown);


    return 0;
}


void bubbleSort(int arr[],int n, bool whichway) {
    int temp;
    if (!whichway) {
        for (int i = 0; i < (n - 1); i++) {
            for (int j = 0; j < (n - i - 1); j++) {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Elements sorted successfully..!!\n";
        cout << "Sorted list in descendig order :\n";
        for (int h = 0; h < n; h++) {
            cout << arr[h] << " ";
        }
    } else {
        for (int i = 0; i < (n - 1); i++) {
            for (int j = 0; j < (n - i - 1); j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Elements sorted successfully..!!\n";
        cout << "Sorted list in ascending order :\n";
        for (int h = 0; h < n; h++) {
            cout << arr[h] << " ";
        }
    }

}