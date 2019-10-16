//
// Created by User on 10/10/2019.
//

#include "DrawableElement.h"

DrawableElement::DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture, SDL_Texture* animation) : _xOnDrawtable(xOnDrawtable),
                                                                       _yOnDrawtable(yOnDrawtable),
                                                                       _texture(texture),
                                                                       _animation(animation){}

DrawableElement::DrawableElement(int inventoryId, int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture) :        _xOnDrawtable(xOnDrawtable),
                                                                                                                     _yOnDrawtable(yOnDrawtable),
                                                                                                                     _texture(texture),
                                                                                                                     _inventoryId(inventoryId){}

int DrawableElement::getXOnDrawtable() const {
    return _xOnDrawtable;
}

int DrawableElement::getYOnDrawtable() const {
    return _yOnDrawtable;
}

SDL_Texture *DrawableElement::getTexture() const {
    return _texture;
}

void DrawableElement::setXAndYOnDrawtable(int xOnDrawtable,int yOnDrawtable) {
    _xOnDrawtable = xOnDrawtable;
    _yOnDrawtable = yOnDrawtable;
}


SDL_Texture *DrawableElement::getAnimation() const {
    return _animation;
}


void DrawableElement::changeByXOnDrawtable(int change){
    _xOnDrawtable = _xOnDrawtable + change;
}

void DrawableElement::changeByYOnDrawtable(int change){
    _yOnDrawtable = _yOnDrawtable + change;
}

void DrawableElement::setInventoryId(int inventoryId) {
    _inventoryId = inventoryId;
}

int DrawableElement::getInventoryId(){
    return _inventoryId;
}

void DrawableElement::resetXandYtoZero(){
    _xOnDrawtable = 0;
    _yOnDrawtable = 0;
}



