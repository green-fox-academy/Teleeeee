//
// Created by User on 25/09/2019.
//

#include "sharpieSet.h"
#include "sharpie.h"
#include "vector"


void sharpieSet::addSharpie(sharpie& o){                 //sharpie memoriacimet toltjuk bele
    _box.push_back(&o);
}

sharpie* sharpieSet::getsharpie(sharpie& o){             //sharpie objecteket eri el
    return &o;
}

sharpie* sharpieSet::getsfromsetharpie(int k){          //pointerrel ter vissza a vectorbol
    if(k > 0 && k < _box.size() ) {
        return _box[k];
    }
}


sharpieSet::sharpieSet()= default;

int sharpieSet::countUseable(){
    int counter = 0;
    for (int i = 0; i < _box.size() ; ++i) {
        if( !_box[i]->haveInk()){
            counter++;
        }
    }
    return counter;
}


void sharpieSet::removeTrash() {
    for(int i = 0; i <  _box.size();) {
            if ( !_box[i]->haveInk()) {
                _box.erase(_box.begin() + i);
            }else{
                i++;
            }
    }
}
