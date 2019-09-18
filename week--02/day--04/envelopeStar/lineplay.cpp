#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    int a = 0;
    int b = 0;
    int a1 = 480;
    int b1 = 480;
    for (int i = 0; i <= 480 ; i = i + 40) {

        SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, i, 0,  b1, i);

    }
    for (int i = 0; i <= 480 ; i = i + 40) {

        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0xff /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, 0, i, i, b1);

    }

}