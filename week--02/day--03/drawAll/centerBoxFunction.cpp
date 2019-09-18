#include "draw.h"
#include <SDL.h>



void squareInTheMiddle(SDL_Renderer* renderer, int size ){

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect r;
    r.x = SCREEN_WIDTH/2 - (size/2) ;
    r.y = SCREEN_HEIGHT/2 - (size/2) ;
    r.w = size;
    r.h = size;
    SDL_RenderDrawRect(renderer, &r);
}
void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
    int size;
    for( int i = 1; i < 4 ; i++){
        size = 50 * i;
        squareInTheMiddle(gRenderer, size);
    }


}
