#include <iostream>
#include <SDL.h>
#include <vector>
#include <queue>
#include "drawRect.h"
#include "ctime"
#include "cstdlib"
#include "SDL_audio.h"


void floodFill(int x, int y , std::vector<std::vector<int>>* numberOfTiles, SDL_Renderer* gRenderer, drawRect * rect ){
    if((*numberOfTiles)[x][y] == 0){
        (*numberOfTiles)[x][y] = 1;

        if(x + 1 < 100) {
            SDL_Delay(1);
            rect->drawIt(gRenderer, y* 10 , x* 10 , 10);
            floodFill(x + 1, y, numberOfTiles,gRenderer, rect);
        }
        if(y + 1 < 100) {
            SDL_Delay(1);
            rect->drawIt(gRenderer, y* 10 , x* 10 , 10);
            floodFill(x, y + 1, numberOfTiles,gRenderer, rect);
        }
        if(x - 1 >= 0) {
            SDL_Delay(1);
            rect->drawIt(gRenderer, y* 10 , x* 10 , 10);
            floodFill(x - 1, y, numberOfTiles,gRenderer, rect);
        }
        if(y - 1 >= 0) {
            SDL_Delay(1);
            rect->drawIt(gRenderer, y * 10 , x * 10 , 10);
            floodFill(x, y - 1, numberOfTiles,gRenderer,rect);
        }
    }
    return;
}



//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

bool init() {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Draw Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close() {
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main(int argc, char *args[]) {
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    srand(time(0));

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    bool doIt = 1;


    //While application is running
    while (!quit) {
        //Handle events on queue

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);



        std::vector<std::vector<int>> numberOfTiles(100, std::vector<int>( 100, 0)) ;
/*
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < 200; j++){
                if(rand()%10 == 1){
                    numberOfTiles[i][j] = 1;
                }else{
                    numberOfTiles[i][j] = 0;
                }
            }
        }
*/


        /*for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++) {
                if(numberOfTiles[i][j] == 0) {
                    SDL_Delay(100);
                    drawRect rect;
                    rect.drawIt(gRenderer, i * 50, j * 50, 50);
                }
            }
        }*/

        SDL_Event event;

        //Save current mouse point
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        bool drawing = 1;
        drawRect rect;


        while(drawing) {

            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    numberOfTiles[mouseY/10][mouseX/10] = 1;
                }
                if (e.type == SDL_MOUSEWHEEL){
                    drawing = 0;
                    if(doIt) {
                        floodFill(0,0,&numberOfTiles,gRenderer, &rect);
                        doIt = 0;
                    }
                }

            }
        }



        //Clear screen


        //You can start drawing here

        //Update screen
        //SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}



