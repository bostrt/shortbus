#ifndef WALLS_H
#define WALLS_H

#include <SDL/SDL.h>
#include <string>

class Walls{
public:
    SDL_Surface* wall;

    Walls(std::string filename);
    void draw(int xPos,int yPos,int width,int height);

};

#endif
