#include <string>
#include <iostream>
#include "Scanner.h"


std::string Scanner::scan(){
    std::cout << "I'm scanning a document " <<  std::to_string(_speed) << " ppm." << std::endl;
    return "I'm scanning a document" + std::to_string(_speed) + " ppm '\n.";
}

Scanner::Scanner(int speed) : _speed(speed) {}
