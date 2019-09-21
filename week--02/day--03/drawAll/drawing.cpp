//
// Created by User on 18/09/2019.
//
#include "draw.h"

void draw(SDL_Renderer* gRenderer) 
{

    SDL_SetRenderDrawColor(gRenderer, 255 /*R*/, 0 /*G*/, 0 /*B*/, 255/*A*/);
    SDL_RenderDrawLine(gRenderer, 0, 240, 640, 240);
}
