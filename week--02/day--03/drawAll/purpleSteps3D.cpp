
#include "draw.h"

void squareInTheMiddle(SDL_Renderer* renderer, double size, double pos ){

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect r;
    r.x = pos - 1;
    r.y = pos - 1 ;
    r.w = size + 2;
    r.h = size + 2;
    SDL_RenderDrawRect(renderer, &r);


    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect a;
    a.x = pos;
    a.y = pos;
    a.w = size;
    a.h = size;
    SDL_RenderFillRect(renderer, &a);

}

void draw(SDL_Renderer* gRenderer) {
    double size = 5;
    double pos = 1;

    for (int i = 0; i < 5 ; ++i) {
        size = 2 * size;
        pos = size ;
        squareInTheMiddle(gRenderer, size, pos);
    }


}