
#ifndef GARDENBETTER_PLANT_H
#define GARDENBETTER_PLANT_H


#include <string>


class Plant {
public:
    double getWaterlevel();
    void virtual setWaterlevel(double water);
    std::string getColor();
    std::string getType();
    int getMaxWaterLevel();

protected:

    double _waterlevel;
    std::string _color;
    std::string _type;
    int _maxWaterLevel;

private:

};


#endif //GARDENBETTER_PLANT_H
