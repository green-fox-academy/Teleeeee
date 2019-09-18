//
// Created by User on 18/09/2019.
//

#include "draw.h"

void draw(SDL_Renderer* gRenderer) {
    // Draw a box that has different colored lines on each edge.
    // The center of the box should align with the center of the screen.
    SDL_SetRenderDrawColor(gRenderer, 0xff /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0x45 /*A*/);
    SDL_RenderDrawLine(gRenderer, 255, 210, 255, 270);

    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0xff /*G*/, 0x00 /*B*/, 0x92 /*A*/);
    SDL_RenderDrawLine(gRenderer, 375, 210, 375, 270);

    SDL_SetRenderDrawColor(gRenderer, 0xcc /*R*/, 0x00 /*G*/, 0xff /*B*/, 0xaa /*A*/);
    SDL_RenderDrawLine(gRenderer, 255, 210, 375, 210);

    SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0xff /*B*/, 0x23 /*A*/);
    SDL_RenderDrawLine(gRenderer, 255, 270, 375, 270);
}