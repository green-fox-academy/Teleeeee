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

    //who bought more with input
    std::string input;
    getline(std::cin, input);
    int c = 0;

    int x = bobList.find(input)->second;
    int y = aliceList.find(input)->second;

    if (bobList.find(input)->second == aliceList.find(input)->second && bobList.find(input)->second != 0 + aliceList.find(input)->second != 0  ) {
    c = 1;
    }
    if (bobList.find(input)->second > aliceList.find(input)->second) {
    c = 2;
    }
    if (bobList.find(input)->second < aliceList.find(input)->second) {
    c = 3;
    }
    switch(c){
        case 0:
            std::cout << input << " was not on the list" << std::endl;
            break;
        case 1:
            std::cout << "They have bought the same amount of " << input << std::endl;
            break;
        case 2:
            std::cout << "Bob bought more " << input << std::endl;
            break;
        case 3:
            std::cout << "Alice bought more " << input << std::endl;
            break;
    }


}


