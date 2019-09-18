#include "draw.h"
#include <iostream>
#include <SDL.h>
#include <random>
#include <cstdlib>
#include <time.h>



void drawSquare(SDL_Renderer* renderer, const int arrx[], const int arry[] ){
    for (int i = 0; i < 3 ; ++i) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect r;
        r.x = arrx[i];
        r.y = arry[i];
        r.w = 50;
        r.h = 50;
        SDL_RenderDrawRect(renderer, &r);
    }

}

void draw(SDL_Renderer* gRenderer) {
    // create a function that draws one square and takes 2 parameters:
    // the x and y coordinates of the square's top left corner
    // and draws a 50x50 square from that point.
    // draw at least 3 squares with that function.
    // avoid code duplication.

    int arrx[4] = {45, 90, 345, 230};
    int arry[4] = {12, 400, 332, 223};
    int arrw[4] = {23, 45, 63, 11};
    int arrh[4] = {100, 32, 10, 34};



   drawSquare(gRenderer, arrx, arry);

}
