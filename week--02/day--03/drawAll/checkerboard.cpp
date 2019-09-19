#include "draw.h"
#include <SDL.h>

void draw(SDL_Renderer* gRenderer) {
    double size = 50;
    int chessBoardSide = 400;
    int chessBoardStartPoint = 0;
    for (int i = chessBoardStartPoint; i < chessBoardSide  ; i = i + 2* size) {
        for (int j = chessBoardStartPoint; j < chessBoardSide  ; j = j + 2 * size) {
            SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
            SDL_Rect r;
            r.x = i;
            r.y = j;
            r.w = size;
            r.h = size;
            SDL_RenderFillRect(gRenderer, &r);
        }
        for (int i = size + chessBoardStartPoint; i < chessBoardSide  ; i = i +  2 *size) {
            for (int j = size + chessBoardStartPoint; j < chessBoardSide; j = j +  2 * size) {
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