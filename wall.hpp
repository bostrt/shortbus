#ifndef WALL_H
#define WALL_H

#include <SDL/SDL.h>
#include <string>

class Wall {
public:
    Wall(std::string filename);
    void draw(int x, int y, int width, int height);
private:
    SDL_Surface *wall;
};

#endif
