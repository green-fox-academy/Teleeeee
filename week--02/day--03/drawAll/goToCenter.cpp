//
// Created by User on 18/09/2019.
//
#include "draw.h"
#include <random>
#include <cstdlib>

void goToThecenter(SDL_Renderer* renderer, int x, int y)
{
    SDL_SetRenderDrawColor(renderer, x /*R*/, 0x00 /*G*/, y /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, x, y);

}

void draw(SDL_Renderer* gRenderer) 
{
    int x;
    int y;
    for (int i = 0; i < 3; i++) {
        int x = rand()% 640;
        int y = rand()% 480;
        goToThecenter(gRenderer, x, y);
        if(i == 2) {
            SDL_Delay(1000);
            break;
        }
    }


    // Create a function that draws a single line and takes 2 parameters:
    // The x and y coordinates of the line's starting point
    // and draws a line from that point to the center of the canvas.
    // Draw at least 3 lines with that function using a loop.

}
