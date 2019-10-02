#include <vector>
#include <map>
#include "Apple.h"
#include "algorithm"


std::string Apple::getApple(){
    return  "apple";
}

int Apple::sumOfVector(std::vector<int> myVec){
    int sum = 0;
    for (int i = 0; i < myVec.size() ; ++i) {
        sum = myVec[i]+ sum;
    }
    return  sum;
}

bool Apple::anagram(std::string first, std::string second){
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    return first == second;
}

std::map<char, int>  Apple::dictionary(std::string word){
    std::map<char, int> chars;
    std::vector<int> numb;
    for (int i = 0; i < word.size(); ++i) {
        int counter = 0;
        for (int j = 0; j < word.size(); ++j) {
            if(word[j] == word[i]){
                counter++;
            }
        }numb.emplace_back(counter);
    }
    for (int i = 0; i < word.size(); ++i) {
        chars.insert(std::pair<char, int> (word[i], numb[i]) );
    }
    return chars;
}

int Apple::Fibonacci(int index){
    if(index > 0) {
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 1; i <= index; ++i) {
            c = a + b;
            b = a;
            a = c;
        }
        return c;
    }
    return 0;
}
