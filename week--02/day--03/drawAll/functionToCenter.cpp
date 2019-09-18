#include "draw.h"
#include <SDL.h>


void toTheCenter(SDL_Renderer* renderer, int a, int b){
    a = 0;
    b = 0;
    int a1 = 640;
    int b1 = 480;
    for (int i = 0; i <= 480 ; i = i + 40) {

            SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
            SDL_RenderDrawLine(renderer, i, 0,  b1, i);

    }
    for (int i = 0; i <= 480 ; i = i + 40) {

        SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(renderer, 0, i, i, b1);

    }

}


void draw(SDL_Renderer* gRenderer) {
    int a = 0;
    int b = 0;
    toTheCenter(gRenderer, a, b);





}

