#ifndef WANDERERLIKEGAME_DRAWABLEELEMENT_H
#define WANDERERLIKEGAME_DRAWABLEELEMENT_H


#include <SDL_render.h>

class DrawableElement {

public:

    DrawableElement(int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture,SDL_Texture* animation );
    DrawableElement(int inventoryId, int xOnDrawtable, int yOnDrawtable, SDL_Texture* texture);

    int getXOnDrawtable() const;

    int getYOnDrawtable() const;

    void setXAndYOnDrawtable(int xOnDrawtable,int yOnDrawtable);

    void resetXandYtoZero();

    [[nodiscard]] SDL_Texture *getTexture() const;

    SDL_Texture *getAnimation() const;

    void changeByXOnDrawtable(int change);

    void changeByYOnDrawtable(int change);

    void setInventoryId(int inventoryId);

    int getInventoryId();




private:

    int _xOnDrawtable;
    int _yOnDrawtable;
    SDL_Texture* _texture;
    SDL_Texture* _animation;
    int _inventoryId;


};


#endif //WANDERERLIKEGAME_DRAWABLEELEMENT_H
