#include "draw.h"
#include <SDL.h>

void draw(SDL_Renderer* renderer)
{
    int a = 0;
    int b = 0;
    int a1 = 640;
    int b1 = 480;
    for (int i = 0; i <= 640 ; i = i + 20) {

        SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(renderer, i, 0, a1-i, b1);

    }
    for (int i = 0; i <= 480 ; i = i + 20) {

        SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(renderer, 0, i, a1, b1-i);

    }

}
