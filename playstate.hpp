#ifndef PLAYSTATE_HPP_
#define PLAYSTATE_HPP_

#include "gamestate.hpp"

class PlayState: public GameState
{
public:
	PlayState(SDL_Surface *s);
	virtual void init();
	virtual void update();
	virtual void draw(SDL_Surface *screen);
};


#endif /* PLAYSTATE_HPP_ */
