#include "Resources.h"
#include "SDL_image.h"

void Resources::loadImages(SDL_Renderer* renderer, const char*fileName) {
    SDL_Texture * texture = IMG_LoadTexture(renderer, fileName);
    _textures.emplace_back(texture);
}

//TODO: use map to store textures
Resources::Resources(SDL_Renderer* renderer) {
    _textures.emplace_back(IMG_LoadTexture(renderer, "vagodeszka.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "asztal.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "innerMapFloor.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "innerMapWall.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "zolibacsi.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "spritestrans.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "mapElements.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "kfc.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "sprites.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "spriteSheetCartmen.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "introPics.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "senco'.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "silverkratch.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "kenwu.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "tomlossajt.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "zsir.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "mustar.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "pennylogo.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "dolgozoalap.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "240fok.PNG"));
}

std::vector<SDL_Texture *> Resources::getTextures() {
    return _textures;
}

void Resources::loadMap(std::string fileName, std::vector<std::vector<int>>* map){

    // fills up the map-vector with the numbers from the saved document
    std::ifstream myFileIn;
    int sor = -1;
    std::string mapElement;
    std::string number;
    myFileIn.open("map.txt");

    while(!myFileIn.eof()) {
        getline(myFileIn, mapElement);
        std::stringstream ss(mapElement);
        sor += 1;
        for (int j = 0; j < 500; ++j) {
            std::getline(ss, number, ' ');
            if (number.length() == 2) {
               (*map)[sor][j] = (number[0] - '0') * 10 + (number[1] - '0');
            } else {
                (*map)[sor][j] = number[0] - '0';
        }
    }
        if (sor > 500) { break; }
    }
    myFileIn.close();
}

void Resources::saveMap(std::vector<std::vector<int>>* map, std::string fileName){

    //save the state of the map vetor as a txt

    std::ofstream myFileOut;
    myFileOut.open("map.txt");
    for(int i = 0; i < map->size(); i++){
        for (int j = 0; j < map[0].size() ; ++j) {
            myFileOut << (*map)[i][j] << ' ';
        }myFileOut << std::endl;
    }
    myFileOut.close();
}

Resources::Resources() {}
