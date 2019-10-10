#ifndef WANDERERLIKEGAME_RESOURCES_H
#define WANDERERLIKEGAME_RESOURCES_H

#include <SDL_render.h>
#include <vector>
#include <string>

class Resources {
public:

    Resources(SDL_Renderer* renderer);

    void loadImages(SDL_Renderer* renderer, const char* fileName);

    std::vector<SDL_Texture *> getTextures();



private:

    std::vector<SDL_Texture*> _textures;



};


#endif //WANDERERLIKEGAME_RESOURCES_H
