//
// Created by User on 08/10/2019.
//

#ifndef FLOODEDTEST_DRAWRECT_H
#define FLOODEDTEST_DRAWRECT_H


#include <SDL_render.h>
#include "iostream"
#include "vector"

class drawRect {

public:
    void drawIt(SDL_Renderer *renderer, int x, int y, int side);
    int _x;
    int _y;


};
#endif //FLOODEDTEST_DRAWRECT_H
