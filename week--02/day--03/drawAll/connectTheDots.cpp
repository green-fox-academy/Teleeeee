#include <SDL.h>
#include "draw.h"

void connectTheDots(SDL_Renderer* renderer, int arr[][2], int size){
    int x1= 0;
    int x2= 0;
    int y1= 0;
    int y2= 0;
    for ( int i = 0; i < size - 1 ; i++ ) {


        x1 = arr[i][0];
        y1 = arr[i][1];
        x2 = arr[i+1][0];
        y2 = arr[i+1][1];
        SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);


    }

    x1 = arr[size -1][0];
    y1 = arr[size -1][1];
    x2 = arr[0][0];
    y2 = arr[0][1];
    SDL_SetRenderDrawColor(renderer, 0xFF /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);



}

void draw(SDL_Renderer* gRenderer) {


    int arra[][2] = {{10, 10}, {290,  10}, {290, 290}, {10, 290}};
    int arrb[][2] = {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}};
    int sizea = 4;
    int sizeb = 8;
    connectTheDots(gRenderer, arra, sizea);
    connectTheDots(gRenderer, arrb, sizeb);
    // Create a function that takes 1 parameter:
    // An array of {x, y} points
    // and connects them with green lines.
    // Connect these to get a box: {{10, 10}, {290,  10}, {290, 290}, {10, 290}}
    // Connect these: {{50, 100}, {70, 70}, {80, 90}, {90, 90}, {100, 70}, {120, 100}, {85, 130}, {50, 100}}

}
