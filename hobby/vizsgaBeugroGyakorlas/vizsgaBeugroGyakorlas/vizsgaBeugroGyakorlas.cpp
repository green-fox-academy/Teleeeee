#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <ctime>

std::vector<std::string> putSaturn(const std::vector<std::string>& planets)
{
    std::vector<std::string> temp;
    for (int i = 0; i <= planets.size(); i++) {
        if (i == 6) {
            temp.push_back("Saturn");
        }
        if (i < 5) {
            temp.push_back(planets[i]);
        }
        else {
            temp.push_back(planets[i - 1]);
        }
    }
    return temp;
}

std::vector<std::string> makingMatches(const std::vector<std::string>& girls, const std::vector<std::string>& boys)
{
    std::vector<std::string> temp;
    int b = boys.size();
    int g = girls.size();
    for (int i = 0; i < (g > b ? g : b); i++) {
        if (girls.size() > i && boys.size() > i ) {
            temp.push_back(girls[i]);
            temp.push_back(boys[i]);
        }else if(girls.size() > i) {
            temp.push_back(girls[i]);
        }
        else if (boys.size() > i) {
            temp.push_back(boys[i]);
        }
    }
    return temp;
}
std::vector<std::string> appendA(const std::vector<std::string>& animals)
{
    std::vector<std::string> temp;
    for (int i = 0; i < animals.size(); i++) {
        std::string tempString = animals[i] + "a";
        temp.push_back(tempString);
    }
    return temp;
}

std::vector<std::string> filter(const std::vector<std::string>& list, const std::vector<std::string>& sweets)
{
    bool flag = false;
    std::vector<std::string> temp;
    for (auto l : list) {
        for (auto s : sweets) {
            if (l == s) {
                flag = true;
            }
        }
        if (flag == false) {
            temp.push_back(l);
        }
        flag = false;
    }
    
    return temp;
}
std::string containsSeven(const std::vector<int>& numbers)
{
    for(auto n : numbers){
        if (n == 7) {
            return "Hooray";
        }
    }
    return "Noooooo";

}

bool checkNums(const std::vector<int>& numbers, const std::vector<int>& checker) 
{
    std::vector<int> tempNumbers = numbers;
    std::sort(tempNumbers.begin(), tempNumbers.end());
    std::vector<int> tempChecker = checker;
    std::sort(tempChecker.begin(), tempChecker.end());
    int countr = 0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int k = countr; k < checker.size(); k++) {
            if (tempNumbers[i] == tempChecker[k]) {
                countr++;
            }
        }
    }
   return countr == checker.size(); 
}


std::vector<std::string>quoteSwap(std::vector<std::string>& sentence, int swapIndexFirst, int swapIndexSecond ) {
    std::vector<std::string> temp  = sentence;
    std::string tempprarry;
    tempprarry = temp[swapIndexFirst];
    temp[swapIndexFirst] = temp[swapIndexSecond];
    temp[swapIndexSecond] = tempprarry;
    return temp;
}

std::vector<std::string> getChildrenWithMoreThanFourCandies(const std::vector<std::pair<std::string, std::map<std::string, int>>>& students)
{
    std::vector<std::string> counter;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].second.at("candies") > 4) {
            counter.push_back(students[i].first);
        }
    }
    return counter;
}

int sumOfAgeWithLessThanFiveCandies(const std::vector<std::pair<std::string, std::map<std::string, int>>>& students)
{
    int counter = 0;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].second.at("candies") < 5) {
            counter += students[i].second.at("age");
        }
    }
    return counter;
}

int subStrList(std::string find, std::vector<std::string>& sentence) {
    int index = -1;
    int cnt = 0;
    for (int i = 0; i < sentence.size(); i++) {
        for (int k = 0; k < sentence[i].size(); k++){
            cnt = 0;
            for (int l = 0; l < find.size(); l++) {
                if (sentence[i][k] == find[l]) {
                    cnt++;
                    k++;
                }
                else {
                    break;
                }
            }
            if (cnt == find.size()) {
                index = i;
            }
        }
    }
    return index;
}

