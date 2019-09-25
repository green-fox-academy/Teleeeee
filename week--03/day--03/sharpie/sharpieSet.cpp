//
// Created by User on 25/09/2019.
//

#include "sharpieSet.h"
#include "cmake-build-debug/sharpie.h"
#include "vector"


void sharpieSet::addSharpie(sharpie& o){
    _box.push_back(o);
}

sharpieSet::sharpieSet()= default;;

bool countUseable(sharpie &sharpie){
    return sharpie.haveInk();
}

void sharpieSet::removeTrash() {
    for(int i = 0; i <  _box.size(); i++) {
        if (! _box[i].haveInk()) {
            _box.erase( _box.begin()+i);
        }
    }
}



