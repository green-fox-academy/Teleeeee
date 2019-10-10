//
// Created by User on 10/10/2019.
//

#include "Resources.h"
#include "SDL_image.h"

void Resources::loadImages(SDL_Renderer* renderer, const char*fileName) {
    SDL_Texture * texture = IMG_LoadTexture(renderer, fileName);
    _textures.emplace_back(texture);
}

Resources::Resources(SDL_Renderer* renderer) {
    _textures.emplace_back(IMG_LoadTexture(renderer, "wall.gif"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "floor.gif"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "Kyle.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "Timmy.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "cartmen.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "spritestrans.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "mapElements.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "kfc.png"));
    _textures.emplace_back(IMG_LoadTexture(renderer, "spriteSheetCartmen.png"));
}

std::vector<SDL_Texture *> Resources::getTextures() {
    return _textures;
}
