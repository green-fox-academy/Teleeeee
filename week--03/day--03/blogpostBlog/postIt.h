//
// Created by User on 25/09/2019.
//

#ifndef OOPTEST_POSTIT_H
#define OOPTEST_POSTIT_H


#include <string>

class postIt {

public:
    void setBackgroundColor(int backgroundColor);

    void setText(std::string text);

    void setTextColor(int textColor);

private:
    std::string text;
    int textColor;
    int backgroundColor;


};


#endif //OOPTEST_POSTIT_H
