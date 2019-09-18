#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    int a = 0;
    int b = 0;
    int a1 = 480;
    double b1 = 480;
    int arany = 16;
    for (int k = 0; k < 64 ; k++) {
        for (int j = 0; j < 64; j++) {

            for (double i = 0; i <= 480 / arany; i = i + 40 / arany) {

                SDL_SetRenderDrawColor(gRenderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
                SDL_RenderDrawLine(gRenderer, i + (j * b1 / arany), 0 +(k * (b1/arany)), b1 / arany + (j * b1 / arany), i +(k * (b1/arany)));

            }
            for (double i = 0; i <= 480 / arany; i = i + 40 / arany) {

                SDL_SetRenderDrawColor(gRenderer, 0 /*R*/, 0xff /*G*/, 0x00 /*B*/, 0xFF /*A*/);
                SDL_RenderDrawLine(gRenderer, 0 + (j * b1 / arany), i + (k * (b1/arany)), i + (j * b1 / arany), b1 / arany + (k * (b1/arany)));

            }
        }
    }
}
