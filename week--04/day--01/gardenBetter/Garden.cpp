//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Garden.h"

void Garden::addPlants(Plant* plant){
    _plants.push_back(plant);
}

void Garden::wateringWith70() {
    std::cout << "Watering with 70" << std::endl;
    double needswatering = _plants.size();
    double waterAmount = 70/needswatering;
    for (int i = 0; i < _plants.size() ; ++i) {
        if(_plants[i]->getMaxWaterLevel() == 5 && _plants[i]->getWaterlevel() < 5) {
            _plants[i]->setWaterlevel(waterAmount);
        }
        else if(_plants[i]->getMaxWaterLevel() == 10 && _plants[i]->getWaterlevel() < 10){
            _plants[i]->setWaterlevel(waterAmount);
        }
    }
}

void Garden::needsWatering() {
    for (int i = 0; i < _plants.size(); ++i) {
        if (_plants[i]->getMaxWaterLevel() == 5) {
            if (_plants[i]->getWaterlevel() < 5) {
                std::cout << "The " << _plants[i]->getColor() << " flower needs water!" << std::endl;
            } else {
                std::cout << "The " << _plants[i]->getColor() << " flower doesn't need water!" << std::endl;
            }
        }if (_plants[i]->getMaxWaterLevel() == 10) {
            if (_plants[i]->getWaterlevel() < 10) {
                std::cout << "The " << _plants[i]->getColor() << " tree needs water!" << std::endl;
            } else {
                std::cout << "The " << _plants[i]->getColor() << " tree doesn't need water!" << std::endl;
            }
        }
    }
};

void Garden::wateringWith40() {
    std::cout << "Watering with 70" << std::endl;
    double needswatering = _plants.size();
    double waterAmount = 40/needswatering;
    for (int i = 0; i < _plants.size() ; ++i) {
        if(_plants[i]->getMaxWaterLevel() == 5 && _plants[i]->getWaterlevel() < 5) {
            _plants[i]->setWaterlevel(waterAmount);
        }
        else if(_plants[i]->getMaxWaterLevel() == 10 && _plants[i]->getWaterlevel() < 10){
            _plants[i]->setWaterlevel(waterAmount);
        }
    }
}

