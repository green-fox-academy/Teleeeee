//
// Created by User on 10/10/2019.
//

#include "DrawableElement.h"

DrawableElement::DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* _texture) : _xOnDrawtable(xOnDrawtable),
                                                                       _yOnDrawtable(yOnDrawtable),
                                                                       _texture(_texture){}

int DrawableElement::getXOnDrawtable() const {
    return _xOnDrawtable;
}

int DrawableElement::getYOnDrawtable() const {
    return _yOnDrawtable;
}

SDL_Texture *DrawableElement::getTexture() const {
    return _texture;
}

void DrawableElement::setXOnDrawtable(int xOnDrawtable) {
    _xOnDrawtable = xOnDrawtable;
}

void DrawableElement::setYOnDrawtable(int yOnDrawtable) {
    _yOnDrawtable = yOnDrawtable;
}
void DrawableElement::changeXOnDrawtable(int change) {
    _xOnDrawtable = _xOnDrawtable + change;
}

void DrawableElement::changeYOnDrawtable(int change) {
    _yOnDrawtable = _yOnDrawtable + change;
}

