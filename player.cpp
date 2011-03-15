#include <SDL/SDL.h>
#include "vehicle.hpp"

using namespace std;

class Player{
public:
  SDL_Surface* player;
  //  Vehicle *vehicle;
  Player();
  void handleEvent(SDL_Event *event);
};

Player::Player()
{
  player=SDL_LoadBMP("bus.bmp");
}

void Player::handleEvent(SDL_Event *event)
{
  // Check direction.
  if(event->type==SDL_KEYDOWN)
    {
      switch(event->key.keysym.sym)
	{
	case SDLK_UP:
	  break;
	case SDLK_DOWN:
	  break;
	case SDLK_LEFT:
	  break;
	case SDLK_RIGHT:break;
	}
    }

}

