#ifndef WANDERERLIKEGAME_RESOURCES_H
#define WANDERERLIKEGAME_RESOURCES_H

#include <SDL_render.h>
#include <vector>
#include <string>
#include <fstream>

class Resources {
public:
    Resources();

    Resources(SDL_Renderer* renderer);

    void loadImages(SDL_Renderer* renderer, const char* fileName);

    std::vector<SDL_Texture *> getTextures();

    void loadMap(std::string fileName, std::vector<std::vector<int>>* map);

    void saveMap(std::vector<std::vector<int>>* map,  std::string fileName);

private:

    std::vector<SDL_Texture*> _textures;

};


#endif //WANDERERLIKEGAME_RESOURCES_H
