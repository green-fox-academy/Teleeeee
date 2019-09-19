
#include "draw.h"



void draw(SDL_Renderer* gRenderer) {

    int height = 60;
    int i = 100;
    int k = 100;



    int upperLine = 36;
    int triangleHeight = upperLine / 2;
    int shiftingPoint = i ;
    int shiftingPoint2 = k;



    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2 ,
                       shiftingPoint + triangleHeight,
                       shiftingPoint2 );
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2  + height,
                       shiftingPoint  +triangleHeight,
                       shiftingPoint2 + height);

//side triangle
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2  +height);

// other side triangle
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 + height);
}
