#include "draw.h"
#include "draw.h"



void draw(SDL_Renderer* gRenderer) 
{
        int a = 0;
        int b = 0;
        int a1 = 480;
        int b1 = 480;
        for (int i = 0; i <= 239 ; i = i + 15) {

            SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, 240 + i, 240,  240, 0 + i);

            SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, 240 , 480 - i,  240 + i, 240);

            SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, 240 -i, 240,  240, 0 + i);

            SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
            SDL_RenderDrawLine(gRenderer, 240 , 480 - i,  240 - i, 240);

          }

}

