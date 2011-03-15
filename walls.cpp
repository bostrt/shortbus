#include <SDL/SDL.h>
#include <string>
using namespace std;
class Walls{
public:
SDL_Surface* wall;

Walls(string filename);
void draw(int xPos,int yPos,int width,int height);

};

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
