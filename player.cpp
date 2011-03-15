#include <SDL/SDL.h>
using namespace std;
class Player{
SDL_Surface* player;
public:
Player();
};
Player::Player()
{
player=SDL_LoadBMP("bus.bmp");
}

