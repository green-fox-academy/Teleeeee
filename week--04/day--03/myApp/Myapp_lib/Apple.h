#ifndef MYAPP_APPLE_H
#define MYAPP_APPLE_H


#include <string>

class Apple {
public:
    std::string getApple();
    int sumOfVector(std::vector<int> myVec);
    bool anagram(std::string first, std:: string second);
    std::map<char, int> dictionary(std::string );
    int Fibonacci(int index);
};


#endif //MYAPP_APPLE_H
