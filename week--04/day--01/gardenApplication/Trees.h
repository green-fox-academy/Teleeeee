//
// Created by User on 30/09/2019.
//

#ifndef GARDENAPPLICATION_TREES_H
#define GARDENAPPLICATION_TREES_H


#include <string>

class Trees {

public:

   double getWaterlevel();
   void setWaterlevel(double water);
   Trees(std::string color);
   std::string getColor();


protected:

    double _waterlevel;
    std::string _color;

private:



};


#endif //GARDENAPPLICATION_TREES_H
