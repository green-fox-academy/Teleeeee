//
// Created by User on 10/10/2019.
//

#include "DrawableElement.h"

DrawableElement::DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture, SDL_Texture* animation) : _xOnDrawtable(xOnDrawtable),
                                                                       _yOnDrawtable(yOnDrawtable),
                                                                       _texture(texture),
                                                                       _animation(animation){}

DrawableElement::DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture) : _xOnDrawtable(xOnDrawtable),
                                                                                                                     _yOnDrawtable(yOnDrawtable),
                                                                                                                     _texture(texture){}

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

SDL_Texture *DrawableElement::getAnimation() const {
    return _animation;
}


