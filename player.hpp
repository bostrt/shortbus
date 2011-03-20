#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "vehicle.hpp"

class Player {
public:
	int pointtotal;
	Player();
	void handleKeys(Uint8 *keys);
	void drawVehicle(SDL_Surface *screen);
	Vehicle *getVehicle();
private:
	Vehicle *vehicle;
};

#endif
