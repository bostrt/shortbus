#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <iostream>
using namespace std;
SDL_Surface* screen;
#include "walls.cpp"
int main ( int argc, char** argv )
{
    SDL_Event event;
    SDL_Surface* horiz=NULL;
    SDL_Surface* vert=NULL;
    SDL_Surface* bus = NULL;
   
   Walls wallv("vert.bmp");
   
    SDL_Init(SDL_INIT_EVERYTHING);
    bus=SDL_LoadBMP("bus.bmp");
    screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    Uint32 colorkey = SDL_MapRGB( bus->format, 0xFF, 0xFF, 0xFF );
    SDL_SetColorKey( bus, SDL_SRCCOLORKEY, colorkey );
    SDL_BlitSurface(bus,NULL,screen,NULL);
    wallv.draw(50,50,32,64);
    SDL_Flip(screen);
    bool done=false;
    while(!done)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                done=true;
            }

        }

    }

    return 0;
}
