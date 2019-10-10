#ifndef WANDERERLIKEGAME_DRAWABLEELEMENT_H
#define WANDERERLIKEGAME_DRAWABLEELEMENT_H


#include <SDL_render.h>

class DrawableElement {

public:

    DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture );

    int getXOnDrawtable() const;

    int getYOnDrawtable() const;

    void setXOnDrawtable(int xOnDrawtable);

    void setYOnDrawtable(int yOnDrawtable);

    void changeXOnDrawtable(int change);

    void changeYOnDrawtable(int change);

private:
public:
    SDL_Texture *getTexture() const;

private:

    int _xOnDrawtable;
    int _yOnDrawtable;
    SDL_Texture* _texture;

};


#endif //WANDERERLIKEGAME_DRAWABLEELEMENT_H
