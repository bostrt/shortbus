#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "vehicle.hpp"

class Player {
public:
    Player();
    void handleEvent(SDL_Event *event);
    Vehicle *getVehicle();
private:
    Vehicle *vehicle;
};

#endif
