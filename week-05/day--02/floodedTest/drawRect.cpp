//
// Created by User on 08/10/2019.
//

#include "drawRect.h"


void drawRect::drawIt(SDL_Renderer* renderer, int x, int y, int side){
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = side;
    rectangle.h = side;
    SDL_SetRenderDrawColor( renderer, 0, 100, 255, 1 );
    SDL_RenderFillRect( renderer, &rectangle );
    SDL_RenderPresent(renderer);

}
