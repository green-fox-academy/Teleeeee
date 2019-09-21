#include <iostream>
#include <SDL.h>
#include <random>
#include <cstdlib>
#include <time.h>


void draw(SDL_Renderer* gRenderer) 
{
    int arrx[4] = {45, 90, 345, 230};
    int arry[4] = {12, 400, 332, 223};
    int arrw[4] = {23, 45, 63, 11};
    int arrh[4] = {100, 32, 10, 34};



    for (int i = 0; i < 4 ; ++i) {
        SDL_SetRenderDrawColor(gRenderer, rand(), rand(), rand(), 255);
        SDL_Rect r;
        r.x = arrx[i];
        r.y = arry[i];
        r.w = arrw[i];
        r.h = arrh[i] ;
        SDL_RenderDrawRect( gRenderer, &r );

    }






}
