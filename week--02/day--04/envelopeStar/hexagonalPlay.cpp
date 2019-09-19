
#include "draw.h"

void drawHexagon(SDL_Renderer* gRenderer, int height , int shiftingPoint, int  shiftingPoint2) {


    double upperLine = height * 0.6;
    double triangleHeight = upperLine / 2;



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



void draw(SDL_Renderer* gRenderer) {

    int height = 60;
    int downShift = height;
    int sideShift = 108;
    int startPoint1 = 0; // shift to right
    int startPoint2 = 0; // shift to bottom

    for (int i1 = 0; i1 <=1 ; ++i1) {

        for (int n = 0; n <= 1; ++n) {

            for (int m = 0; m <= 1; ++m) {

                for (int l = 0; l <= 1; ++l) {

                    for (int k = 0; k <= 1; ++k) {

                        for (int j = 0; j <= 1; ++j) {

                            for (int i = 0; i < 4 + j + k + l - m - n - i1; ++i) {
                                startPoint1 = 42 + (j * 54) + (k * 54) + (l * 54) + (m * 54) + (n * 54)+ (i1 * 54);
                                startPoint2 = 120 - (j * 30) + (i * 60) - (k * 30) - (l * 30) + (m * 30) + (n * 30) + (i1 * 30);
                                drawHexagon(gRenderer, height, startPoint1, startPoint2);
                            }
                        }
                    }
                }
            }
        }
    }


}
