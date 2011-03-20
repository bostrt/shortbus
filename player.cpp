#include <SDL/SDL.h>
#include <iostream>

#include "player.hpp"
#include "bus.hpp"

using namespace std;

Player::Player()
{
	pointtotal=0;
	vehicle = new Bus(400,200);
}

void Player::handleKeys(Uint8 *keys)
{
	// Handle keyboard event
	if(keys[SDLK_UP]){
		vehicle->accelerate(true);
	}else if(keys[SDLK_DOWN]){
		vehicle->reverse();
	}else if(keys[SDLK_r])
		vehicle->reset();
	else{
		vehicle->accelerate(false);
	}

	if(vehicle->getVelocity() != 0){
		if(keys[SDLK_LEFT])
			vehicle->turnLeft();
		else if(keys[SDLK_RIGHT])
			vehicle->turnRight();
	}
}

// Draw the player's vehicle on the screen
void Player::drawVehicle(SDL_Surface *screen)
{
	vehicle->draw(screen,vehicle->direction);
}

Vehicle *Player::getVehicle()
{
	return vehicle;
}

