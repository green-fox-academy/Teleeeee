//
// Created by User on 18/09/2019.
//
#include "draw.h"
#include <SDL.h>

void rainbowSquares(SDL_Renderer* renderer, int size , int color){
    if(color == 1){
        SDL_SetRenderDrawColor(renderer, 51, 61, 206, 20);
    }else if(color == 2){
        SDL_SetRenderDrawColor(renderer, 244, 241, 53, 20);
    }else if(color == 3){
        SDL_SetRenderDrawColor(renderer, 244, 53, 216, 20);
    }else if(color == 4){
        SDL_SetRenderDrawColor(renderer, 79, 244, 53, 20);
    }else if(color == 5) {
        SDL_SetRenderDrawColor(renderer, 244, 66, 53, 20);
    }else if(color == 6){
        SDL_SetRenderDrawColor(renderer, 193, 53, 244, 20);
    }
    SDL_Rect r;
    r.x = SCREEN_WIDTH/2 - (size/2) ;
    r.y = SCREEN_HEIGHT/2 - (size/2) ;
    r.w = size;
    r.h = size;
    SDL_RenderFillRect(renderer, &r);
}

void draw(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_MOD);
    int size;
    int color;
    for (int i = 1; i < 7 ; ++i) {
        size = 50 *i;
        color = i;
        rainbowSquares(gRenderer, size, color);
    }


}
