#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <iostream>
#include "player.hpp"
#include "wall.hpp"

using namespace std;

SDL_Surface* screen;

int main ( int argc, char** argv )
{
    // SDL_Event event;
    // SDL_Surface* bus=SDL_LoadBMP("bus.bmp");
    SDL_Surface* vert=NULL;
    Player *player = new Player();
    Wall wallv("vert.bmp");
    SDL_Event event;
    SDL_Surface* bg = SDL_LoadBMP("bg.bmp");  
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("SHOЯTBUƧ","SHOЯTBUƧ");
    // SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
    // Uint32 colorkey = SDL_MapRGB( bus->format, 0xFF, 0xFF, 0xFF );
    // SDL_SetColorKey( bus, SDL_SRCCOLORKEY, colorkey );
    //SDL_BlitSurface(bus,NULL,screen,NULL);
    //x,y,width,height
    wallv.draw(740,500,32,64);
    
    bool done=false;
    // See http://en.wikipedia.org/wiki/Game_programming#Game_structure
    while(!done){
        // Get user input.
        while(SDL_PollEvent(&event)){
            player->handleEvent(&event);
            if(event.type==SDL_QUIT){
                done=true;
            }
            //SDL_PumpEvents();
        }
        // AI
        
        // move enemies
        // collisions
        // draw graphics
        //LEAVE THIS NEXT LINE HERE
        SDL_BlitSurface(bg,NULL,screen,NULL);
        player->drawVehicle(screen);
        SDL_Flip(screen);
        // play sounds
        sleep(.2);
    }

    return 0;
}
