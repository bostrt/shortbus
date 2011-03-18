#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <iostream>
#include "player.hpp"
#include "wall.hpp"
#include "aiopponents.hpp"
using namespace std;

SDL_Surface* screen;

int main ( int argc, char** argv )
{
    SDL_Event event;
    SDL_Surface* bg = SDL_LoadBMP("bg.bmp");  
    SDL_Surface* vert=NULL;
    Player *player = new Player();
    Wall *wallv=new Wall(300,300,"images/building_01.png");
    Wall *wallx=new Wall(100,150,"images/building_02.png");
    Wall *wally=new Wall(400,0,"images/building_03.png");
    AiOponents *granny = new AiOponents(700,65,"images/granny64.png",900);
    vector<Model *> world;
    vector<Model *>::iterator it;

    it = world.begin();
    it = world.insert(it, wallv);
    it = world.insert(it, wallx);
    it = world.insert(it, wally);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("SHOЯTBUƧ","SHOЯTBUƧ");

    bool done=false;
    // See http://en.wikipedia.org/wiki/Game_programming#Game_structure
    while(!done){
        // Get user input.
        do{
            player->handleEvent(&event);
            if(event.type==SDL_QUIT){
                done=true;
            }
            //SDL_PumpEvents();

        }while(SDL_PollEvent(&event));

        // AI
        
        // move enemies
        // collisions
        player->getVehicle()->update(world);
        // draw graphics
        //LEAVE THIS NEXT LINE HERE
        //granny->draw(screen,90);
        SDL_BlitSurface(bg,NULL,screen,NULL);
        wallv->draw(screen,0);
        wallx->draw(screen,0);
        wally->draw(screen,0);
        granny->draw(screen,90);
        player->drawVehicle(screen);
        SDL_Flip(screen);
        // play sounds
        sleep(.2);
    }

    return 0;
}
