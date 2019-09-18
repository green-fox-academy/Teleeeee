#include <SDL.h>
#include "draw.h"
#include "cstdlib"
#include "random"
#include <time.h>


void draw(SDL_Renderer* gRenderer) {

    srand(time());

    int size = 5;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear();

    for (int i = 0; i < 30 ; ++i) {
        SDL_SetRenderDrawColor(renderer, 193, 53, 244, 20);
        SDL_Rect r;
        r.x = rand() % 635;
        r.y = rand() % 635;
        r.w = size;
        r.h = size;
        SDL_RenderFillRect(renderer, &r);
    }



    // Draw the night sky:
    //  - The background should be black
    //  - The stars can be small squares
    //  - The stars should have random positions on the canvas
    //  - The stars should have random color (some shade of grey)
    //
    // You might have to make modifications somewhere else to create a black background ;)

}

