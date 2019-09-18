#include "draw.h"
#include <SDL.h>

void draw(SDL_Renderer* gRenderer) {
    double size = 50;
    for (int i = 0; i < 640  ; i = i + 2* size) {
        for (int j = 0; j < 480  ; j = j + 2 * size) {
            SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
            SDL_Rect r;
            r.x = i;
            r.y = j;
            r.w = size;
            r.h = size;
            SDL_RenderFillRect(gRenderer, &r);
        }
        for (int i = size; i < 640  ; i = i +  2 *size) {
            for (int j = size; j < 480; j = j +  2 * size) {
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
                SDL_Rect r;
                r.x = i;
                r.y = j;
                r.w = size;
                r.h = size;
                SDL_RenderFillRect(gRenderer, &r);
            }
        }
    }


}