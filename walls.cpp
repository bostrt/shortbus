#include <SDL/SDL.h>
#include <string>
class Walls{
public:
SDL_Surface* wall;

Walls(string filename)
};

Walls::Walls(string filename)
{
wall=SDL_LoadBmp(filename);

}
