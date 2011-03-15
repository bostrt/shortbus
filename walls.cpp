#include <SDL/SDL.h>
#include <string>
#include "walls.hpp"

using namespace std;
extern SDL_Surface *screen;

Walls::Walls(string filename)
{

    char *cfilename;

    cfilename = new char[filename.length() + 1];
    strcpy(cfilename, filename.c_str());
    wall=SDL_LoadBMP(cfilename);

}
void Walls::draw(int xPos,int yPos,int width,int height)
{
    SDL_Rect dest;
    dest.x=xPos;
    dest.y=yPos;
    dest.w=width;
    dest.h=height;
    SDL_BlitSurface(wall,NULL,screen,&dest);
}
