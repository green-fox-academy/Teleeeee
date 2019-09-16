#include <iostream>
#include<vector>


int allexpenses(std::vector<int> howMuch);
int greatest(std::vector<int> greatest);
int cheapest(std::vector<int> cheapest);
double avarage(std::vector<int> cheapest);




int main() {
    std::vector<int> finance = {500, 1000, 1250, 175, 800, 120};
    std::cout << "We have spent: " << allexpenses(finance) << std::endl;          //How much did we spend?
    std::cout << "Our greatst expense was: " << greatest(finance) << std::endl;   //Which was our greatest expense?
    std::cout << "Our cheapest expense was: " << cheapest(finance) << std::endl;  //Which was our cheapest spending?
    std::cout << "Our avarage spending was: " << avarage(finance) << std::endl;   //What was the average amount of our spendings?

}

int allexpenses(std::vector<int> howMuch){
    int allWeSpent = 0;

    for (int i = 0; i < howMuch.size() ; ++i) {
        allWeSpent +=howMuch.at(i);
    }

    return allWeSpent;
}
int greatest(std::vector<int> greatest){
    int tempgreatest = 0;
    for (int i = 0; i < greatest.size() ; ++i) {
        if(tempgreatest < greatest[i]){
            tempgreatest = greatest[i];

            }
    }
    return tempgreatest;
}
int cheapest(std::vector<int> cheapest){
    int tempcheapest = cheapest[0];
    for (int i = 0; i < cheapest.size() ; ++i) {
        if(tempcheapest > cheapest[i])
            tempcheapest = cheapest[i];
            }


    return tempcheapest;

}
double avarage(std::vector<int> avarage){
    double tempavarage = 0;
    for (int i = 0; i < avarage.size() ; ++i) {
        tempavarage += avarage[i];
    }

    tempavarage = tempavarage/avarage.size();

    return  tempavarage;

}