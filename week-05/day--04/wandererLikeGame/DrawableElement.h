#ifndef WANDERERLIKEGAME_DRAWABLEELEMENT_H
#define WANDERERLIKEGAME_DRAWABLEELEMENT_H


#include <SDL_render.h>

class DrawableElement {

public:

    DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture,SDL_Texture* animation );
    DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture);

    int getXOnDrawtable() const;

    int getYOnDrawtable() const;

    void setXOnDrawtable(int xOnDrawtable);

    void setYOnDrawtable(int yOnDrawtable);

    [[nodiscard]] SDL_Texture *getTexture() const;

    SDL_Texture *getAnimation() const;

    void changeByXOnDrawtable(int change);

    void changeByYOnDrawtable(int change);



private:

    int _xOnDrawtable;
    int _yOnDrawtable;
    SDL_Texture* _texture;
    SDL_Texture* _animation;


};


#endif //WANDERERLIKEGAME_DRAWABLEELEMENT_H
