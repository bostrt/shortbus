#include <SDL/SDL.h>
#include "player.hpp"
#include "vehicle.hpp"
#include "bus.hpp"

using namespace std;

Player::Player()
{
    vehicle = new Bus(0, 0);
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
                case SDLK_RIGHT:
                    break;
                }
        }

}

