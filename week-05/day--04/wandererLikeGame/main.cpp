#include <iostream>
#include <SDL.h>
#include <sstream>
#include "Resources.h"
#include "Draw.h"
#include "Movements.h"
#include "ctime"
#include <SDL_ttf.h>

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
    TTF_Init();
    if( TTF_Init() == -1 )
    {
        std::cout << "Failed to initialize TTF" << std::endl;
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
    bool menu = true;
    bool firstRun = true;

    //ask for time for random
    srand(time(0));

    //Event handler
    SDL_Event e;

    Draw gDraw;

    int k = 255;
    int z = 255;
    int side = 100;
    Resources gResources(gRenderer);
    Movements gMove;



    //std::vector<std::vector<int>> map = gDraw.generateMap();
    std::vector<std::vector<int>> map (520,std::vector<int>(520,1));

    //generate new map
    //map = gDraw.generateMap();

    //load saved map
    gResources.loadMap("map.txt", &map);


    DrawableElement Cartmen(4,4, gResources.getTextures()[4], gResources.getTextures()[8]);
    DrawableElement Wall(0,0, gResources.getTextures()[6]);
    DrawableElement Floor(0,0, gResources.getTextures()[6]);
    DrawableElement KFC(0,0,gResources.getTextures()[7]);

    gDraw.SetMap(gRenderer, &Wall, &Floor, &KFC, &Cartmen, k, z, map, side);



    //While application is running
    while (!quit) {


        //menu is initialized here
        while(menu){
            if(firstRun) {
                gDraw.menuBackground(gRenderer);
                gDraw.mainMenu(gRenderer);
                SDL_RenderPresent(gRenderer);
                firstRun = false;
            }
            SDL_PollEvent(&e);
            if(e.type == SDL_MOUSEBUTTONDOWN){
                 int mouseX, mouseY;
                  SDL_GetMouseState(&mouseX,&mouseY);
                  if (400 < mouseX && mouseX < 520 && 100 < mouseY && mouseY < 200 ){
                      menu = false;
                      quit = true;
                  }
                  if(400 < mouseX && mouseX < 520 && 250 < mouseY && mouseY < 350){
                      menu = false;
                  }
                  if(400 < mouseX && mouseX < 520 && 400 < mouseY && mouseY < 450){
                      menu = false;
                  }
            }
        }

        //Handle events on queue
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            //movements here
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case (SDLK_UP):
                        if (gMove.moveAble(&map, k - 1, z)) {
                            k--;
                        }
                        break;
                    case (SDLK_DOWN):
                        if (gMove.moveAble(&map, k + 1, z)) {
                            k++;
                        }
                        break;
                    case (SDLK_RIGHT):
                        if (gMove.moveAble(&map, k, z + 1)) {
                            z++;
                        }
                        break;
                    case (SDLK_LEFT):
                        if (gMove.moveAble(&map, k, z - 1)) {
                            z--;
                        }
                        break;
                    case (SDLK_ESCAPE):
                        menu = true;
                        firstRun = true;
                        break;
                }
            }
        }

        ////DRAW HERE ////

        gDraw.SetMap(gRenderer, &Wall, &Floor, &KFC, &Cartmen, k, z, map, side);
        gDraw.draw(gRenderer, &Cartmen, side);
        //gDraw.animation(gRenderer,&Cartmen);


        ////DRAW HERE ////
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    //save map
    gResources.saveMap(&map,"map.txt");

    return 0;
}
