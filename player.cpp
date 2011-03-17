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
 {   //trying key state so we can have multiple inputs
     Uint8* keys= SDL_GetKeyState(NULL);
     
     if(event->type == SDL_KEYDOWN){
         if(keys[SDLK_UP])
             vehicle->accelerate();
         else if(keys[SDLK_DOWN])
             vehicle->deccelerate();
         if(keys[SDLK_LEFT])
             vehicle->turnLeft();
         else if(keys[SDLK_RIGHT])
             vehicle->turnRight();
     }else{
         vehicle->setVelocity(0);
     }
     
     
 }

// Draw the player's vehicle on the screen
void Player::drawVehicle(SDL_Surface *screen)
{
    vehicle->draw(screen,vehicle->direction);
    vehicle->update();
}

Vehicle *Player::getVehicle()
{
    return vehicle;
}

