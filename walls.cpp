#include <SDL/SDL.h>
#include <string>
using namespace std;
class Walls{
public:
SDL_Surface* wall;

Walls(string filename);
};

Walls::Walls(string filename)
{

char *cfilename;

sz = new char[filename.length() + 1];
strcpy(cfilename, filename.c_str());
wall=SDL_LoadBMP(cfilename);

}
