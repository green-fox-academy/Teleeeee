#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H
#include "string"

class sharpie {

public:

    void use();
    sharpie(std::string, float);
    bool haveInk();

private:

    float _width;
    float _inkAmount;
    std::string _color;


};


#endif //SHARPIE_SHARPIE_H
