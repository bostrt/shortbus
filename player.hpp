#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>

class Player {
public:
    Player();
    void handleEvent(SDL_Event *event);
};

#endif
