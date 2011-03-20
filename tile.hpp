#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
class Tile{
public:
Tile(SDL_Rect location,string filename);
SDL_Surface* returnSurface();
protected:
SDL_Surface* tilesurface;
};
