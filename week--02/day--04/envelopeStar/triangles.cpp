#include "draw.h"
#include <algorithm>

void draw(SDL_Renderer* gRenderer) {
    float magassag = 17.33;
    float oldal = 20;
    float startPoint = 10 * oldal;
    float secondStart = 480 - ( 20 * magassag);


    for (float i = 0; i < 20; i =  i + 1) {


        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, 0 + (oldal *i), 480, startPoint + ((oldal/2)*i),abs( (20 * magassag) - 480) + (magassag * i) );

        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0/*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, (20*20) - (oldal *i), 480, startPoint - ((oldal/2)*i), secondStart + (magassag * i) );

        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, 0 + ((oldal/2) * i), 480 - (magassag * i), 400 - ((oldal/ 2) * i),  480- (magassag* i));



    }


}
