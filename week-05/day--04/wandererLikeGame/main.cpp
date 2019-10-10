#include <iostream>
#include <SDL.h>
#include "Resources.h"
#include "Draw.h"
#include "Movements.h"
#include "ctime"

//Screen dimension constants
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;

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

    //Main loop flag
    bool quit = false;

    //ask for time for random
    srand(time(0));

    //Event handler
    SDL_Event e;

    Draw draw;

    int k = 2050;
    int z = 2050;
    std::vector<std::vector<int>> map = draw.generateMap();


    Resources gResources(gRenderer);
    Movements move;
    DrawableElement Cartmen(4,4, gResources.getTextures()[4]);
    DrawableElement Wall(0,0, gResources.getTextures()[0]);
    DrawableElement Floor(0,0, gResources.getTextures()[1]);

    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z, map);



    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }




        //movements here

        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case (SDLK_UP):
                    if(move.moveAble(&map , k - 1, z)){
                        k--;
                    }
                    break;
                case (SDLK_DOWN):
                    if(move.moveAble(&map , k + 1, z)){
                        k++;
                    }
                    break;
                case (SDLK_RIGHT):
                    if(move.moveAble(&map , k, z  + 1)){
                        z++;
                    }
                    break;
                case (SDLK_LEFT):
                    if(move.moveAble(&map , k, z - 1)){
                        z--;
                    }
                    break;
            }
        }

        ////DRAW HERE ////
        draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z,map);
        draw.draw(gRenderer,&Cartmen);

        ////DRAW HERE ////


        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
