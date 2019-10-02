#ifndef MYAPP_GIVENTEST_H
#define MYAPP_GIVENTEST_H


#include <string>
#include <vector>

class GivenTest {
public:
    int add(int a, int b);
    int maxOfThree(int a, int b, int c);
    int median(const std::vector<int>& pool);
    bool isVowel(char c);
    std::string translate(const std::string& hungarian);
    std::vector<std::string> split(const std::string& str, char delim);
    std::string join(const std::string& separator, const std::vector<std::string>& array);
};


#endif //MYAPP_GIVENTEST_H
