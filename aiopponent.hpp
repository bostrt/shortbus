#ifndef AIOPPONENT_H
#define AIOPPONENT_H

#include <SDL/SDL.h>
#include <string>
#include "model.hpp"
#include <vector>
using namespace std;
class AiOpponent:public Model{
public:
	bool dead;
	int getRotation();
	void setRotation(int rotate);
	bool flip;
	int x,y,points;
	int dir;
	SDL_Surface* image;
	double velocity;
	AiOpponent(int x,int y,string filename,int pts);
	virtual void update(std::vector<Model *> world);
	void die(Model* model);
	void checkCollisions(std::vector<Model *> worlds);
	int getDirection();
	void setDirection(int direction);
	bool isDead();
	void setDead(bool deathstatus);
};

#endif /* AIOPPONENT */
