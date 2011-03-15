#include <SDL/SDL.h>
using namespace std;
class Player{
SDL_Surface* player;
public:
//using ints for now maybe a double direction
int xPos,yPos,velocity,direction;
Player();
void handleEvent();
};
Player::Player()
{
player=SDL_LoadBMP("bus.bmp");
}
void Player::handleEvent()
{
if(event.type==SDL_KEYDOWN)
{
switch(event.key.keysym.sym)
{
case SDLK_UP:break;
case SDLK_DOWN:break;
case SDLK_LEFT:break;
case SDLK_RIGHT:break;
}
}

}

