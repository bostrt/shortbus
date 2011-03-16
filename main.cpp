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
    SDL_Surface* horiz=NULL;
    SDL_Surface* vert=NULL;
    Player *player = new Player();
    Wall wallv("vert.bmp");
    SDL_Event event;
   
    SDL_Init(SDL_INIT_EVERYTHING);
    screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
     SDL_WM_SetCaption("SHORTBUS","SHORTBUS");
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
    //Uint32 colorkey = SDL_MapRGB( bus->format, 0xFF, 0xFF, 0xFF );
    //SDL_SetColorKey( bus, SDL_SRCCOLORKEY, colorkey );
    //SDL_BlitSurface(bus,NULL,screen,NULL);
    //x,y,width,height
    wallv.draw(740,500,32,64);

    bool done=false;
    while(!done){
        // Get user input.
        while(SDL_PollEvent(&event)){
            player->handleEvent(&event);
            if(event.type==SDL_QUIT)
                {
                    done=true;
                }

        }
        SDL_Flip(screen);

    }

    return 0;
}
