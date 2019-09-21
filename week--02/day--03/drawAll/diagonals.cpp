//
// Created by User on 18/09/2019.
//
#include "draw.h"

void draw(SDL_Renderer* gRenderer) 
{
    // Draw the canvas' diagonals.
    // If it starts from the upper-left corner it should be green, otherwise it should be red.

    //choose color
    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xff /*G*/, 0x00 /*B*/, 0x00 /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, 0, 0, 640, 480);//choose color
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    //draw line
    SDL_RenderDrawLine(gRenderer, 0, 480, 640, 0);
    //choose color


}
