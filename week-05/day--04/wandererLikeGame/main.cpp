#include <iostream>
#include <SDL.h>
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
    int zoom = 0;
    Resources gResources(gRenderer);
    Movements gMove;



    //std::vector<std::vector<int>> map = gDraw.generateMap();
    std::vector<std::vector<int>> map (520,std::vector<int>(520,1));

    //generate new map
    //map = gDraw.generateMap();

    //load saved map
    gResources.loadMap("map.txt", &map);


    DrawableElement zoliBacsi(4, 4, gResources.getTextures()[4], gResources.getTextures()[8]);
    DrawableElement Wall(0,0, gResources.getTextures()[0]);
    DrawableElement Floor(0,0, gResources.getTextures()[1]);
    DrawableElement KFC(0,0,gResources.getTextures()[7]);
    DrawableElement senco(0,0,gResources.getTextures()[11]);
    DrawableElement silverkratch(0, 0, gResources.getTextures()[12]);
    DrawableElement kenwu(0,0,gResources.getTextures()[13]);
    DrawableElement tomlossajt(1,0,gResources.getTextures()[14]);
    DrawableElement zsir(2,0,gResources.getTextures()[15]);
    DrawableElement mustar(3,0,gResources.getTextures()[16]);
    DrawableElement menuBackGround(0,0,gResources.getTextures()[10]);

    gDraw.SetMap(gRenderer, &Wall, &Floor, &KFC, &senco, &silverkratch, &kenwu, &tomlossajt, &zsir, &mustar, &zoliBacsi, k, z, map, side, zoom);



    //While application is running
    while (!quit) {


        //menu is initialized here

        while(menu){
            if(firstRun) {
                gDraw.draw(gRenderer, &menuBackGround, 1000);
                gDraw.mainMenu(gRenderer);
                SDL_RenderPresent(gRenderer);
                firstRun = false;
            }
            SDL_PollEvent(&e);
            if(e.type == SDL_MOUSEBUTTONDOWN){
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX,&mouseY);
                if (350 < mouseX && mouseX < 650 && 100 < mouseY && mouseY < 200 ){
                    menu = false;
                    quit = true;
                }
                if(350 < mouseX && mouseX < 650 && 250 < mouseY && mouseY < 350){
                    menu = false;
                }
                if(350 < mouseX && mouseX < 650 && 400 < mouseY && mouseY < 450){
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
            gMove.changeTileWithMouseClick(k,z,&map, &e);
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
                    case(SDLK_a):

                        if(side > 5) {
                            side -= 1;
                        }
                        if(zoom < 100){
                        zoom +=1;
                        }
                        break;
                    case(SDLK_b):
                        if(side < 100) {
                            side += 1;
                        }
                        if(zoom > 0) {
                            zoom -= 1;
                        }
                }
            }
        }


        ////DRAW HERE ////



        gDraw.SetMap(gRenderer, &Wall, &Floor, &KFC, &senco, &silverkratch,&kenwu ,&tomlossajt , &zsir, &mustar, &zoliBacsi, k, z, map, side, zoom);
        gDraw.draw(gRenderer, &zoliBacsi, side);
        //gDraw.inventory(gRenderer,&inventoryFirst,&inventorySecond,&inventoryThird,&inventoryFourth);
        //gDraw.animation(gRenderer,&zoliBacsi);


        ////DRAW HERE ////
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    //save map
    gResources.saveMap(&map,"map.txt");

    return 0;
}
