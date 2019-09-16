#include <iostream>
#include <vector>
#include <map>
#include <limits>



std::string mostexpensive(std::map<std::string, double> mostExpensiveItem){
    double mostExp;
    std::string item;
    for (std::pair<std::string, double> myPair : mostExpensiveItem) {
        if( myPair.second > mostExp){
            mostExp = myPair.second;
        }
    }
    for (std::pair<std::string, double> myPair : mostExpensiveItem) {
        if(myPair.second == mostExp){
            item = myPair.first;
        }

    }
    return item;

}
double averagePrice(std::map<std::string, double> averagePrice){
    double sum = 0;
    double average = 0;
    int j = 0;
    for (std::pair<std::string, double> tempPair : averagePrice) {
            sum = sum + tempPair.second;
            j = j + 1;
    }

    average = sum / j;

    return average;


}
int productsBelow300(std::map<std::string, double> below300){
    int j = 0;
    for (std::pair<std::string, double> tempProduct : below300) {
        if( tempProduct.second < 300){
            j = j + 1;
        }
    }

    return j;
}
std::string anythingFor125(std::map<std::string, double> for125){
    bool anyfor125;
    for (std::pair<std::string, double> tempProduct : for125) {
        if(tempProduct.second == 125){
            anyfor125 = true;
        }else{
            anyfor125 == false;
        }
    }
    if(anyfor125){
        std::cout << "we have product for 125"<< std::endl;
    }else{
        std::cout << "we don't have product for 125"<< std::endl;
    }



}
std::string cheapestProduct(std::map<std::string, double> cheapestProduct);



int main() {
    std::map<std::string, double> productList = {
            {"Eggs",    200},
            {"Milk",    200},
            {"Fish",    400},
            {"Apples",  150},
            {"Bread",   50},
            {"Chicken", 550},
    };
    std::cout << "How much is the fish?" << std::endl;                                //How much is the fish?

    std::cout << "The fish's price is " << productList.find("Fish")->second << std::endl;

    std::cout << mostexpensive(productList) << std::endl;                                //What is the most expensive product?
    std::cout << averagePrice(productList) << std::endl;                                 //What is the average price?
    std::cout << productsBelow300(productList) << std::endl;                             //How many products' price is below 300?
    anythingFor125(productList);                                                         //Is there anything we can buy for exactly 125?
    cheapestProduct(productList);                                                         //What is the cheapest product?







}

std::string cheapestProduct(std::map<std::string, double> cheapestProduct){
    double cheapest = std::numeric_limits<double>::max();
    std::string item;
    for (std::pair<std::string, double> myPair : cheapestProduct) {
        if( myPair.second < cheapest){
            cheapest = myPair.second;
        }
    }
    for (std::pair<std::string, double> myPair : cheapestProduct) {
        if(myPair.second == cheapest){
            item = myPair.first;
        }
    }
    std::cout << item << std::endl;
}



