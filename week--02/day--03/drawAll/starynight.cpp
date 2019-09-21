#include <SDL.h>
#include "draw.h"
#include "cstdlib"
#include "random"
#include <ctime>


void draw(SDL_Renderer* gRenderer) 
{

    srand(time(NULL));

    int size = 5;
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);

    for (int i = 0; i < 30 ; ++i) {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
        SDL_Rect r;
        r.x = rand() % 635;
        r.y = rand() %475;
        r.w = size;
        r.h = size;
        SDL_RenderFillRect(gRenderer, &r);
    }



    // Draw the night sky:
    //  - The background should be black
    //  - The stars can be small squares
    //  - The stars should have random positions on the canvas
    //  - The stars should have random color (some shade of grey)
    //
    // You might have to make modifications somewhere else to create a black background ;)

}

