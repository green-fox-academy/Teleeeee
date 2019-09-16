#include <iostream>
#include <map>

int main() {
    std::map<std::string, double> firstList = {
            {"Milk",            1.07},
            {"Rice",            1.59},
            {"Eggs",            3.14},
            {"Cheese",          12.60},
            {"Chicken Breasts", 9.40},
            {"Apples",          2.31},
            {"Tomato",          2.58},
            {"Potato",          1.75},
            {"Onion",           1.10},
    };
    std::map<std::string, double> aliceList = {
            {"Rice",            1},
            {"Eggs",            5},
            {"Chicken Breasts", 2},
            {"Apples",          1},
            {"Tomato",          10},
    };
    std::map<std::string, double> bobList = {
            {"Milk",            3},
            {"Rice",            2},
            {"Eggs",            2},
            {"Cheese",          1},
            {"Chicken Breasts", 4},
            {"Apples",          1},
            {"Tomato",          2},
            {"Potato",          1},
    };
    double howMuchBobPay = 0;                                                            // How much does Bob pay?
    for (std::pair<std::string, double> priceList : firstList) {
        for (std::pair<std::string, double> bobPay : bobList) {
            if (priceList.first == bobPay.first) {
                howMuchBobPay = howMuchBobPay + (priceList.second * bobPay.second);
            }
        }
    }
    std::cout << howMuchBobPay << std::endl;

    double howMuchAlicePay = 0;                                                         //How much does Alice pay?
    for (std::pair<std::string, double> priceList : firstList) {
        for (std::pair<std::string, double> alicePay : aliceList) {
            if (priceList.first == alicePay.first) {
                howMuchAlicePay = howMuchAlicePay + (priceList.second * alicePay.second);
            }
        }
    }
    std::cout << howMuchAlicePay << std::endl;

        if (bobList.find("Rice")->second > aliceList.find("Rice")->second) {           //Who buys more Rice?
            std::cout << "Bob bought more rice." << std::endl;
        } else if (bobList.find("Rice")->second < aliceList.find("Rice")->second) {
            std::cout << "Alice bought more rice." << std::endl;
        } else if (bobList.find("Rice")->second == aliceList.find("Rice")->second) {
            std::cout << "They bought the same amount of rice." << std::endl;
        }

        if (bobList.find("Potato")->second > aliceList.find("Potato")->second) {         //Who buys more Potato?
            std::cout << "Bob bought more Potato." << std::endl;
        } else if (bobList.find("Potato")->second < aliceList.find("Potato")->second) {
            std::cout << "Alice bought more Potato." << std::endl;
        } else if (bobList.find("Potato")->second == aliceList.find("Potato")->second) {
            std::cout << "They bought the same amount of Potato." << std::endl;
        }


        int i = 0;                                                                                             //Who buys more different products?
        int j = 0;
        for (std::pair<std::string, double> whoBoughtmore : bobList) {
            i++;
        }
        for (std::pair<std::string, double> whoBoughtmore : aliceList) {
            j++;
        }

        if (i > j) {
            std::cout << "Bob bought more different product" << std::endl;
        } else {
            std::cout << "Alice bought more different product" << std::endl;
        }

        int k = 0;                                                                                       //Who buys more products? (piece)
        int m = 0;
        for (std::pair<std::string, double> whoBoughtmore : bobList) {
            k = k + whoBoughtmore.second;
        }
        for (std::pair<std::string, double> whoBoughtmore : aliceList) {
            m = m + whoBoughtmore.second;
        }
        if (k > m) {
            std::cout << "Bob bought bigger amount of product" << std::endl;
        } else {
            std::cout << "Alice bought bigger amount of product" << std::endl;
        }
    std::string input;
    std::cin >> input;
    bool BobBoughtMore;

    for (std::pair<std::string, double> priceList : firstList) {                                            //who bought more with input
        for (std::pair<std::string, double> alicePay : aliceList) {
            if (bobList.find(input)->second == aliceList.find(input)->second) {
                break;
            }
            if (bobList.find(input)->second > aliceList.find(input)->second) {
               BobBoughtMore == true;
            }
            if (bobList.find(input)->second < aliceList.find(input)->second) {
                BobBoughtMore == false;
            }
        }
    }if(BobBoughtMore){
        std::cout << "Bob bought more of " << input << std::endl;
    }else if(BobBoughtMore == false){
        std::cout << "Alice bought more of " << input << std::endl;
    }else{                                                                                                 // not possible that they bought the same amount :(
        std::cout << "They bought the same amount " << input << std::endl;
    }
}


