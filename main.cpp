#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <iostream>

#include "timer.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "aiopponent.hpp"
#include "gamestate.hpp"
#include "playstate.hpp"

const Uint32 FRAMES_PER_SEC = 30;

using namespace std;

SDL_Surface* screen;

int main ( int argc, char** argv )
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	screen = SDL_SetVideoMode(1024,600,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("SHOЯTBUS","SHOЯTBUS");
	GameState *state = new PlayState(screen);
    state->run();
	return 0;
}
