#include <iostream>
#include <string>

using namespace std;

std::string reverse(const std::string& text){
    std::string temp;
    for (int i = text.size() - 1; i >= 0 ; --i) {
        temp.push_back(text[i]);
    }

    temp.swap(const_cast<basic_string<char, char_traits<char>, allocator<char>> &>(text));


    return text;

}

int main(int argc, char* args[])
{
    std::string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";


    // Create a method that can reverse an std:string, which is passed as the parameter
    // Use it on this reversed string to check it!
    // Try to solve this using .at() first, and optionally anything else after.
    // Hint: You might use a temporary variable to swap 2 characters or you can use std::swap function.

    std::cout << reverse(reversed) << std::endl;

    return 0;
}