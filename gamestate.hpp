#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL/SDL.h>
#include "timer.hpp"

class GameState
{
public:
	/*
	 * Pass an initialized SDL_Surface to the new game state.
	 * This will be passed to the draw function.
	 */
	GameState(SDL_Surface *screen);
	/*
	 * FPS is maintained in here. Also, init, update and draw are called
	 * inside this function. (In that order.)
	 */
	void run();
	/*
	 * Objects related to this game state should be constructed in this function.
	 * Only called once.
	 */
	virtual void init() = 0;
	/*
	 * This is where you AI, NPC/Player movement, and collision detection should
	 * be handled.
	 * TODO: Should keyboard state, mouse state, <?> state be passed to this?
	 */
	virtual void update() = 0;
	/*
	 * Draw all objects to the passed screen.
	 */
	virtual void draw(SDL_Surface *screen) = 0;

	/*
	 * Getters/Setters
	 */
	SDL_Surface *getScreen();
	void setScreen(SDL_Surface *s);
	Timer *getFpsTimer();
	void setFpsTimer(Timer *t);
private:
	SDL_Surface *screen;
	Timer *fps;
};

#endif /* GAMESTATE_H */
