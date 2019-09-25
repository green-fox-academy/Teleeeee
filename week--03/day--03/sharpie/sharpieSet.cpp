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

int sharpieSet::countUseable(){
    int counter = 0;
    for (int i = 0; i < _box.size() ; ++i) {
        if( !_box[i].haveInk()){
            counter++;
        }
    }
    return counter;
}

void sharpieSet::removeTrash() {
    for(int i = 0; i <  _box.size();) {
            if ( !_box[i].haveInk()) {
                _box.erase(_box.begin() + i);
            }else{
                i++;
            }
    }
}
