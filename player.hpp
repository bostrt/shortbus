#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "vehicle.hpp"

class Player {
public:
    Player();
    void handleEvent(SDL_Event *event);
private:
    Vehicle *vehicle;
};

#endif
