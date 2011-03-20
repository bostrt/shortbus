#ifndef WALL_H
#define WALL_H

#include <SDL/SDL.h>
#include <string>
#include <vector>

#include "model.hpp"

class Wall:public Model {
public:
	Wall(int xPos,int yPos,string filename);
	virtual void update(std::vector<Model *> world);
private:
	SDL_Surface *wall;
};

#endif
