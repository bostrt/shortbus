#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "vehicle.hpp"

class Player {
public:
	int pointtotal;
	Player();
	void handleEvent(SDL_Event *event);
	void drawVehicle(SDL_Surface *screen);
	Vehicle *getVehicle();
private:
	Vehicle *vehicle;
};

#endif
