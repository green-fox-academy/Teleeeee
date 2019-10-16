#include "Resources.h"
#include "SDL_image.h"

void Resources::loadImages(SDL_Renderer* renderer, const char*fileName) {
    SDL_Texture * texture = IMG_LoadTexture(renderer, fileName);
    _textures.emplace_back(texture);
}

Resources::Resources(SDL_Renderer* renderer) {
    _textures.emplace_back(IMG_LoadTexture(renderer, "vagodeszka.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "asztal.PNG"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "Kyle.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "Timmy.png"));
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
}

std::vector<SDL_Texture *> Resources::getTextures() {
    return _textures;
}

void Resources::loadMap(std::string fileName, std::vector<std::vector<int>>* map){

    // fills up the map-vector with the numbers from the saved document
    std::ifstream myFileIn;
    int sor = -1;
    std::string mapElement;
    myFileIn.open("map.txt");

    while( getline(myFileIn, mapElement)) {
        sor += 1;
        for (int j = 0; j < 500 ; ++j) {
            (*map)[sor][j] = mapElement[j] - '0';
        }
        if(sor > 500){break;}
    }

}

void Resources::saveMap(std::vector<std::vector<int>>* map, std::string fileName){

    //save the state of the map vetor as a txt

    std::ofstream myFileOut;
    myFileOut.open("map.txt");
    for(int i = 0; i < map->size(); i++){
        for (int j = 0; j < map[0].size() ; ++j) {
            myFileOut << (*map)[i][j];
        }myFileOut << std::endl;
    }
}

Resources::Resources() {}
