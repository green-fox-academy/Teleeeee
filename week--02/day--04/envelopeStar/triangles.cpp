#include "draw.h"
#include <algorithm>

void draw(SDL_Renderer* gRenderer) {
    float shifItFromBottom  = 400;  // lower it is the further away from the bottom
    float  shiftItFromRight = 40;  // shifts it fromright to left
    float magassag =  17.33;
    float oldal = 20;              //side of the triangle
    float startPoint = 10 * oldal;
    float secondStart = shifItFromBottom - ( 20 * magassag);



    for (float i = 0; i < 20; i =  i + 1) {

        // lines from bottom left to the right top
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, shiftItFromRight + (oldal *i), shifItFromBottom , shiftItFromRight + startPoint + ((oldal/2)*i),abs( (20 * magassag) - shifItFromBottom ) + (magassag * i) );


        //lines from bottom right to the left top
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0/*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer,  shiftItFromRight + (20*20) - (oldal *i),shifItFromBottom, shiftItFromRight + startPoint - ((oldal/2)*i), secondStart + (magassag * i) );


        // horizontal lines
        SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, shiftItFromRight + ((oldal/2) * i), shifItFromBottom- (magassag * i), 400 + shiftItFromRight - ((oldal/ 2) * i),  shifItFromBottom - (magassag* i));



    }


}
