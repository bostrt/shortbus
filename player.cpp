 #include <SDL/SDL.h>
 #include <iostream>
 #include "player.hpp"
 #include "vehicle.hpp"
 #include "bus.hpp"

 using namespace std;

 Player::Player()
 {
     pointtotal=0;
     vehicle = new Bus(0, 0);
 }

 void Player::handleEvent(SDL_Event *event)
 {
    //SDL_GetKeyState()
    //SDL_get key state returns an array and wer can check for boolean values(afaik)
     // Check direction.
     if(event->type==SDL_KEYDOWN){
         switch(event->key.keysym.sym)
             {
             case SDLK_UP:
                 vehicle->accelerate();
                 break;
             case SDLK_DOWN:
                 vehicle->deccelerate();
                 break;
             case SDLK_LEFT:
                 vehicle->turnLeft();
                 break;
             case SDLK_RIGHT:
                 vehicle->turnRight();
                 break;
             }
     }else{
         // Nothing is being pressed. Set velocity to zero.
         vehicle->setVelocity(0);
     }

 }

// Draw the player's vehicle on the screen
void Player::drawVehicle(SDL_Surface *screen)
{
    vehicle->draw(screen);
    vehicle->update();
}

Vehicle *Player::getVehicle()
{
    return vehicle;
}

