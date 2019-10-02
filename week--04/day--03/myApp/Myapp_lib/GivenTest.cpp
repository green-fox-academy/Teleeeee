#include "GivenTest.h"

#include <algorithm>
#include <sstream>
#include <vector>

int GivenTest::add(int a, int b)
{
    return 5;
}

int GivenTest::maxOfThree(int a, int b, int c)
{
    if (a > b)
        return a;
    else
        return c;
}

int GivenTest::median(const std::vector<int>& pool) {
    return pool.at((pool.size()-1)/2);
}

bool GivenTest::isVowel(char c) {
    static const std::vector<char> vowels = {'A', 'U', 'E', 'I','a', 'u', 'o', 'e', 'i', 'O'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::vector<std::string> GivenTest::split(const std::string& str, char delim)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> v;
    while (std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string GivenTest::join(const std::string& separator, const std::vector<std::string>& array)
{
    std::stringstream ss;
    for(int i = 0; i < array.size(); ++i)
    {
        ss << array[i];
        if(i != array.size() - 1)
        {
            ss << separator;
        }
    }

    return ss.str();
}

std::string GivenTest::translate(const std::string& hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length;) {
        const char c = teve.at(i);
        if (isVowel(c)) {
            teve = join(std::string(1,c )  + "v" + std::string(1, c) , split(teve, c));
            i+=2;
            length+=2;
        }else{
            i+=2;
        }
    }
    return teve;
}

// Check out the folder. There's a work file and a test file.

//  -  Run the tests, all 10 should be green (passing).
//  -  The implementations though are not quite good.
//  -  Create tests that'll fail, and will show how the implementations are wrong(You can assume that the implementation of join and split are good)
//  -  After creating the tests, fix the implementations
//  -  Check again, if you can create failing tests
//  -  Implement if needed