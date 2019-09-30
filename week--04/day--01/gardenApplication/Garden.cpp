//
// Created by User on 30/09/2019.
//

#include <iostream>
#include "Garden.h"

void Garden::needsWatering(){
    std::vector<int> indexesTrees;
    std::vector<int> indexesFlowers;
    for (int i = 0; i < _flowers.size() ; ++i) {
        if(_flowers[i]->getWaterlevel() < 5){
            std::cout << "The " <<  _flowers[i]->getColor() << " flower needs water!" << std::endl;
        }else{
            std::cout << "The " <<  _flowers[i]->getColor() << " flower doesn't need water!" << std::endl;
        }
    }
    for (int i = 0; i < _trees.size() ; ++i) {
        if(_trees[i]->getWaterlevel() < 10){
           std::cout << "The " << _trees[i]->getColor() << " tree needs water!" << std::endl;
        }else{
            std::cout << "The " << _trees[i]->getColor() << " tree doesn't need water!" << std::endl;
        }
    }

}


void Garden::wateringWith70(){
    std::cout << "Watering with 70" << std::endl;
    std::vector<int> indexesTrees;
    std::vector<int> indexesFlowers;
    for (int i = 0; i < _trees.size() ; ++i) {
        if(_trees[i]->getWaterlevel() < 10){
            indexesTrees.push_back(i);
        }
    }
    for (int i = 0; i < _flowers.size() ; ++i) {
        if(_flowers[i]->getWaterlevel() < 5){
            indexesFlowers.push_back(i);
        }
    }
    double needswatering = indexesFlowers.size() + indexesTrees.size();
    double waterAmount = 70/needswatering;
    for (int i = 0; i < _flowers.size() ; ++i) {
        if(_flowers[i]->getWaterlevel() < 5){
            _flowers[i]->setWaterlevel(waterAmount);
        }
    }
    for (int i = 0; i < _trees.size() ; ++i) {
        if(_trees[i]->getWaterlevel() < 10){
            _trees[i]->setWaterlevel(waterAmount);
        }
    }


}

void Garden::wateringWith40(){
    std::cout << "Watering with 40" << std::endl;
    std::vector<int> indexesTrees;
    std::vector<int> indexesFlowers;
    for (int i = 0; i < _trees.size() ; ++i) {
        if(_trees[i]->getWaterlevel() < 10){
            indexesTrees.push_back(i);
        }
    }
    for (int i = 0; i < _flowers.size() ; ++i) {
        if(_flowers[i]->getWaterlevel() < 5){
            indexesFlowers.push_back(i);
        }
    }
    double needswatering = indexesFlowers.size() + indexesTrees.size();
    double waterAmount = 40/needswatering;
    for (int i = 0; i < _flowers.size() ; ++i) {
        if(_flowers[i]->getWaterlevel() < 5){
            _flowers[i]->setWaterlevel(waterAmount);
        }
    }
    for (int i = 0; i < _trees.size() ; ++i) {
        if(_trees[i]->getWaterlevel() < 10){
            _trees[i]->setWaterlevel(waterAmount);
        }
    }

}

void Garden::addFlowers(Flowers* flower){
    _flowers.push_back(flower);
}
void  Garden::addTrees(Trees* tree){
    _trees.push_back(tree);
};