bool armstrongNumber(int number) {
    int size = 0;
    int newnumber = 0;
    std::vector<int> broken = {
    number % 10,
    number / 10 % 10,
    number / 100 % 10,
    number / 1000 % 10,
    number / 10000 % 10,
    number / 100000 % 10,
    number / 1000000 % 10,
    number / 10000000 % 10,
    number / 100000000 % 10,
    number / 1000000000 % 10,
    };
    for (int i = broken.size() - 1; i > 0; i--) {
        if (broken[i] == 0 && broken[i -1] != 0){
            size = i;
            break;
        }
    }
    for (int i = 0; i < size; i++) {
        newnumber += std::pow(broken[i], size);
    }
    return number == newnumber;

}
int main(int argc, char* args[])
{
    /*
    std::vector<std::string> planets = { "Mercury","Venus","Earth","Mars","Jupiter","Uranus","Neptune" };

    // Saturn is missing from the planetList
    // Insert it into the correct position
    // Create a method called putSaturn() which has list parameter and returns the correct list.

    // Expected output: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune
    std::vector <std::string> correctPlanets = putSaturn(planets);

    for (int i = 0; i < correctPlanets.size(); ++i) {
        std::cout << correctPlanets[i] << " ";
    }
    */
    /*
    std::vector<std::string> girls = { "Eve","Ashley","Claire","Kat","Jane","Eve","Ashley","Claire","Kat","Jane","Eve","Ashley","Claire","Kat","Jane","Eve","Ashley","Claire","Kat","Jane" };
    std::vector<std::string> boys = { "Joe","Fred","Tom","Todd","Neef","Jeff","Joe","Fred","Tom","Todd","Neef" };

    // Write a method that joins the two lists by matching one girl with one boy into a new list
    // If someone has no pair, he/she should be the element of the list too
    // Exepected output: "Eve", "Joe", "Ashley", "Fred"...

    std::vector<std::string> matches = makingMatches(girls, boys);

    for (int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }
    */
    /*
    std::vector<std::string> animals = { "bo", "anacond", "koal", "pand", "zebr" };

    // Create a function called "appendA()" that adds "a" to every string in the "animals" list.
    // The parameter should be a vector.

    std::vector<std::string> newAnimals = appendA(animals);

    for (int i = 0; i < newAnimals.size(); ++i) {
        std::cout << newAnimals[i] << " ";
    }
    */
    /*
    const std::vector<std::string> sweets = { "Cupcake", "Brownie" };
    std::vector<std::string> list = { "Cupcake", "Carrot", "Bread", "Brownie", "Lemon" };

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the two lists as parameters.

    std::vector<std::string> filteredList = filter(list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }
    */
    /*
    const std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    const std::vector<int> numbers2 = { 6, 7, 8, 9, 10 };

    // Write a method that checks if the vector contains "7" if it contains return "Hoorray" otherwise return "Noooooo"

    // Expected output: "Noooooo"
    std::cout << containsSeven(numbers) << std::endl;

    // Expected output: "Hoorray"
    std::cout << containsSeven(numbers2) << std::endl;
    */
    /*
    const std::vector<int> numbers = { 112, 4, 8, 8, 653, 12, 14, 16 };
    const std::vector<int> numbers2 = { 16, 4, 4, 10, 12, 14, 8 };
    const std::vector<int> checker = { 4, 8, 12, 16 };

    // Check if vector contains all of the following elements: 4,8,12,16
    // Create a method that accepts vector as an input
    // it should return "true" if it contains all, otherwise "false"

    // Expected output: "The first vector does not contain all the numbers"
    if (checkNums(numbers, checker)) {
        std::cout << "The first vector contains all the numbers" << std::endl;
    }
    else {
        std::cout << "The first vector does not contain all the numbers" << std::endl;
    }

    // Expected output: "The second vector contains all the numbers"
    if (checkNums(numbers2, checker)) {
        std::cout << "The second vector contains all the numbers" << std::endl;
    }
    else {
        std::cout << "The second vector does not contain all the numbers" << std::endl;
    }

    */
    /*
    std::vector<std::string> quote = { "What", "I", "do", "create,", "I", "cannot", "not", "understand." };

    // Accidentally I messed up this quote from Richard Feynman.
    // Two words are out of place
    // Your task is to fix it by swapping the right words with code
    // Create a method called quoteSwap().

    // Also, print the sentence to the output with spaces in between.
    std::vector<std::string> something = quoteSwap(quote, 2, 5);
    for (int i = 0; i < quote.size(); ++i) {
        std::cout << quote[i] << " ";
    }
    for (int i = 0; i < something.size(); ++i) {
        std::cout << something[i] << " ";
    }
    */
    /*
    // Create a simple calculator application which reads the parameters from the prompt
    // and prints the result to the prompt.

    // It should support the following operations: +, -, *, /, % and it should support two operands.
    // The format of the expressions must be: {operation} {operand} {operand}.
    // Examples: 
    // "+ 3 3" (3 + 3 -> the result will be 6) 
    // "* 4 4" (4 * 4 -> the result will be 16)
    // "/ 20 8" (20 / 8 -> the result will be 2)
    // "% 20 8" (20 % 8 -> the result will be 4)

    // It should work like this:
    // Start the program
    // It prints: "Please type in the expression:"
    // Waits for the user input
    // Print the result to the prompt
    // Exit

    std::string operation;
    int first = 0;
    int second = 0;
    std::cout << "Please type in the expression:";
    std::cin >> operation;
    std::cin >> first;
    std::cin >> second;
    if (operation == "+") { std::cout << first + second << std::endl; }
    if (operation == "/") { std::cout << first / second << std::endl; }
    if (operation == "%") { std::cout << first % second << std::endl; }
    if (operation == "-") { std::cout << first - second << std::endl; }
    if (operation == "*") { std::cout << first * second << std::endl; }
    */
    /*
    std::string out = "";
    std::vector<int> notSoCrypticMessage = { 1, 12, 1, 2, 11, 1, 7, 11, 1, 49, 1, 3, 11, 1, 50, 11 };
    
    std::map<int, std::string> map;
    
    map[7] = "run around and desert you";
    map[50] = "tell a lie and hurt you ";
    map[49] = "make you cry, ";
    map[2] = "let you down";
    map[12] = "give you up, ";
    map[1] = "Never gonna ";
    map[11] = "\n";
    map[3] = "say goodbye ";
    
    // Things are a little bit messed up
    // Your job is to decode the notSoCrypticMessage by using the map as a look up table
    // Assemble the fragments into the out variable
    for (auto i : notSoCrypticMessage) {
        out += map.at(i);
    }

    std::cout << out << std::endl;
    */
    /*
    std::vector<std::pair<std::string, std::map<std::string, int>>> students;
    
    std::map<std::string, int> TheodorData;
    TheodorData.insert(std::make_pair("age", 9));
    TheodorData.insert(std::make_pair("candies", 2));
    students.push_back(std::make_pair("Theodor", TheodorData));
    
    std::map<std::string, int> PaulData;
    PaulData.insert(std::make_pair("age", 10));
    PaulData.insert(std::make_pair("candies", 1));
    students.push_back(std::make_pair("Paul", PaulData));
    
    std::map<std::string, int> MarkData;
    MarkData.insert(std::make_pair("age", 7));
    MarkData.insert(std::make_pair("candies", 3));
    students.push_back(std::make_pair("Mark", MarkData));
    
    std::map<std::string, int> PeterData;
    PeterData.insert(std::make_pair("age", 12));
    PeterData.insert(std::make_pair("candies", 5));
    students.push_back(std::make_pair("Peter", PeterData));
    
    std::map<std::string, int> OlafData;
    OlafData.insert(std::make_pair("age", 12));
    OlafData.insert(std::make_pair("candies", 7));
    students.push_back(std::make_pair("Olaf", OlafData));
    
    std::map<std::string, int> GeorgeData;
    GeorgeData.insert(std::make_pair("age", 3));
    GeorgeData.insert(std::make_pair("candies", 2));
    students.push_back(std::make_pair("George", GeorgeData));
    
    // Display the following things:
    //  - The names of students who have more than 4 candies
    //  - The sum of the age of children who have less than 5 candies
    
    std::cout << "Children with more than 4 candies: ";
    
    std::vector<std::string> childrenWithManyCandies = getChildrenWithMoreThanFourCandies(students);
    
    for (int i = 0; i < childrenWithManyCandies.size(); ++i) {
        std::cout << childrenWithManyCandies[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Sum of those who have less than 5 candies: " << sumOfAgeWithLessThanFiveCandies(students) << std::endl;
      
    */
/*
    //  Create a function that takes a string and a vector of string as a parameter
    //  Returns the index of the string in the vector where the first string is part of
    //  Only need to find the first occurence and return the index of that
    //  Returns `-1` if the string is not part any of the strings in the vector

    //  Example:
    std::vector<std::string> searchArr = { "this", "is", "what", "I'm", "searching" };
    std::cout <<  subStrList("ching", searchArr) << std::endl;
    //  should print: `4`
    std::cout << subStrList("not", searchArr);
    //  should print: `-1
*/
/*
    srand(time(0));
    int real = rand()%100 + 1;
    int guess = 120;
    while ( real != guess) {
        std::cout << "Guess" << std::endl;
        std::cin >> guess;
        if (guess > real) {
            std::cout << "guess something lower" << std::endl;
        }
        if (guess < real) {
            std::cout << "guess something higher" << std::endl;
        }
    }
    std::cout << "Winner, winner chicken dinner!";
    */
    std::cout << armstrongNumber(1633);
    return 0;
}