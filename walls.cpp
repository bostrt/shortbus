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
wall=SDL_LoadBMP(filename);

}
