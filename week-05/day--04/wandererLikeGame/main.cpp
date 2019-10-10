#include <iostream>
#include <SDL.h>
#include "Resources.h"
#include "Draw.h"
#include "Movemnets.h"

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

    //Event handler
    SDL_Event e;

    int k = 0;
    int z = 0;

    Resources gResources(gRenderer);
    DrawableElement Cartmen(5,5, gResources.getTextures()[4]);
    DrawableElement Wall(0,0, gResources.getTextures()[0]);
    DrawableElement Floor(0,0, gResources.getTextures()[1]);
    Draw draw;
    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z);



    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        ////DRAW HERE ////


        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case (SDLK_UP):
                    k--;
                    SDL_Delay(100);
                    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z);
                    break;
                case (SDLK_DOWN):
                    k++;
                    SDL_Delay(100);
                    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z);
                    break;
                case (SDLK_RIGHT):
                    z++;
                    SDL_Delay(100);
                    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z);
                    break;
                case (SDLK_LEFT):
                    z--;
                    SDL_Delay(100);
                    draw.SetMap(gRenderer, &Wall, &Floor, &Cartmen, k,z);
                    break;
            }
        }

        draw.draw(gRenderer,&Cartmen);




        ////DRAW HERE ////


        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
