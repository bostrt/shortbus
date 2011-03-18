#ifndef WALL_H
#define WALL_H

#include <SDL/SDL.h>
#include <string>
#include "model.hpp"
class Wall:public Model {
public:
    SDL_Rect boundingbox;
    Wall(int xPos,int yPos,std::string filename);
//    void draw(int x, int y, int width, int height);
   virtual void update();
private:
    SDL_Surface *wall;
};

#endif
