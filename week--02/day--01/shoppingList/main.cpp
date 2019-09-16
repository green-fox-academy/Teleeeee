#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> shoppingList = {"Eggs", "milk", "fish", "apples", "bread", "chicken"};
    std::cout << "Do we have milk on the list?" << std::endl;


    bool weHaveMilk;                                                          //Do we have milk on the list?
    for(std::string temp : shoppingList){
        if(temp == "milk"){
           weHaveMilk = true;
        }
    }
    if(weHaveMilk){
        std::cout << "We have milk on the list" << std::endl;
    } else{
        std::cout << "We don't have milk on the list" << std::endl;
    }

    std::cout << "Do we have bananas on the list?" << std::endl;

    bool weHaveBananas;                                                       //Do we have bananas on the list?
    for(std::string temp : shoppingList){
        if(temp == "bananas"){
            weHaveBananas = true;
        }
    }
    if(weHaveBananas){
        std::cout << "We have bananas on the list" << std::endl;
    } else{
        std::cout << "We don't have bananas on the list" << std::endl;
    }


}