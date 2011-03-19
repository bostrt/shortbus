#include <SDL/SDL.h>
#include "timer.hpp"

Timer::Timer()
{
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	started = false;
	paused = false;
}

int Timer::getTicks()
{
	// If timer is running
	if(started == true)
	{
		// If timer is paused.
		if(paused == true){
			return pausedTicks;
		}else{
			// Return current time minus start time.
			return SDL_GetTicks() - startTicks;
		}
	}

	// Timer isn't running
	return 0;
}

void Timer::pause()
{
	// If timer is running and isn't already paused.
	if( started == true && paused == false ){
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	// If timer is paused
	if( paused == true )
	{
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		// Reset paused ticks
		pausedTicks = 0;
	}
}

bool Timer::isStarted()
{
	return started;
}
bool Timer::isPaused()
{
	return paused;
}
