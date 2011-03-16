#include <SDL/SDL.h>
#include <string>
#include "wall.hpp"

using namespace std;
extern SDL_Surface *screen;

Wall::Wall(string filename)
{

    char *cfilename;

    cfilename = new char[filename.length() + 1];
    strcpy(cfilename, filename.c_str());
    wall=SDL_LoadBMP(cfilename);
     
}
void Wall::draw(int xPos,int yPos,int width,int height)
{
    SDL_Rect dest;
    
    dest.x=xPos;
    dest.y=yPos;
    dest.w=width;
    dest.h=height;
    boundingbox=dest;
    SDL_BlitSurface(wall,NULL,screen,&dest);
}
