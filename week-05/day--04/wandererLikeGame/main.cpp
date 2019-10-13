#include <iostream>
#include <SDL.h>
#include <fstream>
#include <sstream>
#include "Resources.h"
#include "Draw.h"
#include "Movements.h"
#include "ctime"

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

    //Main loop flag
    bool quit = false;

    //ask for time for random
    srand(time(0));

    //Event handler
    SDL_Event e;

    Draw draw;

    int k = 255;
    int z = 255;
    int side = 100;

   std::vector<std::vector<int>> map (501,std::vector<int>(501,0));

    std::ifstream myFileIn;
    int sor = -1;
    std::string mapElement;
    myFileIn.open("map.txt");

    while( getline(myFileIn, mapElement)) {
        sor += 1;
        for (int j = 0; j < 500 ; ++j) {
                 map[sor][j] = mapElement[j] - '0';
        }
    }

    //std::vector<std::vector<int>> map = draw.generateMap();


    Resources gResources(gRenderer);
    Movements move;
    DrawableElement Cartmen(4,4, gResources.getTextures()[4], gResources.getTextures()[8]);
    DrawableElement Wall(0,0, gResources.getTextures()[6]);
    DrawableElement Floor(0,0, gResources.getTextures()[6]);
    DrawableElement KFC(0,0,gResources.getTextures()[7]);

    draw.SetMap(gRenderer, &Wall, &Floor,&KFC, &Cartmen, k,z, map, side);



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
                case(SDLK_ESCAPE):
                    move.changeTile(&map,k,z);
                    //menu background start set up not done
                    //draw.menuBackground(gRenderer);
                    //SDL_RenderPresent(gRenderer);
            }
        }

        //if(e.type == SDL_MOUSEBUTTONDOWN){
        //   int mouseX, mouseY;
        //    SDL_GetMouseState(&mouseX,&mouseY);
        //    map[k + mouseY / side + 1][z + mouseX / side + 1] = 3;
        //}
        //if(e.type == SDL_MOUSEWHEEL){
        //    side += 1;
        //}
        //if(e.type == SDL_MOUSEMOTION){
        //    side -= 1;
        //}


        ////DRAW HERE ////

        draw.SetMap(gRenderer, &Wall, &Floor, &KFC, &Cartmen,  k, z,map, side);
        draw.draw(gRenderer,&Cartmen,side);
        //draw.animation(gRenderer,&Cartmen);


        ////DRAW HERE ////
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();


    std::ofstream myFileOut;
    myFileOut.open("map.txt");
    for(int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[0].size() ; ++j) {
            myFileOut << map[i][j];
        }myFileOut << std::endl;
    }

    return 0;
}
