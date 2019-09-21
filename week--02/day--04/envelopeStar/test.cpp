#include "draw.h"

void drawHexagon(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2) 
{


    double upperLine = height * 0.6;
    double triangleHeight = upperLine / 2;



    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2 ,
                       shiftingPoint + triangleHeight,
                       shiftingPoint2 );
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0 /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint + triangleHeight + upperLine,
                       shiftingPoint2  + height,
                       shiftingPoint  +triangleHeight,
                       shiftingPoint2 + height);

//side triangle
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint ,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + triangleHeight,
                       shiftingPoint2  +height);

// other side triangle
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 ,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2);
    SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(gRenderer,
                       shiftingPoint  + 2 * upperLine,
                       shiftingPoint2  + height / 2,
                       shiftingPoint  + upperLine + triangleHeight,
                       shiftingPoint2 + height);
}


void draw(SDL_Renderer* gRenderer) 
{

    int height = 60;
    int startPoint1 = 0; // shift to right
    int startPoint2 = 0; // shift to bottom
    int shiftTheWholeThingHorizontal = 42;
    int shiftTheWholeThingVertical = 120;
    for (int n = 0; n <= 1; ++n) {

        for (int m = 0; m <= 1; ++m) {

            for (int l = 0; l <= 1; ++l) {

                for (int k = 0; k <= 1; ++k) {

                    for (int j = 0; j <= 1; ++j) {
                        /*every cycle needs to change the number of hexagons in a coloumn*/
                        for (int i = 0; i < 4 ;  ++i) {
                            startPoint1 = shiftTheWholeThingHorizontal ;
                            startPoint2 = shiftTheWholeThingVertical + (i * height);
                            drawHexagon(gRenderer, height, startPoint1, startPoint2);

                        }
                    }
                }
            }
        }
    }
}
