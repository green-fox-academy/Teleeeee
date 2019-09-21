//
// Created by User on 18/09/2019.
//
#include "draw.h"

void draw(SDL_Renderer* gRenderer) 
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xff, 0x00, 0x00);
    //create a rectangle
    SDL_Rect fillRect = { (SCREEN_WIDTH- 100) / 2, (SCREEN_HEIGHT-100)/2, 100, 100};
    //draw rectangle
    SDL_RenderFillRect( gRenderer, &fillRect );
    // Draw a green 100x100 square to the canvas' center.

}
