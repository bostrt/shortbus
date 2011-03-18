 #include <SDL/SDL.h>
 #include <iostream>
 #include "player.hpp"
 #include "vehicle.hpp"
 #include "bus.hpp"

 using namespace std;
extern SDL_Surface* screen;
 Player::Player()
 {
     pointtotal=0;
     vehicle = new Bus(200,200);
 }

 void Player::handleEvent(SDL_Event *event)
 {   //trying key state so we can have multiple inputs
     Uint8* keys= SDL_GetKeyState(NULL);

     // Handle keyboard event
     if(keys[SDLK_UP]){
         vehicle->accelerate(true);
     }else if(keys[SDLK_DOWN]){
         vehicle->reverse();
     }
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
 //   vehicle->update();
}

Vehicle *Player::getVehicle()
{
    return vehicle;
}

