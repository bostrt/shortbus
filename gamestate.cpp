#include <iostream>

#include "gamestate.hpp"
#include "timer.hpp"

using namespace std;

const Uint32 FRAMES_PER_SEC = 30;

GameState::GameState(SDL_Surface *theScreen)
{
	screen = theScreen;
	fps = new Timer();
}

void GameState::run()
{
	init();
	bool done = false;
	int frame = 0;
	// Start timer
	fps->start();

	// Begin game loop
	while(!done){
		done = update();
		draw(screen);
        if(SDL_Flip(screen) == -1){
            done = true;
        }
		// Increment frame counter
		frame ++;
		// Regulate FPS
		if(fps->getTicks() < 1000 / FRAMES_PER_SEC){
			SDL_Delay((1000/FRAMES_PER_SEC) - fps->getTicks());
		}
	}
	// Clean up
}

SDL_Surface *GameState::getScreen()
{
	return screen;
}

void GameState::setScreen(SDL_Surface *s)
{
	screen = s;
}

Timer *GameState::getFpsTimer()
{
	return fps;
}

void GameState::setFpsTimer(Timer *t)
{
	fps = t;
}
