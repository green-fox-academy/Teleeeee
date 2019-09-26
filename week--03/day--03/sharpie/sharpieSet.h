//
// Created by User on 25/09/2019.
//

#ifndef SHARPIE_SHARPIESET_H
#define SHARPIE_SHARPIESET_H

#include "vector"
#include "cmake-build-debug/sharpie.h"
#include "string"


class sharpieSet {
public:
    sharpieSet();
    void removeTrash();
    int countUseable();
    void addSharpie(sharpie& o);
    sharpie* getsharpie(sharpie& o);           //sharpie objecteket eri el
    sharpie* getsfromsetharpie(int k);         //pointerrel ter vissza a vectorbol

private:

    std::vector<sharpie*> _box;               //sharpie pointereket tartalmazo vector a _box

};


#endif //SHARPIE_SHARPIESET_H
