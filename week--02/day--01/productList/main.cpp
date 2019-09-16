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
void anythingFor125(std::map<std::string, double> for125){
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
void cheapestProduct(std::map<std::string, double> cheapestProduct){
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
void anythingUnder201(std::map<std::string, double> anythingunder){
    std::vector<std::string> itemsUnder;
    for (std::pair<std::string, double> tempProduct : anythingunder) {
        if(tempProduct.second < 201){
            itemsUnder.push_back(tempProduct.first);
        }

        }

    for (std::string temp : itemsUnder) {
        std::cout << temp << std::endl;
    }




}
void productsOver300(std::map<std::string, double> anyover300){
    std::vector<std::string> itemsOver;
    for (std::pair<std::string, double> tempProduct : anyover300) {
        if(tempProduct.second > 300){
            std::cout << tempProduct.first << " " << tempProduct.second << std::endl;
        }
    }

}



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
    anythingFor125(productList);                                                         //Is there anything we can buy for exactly 125?
    anythingUnder201(productList);                                                       //Which products cost less than 201? (just the name)
    cheapestProduct(productList);
    anythingFor125(productList);                                                         //Is there anything we can buy for exactly 125?
    std::cout << mostexpensive(productList) << std::endl;                                //What is the most expensive product?
    std::cout << averagePrice(productList) << std::endl;                                 //What is the average price?
    std::cout << productsBelow300(productList) << std::endl;                             //How many products' price is below 300?
    productsOver300(productList);                                                        //Which products cost more than 150? (name + price)











}




